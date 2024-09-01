// 이제 본격적으로 다이렉트 X 함수를 취하겠다.
// 윈도즈용은 처음이기 때문에 상당히 긴장된다.
// 이 엘아에치 윈도즈 라이브러리는 계속 업그레이드 될것이다 1998. 9. 15
// 이 엘아에치 윈도즈 라이브러리는 320 * 240 * 256 전용이다. !!!

#include <WINDOWS.H>
#include <WINDOWSX.H>
#include <STDIO.H>
#include <CONIO.H>
#include <DDRAW.H>
#include <DSOUND.H>
#include <TIME.H>
#include <NEW.H>
#include "DDUTIL.CPP"
#include "SOUND.CPP"

#define SWAP(a,b)		{a^=b;b^=a;a^=b;}
#define randomize()		srand(time(NULL))
#define random(i)		(rand()%i)

#define TITLE       "에러 !!!"

void start( void );
void end( void );
long FAR PASCAL WindowProc( HWND hWnd, UINT message, 
						    WPARAM wParam, LPARAM lParam );
HWND    hwnd;  //여기서부터 다이렉트 X 기본 설정 부분인거 같다

LPDIRECTDRAW            lpDD;    //다이렉트 X의 기본 포인트
LPDIRECTDRAWSURFACE     page0;   // 도스에서의 보이는 기본 페이지
//LPDIRECTDRAWCLIPPER     lpClipper;     //클리핑에 관련 된거 같은데
LPDIRECTDRAWPALETTE     lpDDPal;       //요건 팔레트 처리

CDXSound *Sound;
CDXSoundBuffer *Eff[50];

char *page[15];
typedef unsigned char byte;
unsigned char palette[768];

//PCX 화일 헤더부분
struct pcx_header
{
       char   header;			
       char   version;
       char   encode;
       char   bitperpixel;
       short  x1,y1,x2,y2;
       short  hres,vres;
       char   palette[48];
       char   mode;
       char   nplanes;
       short  byteperline;
       short  palletteinfo;
       short  scanerhres,scanervres;
       char   temp[54];
} header;

const byte table[3][32]=
	  {{  0, 0, 1, 2, 3, 4, 5, 6,
		  7, 8, 9,10,11,12,13,14,
		 15,16,17,18,19, 0, 0, 0,
		  0, 0, 0, 0, 0, 0, 0, 0 },

	   {  0, 0, 0, 1, 2, 3, 4, 5,
		  0, 0, 6, 7, 8, 9,10,11,
		  0, 0,12,13,14,15,16,17,
		  0, 0,18,19,20,21, 0, 0 },

	   {  0, 0, 1, 2, 3, 4, 5, 6,
		  7, 8, 9,10,11,12,13,14,
		 15,16, 0,17,18,19,20,21,
		 22,23,24,25,26,27, 0, 0 }};

const byte fsttable[2][20]=
	{   { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		  1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },

		{ 0, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		  3, 3, 3, 3, 3, 3, 2, 3, 3, 3 }  };

const byte midtable[3][22]=
	{   { 0, 0, 2, 0, 2, 1, 2, 1, 2, 3, 0,
		  2, 1, 3, 3, 1, 2, 1, 3, 3, 1, 1 },

		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3,
		  3, 3, 1, 2, 4, 4, 4, 2, 1, 3, 0 },

		{ 0, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7,
		  7, 7, 6, 6, 7, 7, 7, 6, 6, 7, 5 }   };

byte HF1[8][20][8];
byte HF2[4][22][8];
byte HF3[4][28][8];

byte EF[256][8];

byte gul_bitmap[8];

void page_on( void )
{
	_set_new_mode( 1 );
	int i;
	for ( i = 1; i < 15; i++ ) page[i] = (char *)malloc( 192000 ), memset( page[i], 0, 192000 );
}

void page_off( void )
{
	int i;
	for ( i = 1; i < 15; i++ ) free( page[i] );
}

//프로그램 종료시 메모리 해제..
static void END( void )
{
	int i;

	if( lpDD != NULL )
	{
        if( page0 != NULL )      //기초 표면 해제
		{
            page0->Release();
            page0 = NULL;
		}
		if( lpDDPal != NULL )			//다이렉트 팔레트 해제
		{
			lpDDPal->Release();
			lpDDPal = NULL;
		}

		lpDD->Release();
		lpDD = NULL;
	}
}

//다이렉트 X 의 로드 팔레트
IDirectDrawPalette * Load_Palette(IDirectDraw *pdd, LPCSTR strFilename)
{
    IDirectDrawPalette* ddpal;
    int                 i;
    PALETTEENTRY        ape[256];
    struct 
	{
		BYTE Red;
		BYTE Green;
		BYTE Blue;
    } rgb[256];

	FILE* fp;
	char temp[256];

    //pcx화일 오픈
	fp = fopen( (LPSTR)strFilename, "rb" );
	if( fp==NULL )
	{
		wsprintf( temp, "%s 파일이 없습니다.", strFilename );
		MessageBox( hwnd, temp, TITLE, MB_OK );
		return NULL;
	}

	//팔레트 부분만 로딩
    fseek( fp, -768, SEEK_END );        
    fread( rgb, 768, 1, fp);           
	fclose( fp );

	for(i=0; i<256; i++ )
    {
		ape[i].peFlags = PC_NOCOLLAPSE | PC_RESERVED;	//다이렉트 드로우 도큐먼크를 참조하세요.
														//팔레트 애니메이션 가능케하고 사용자가 세팅한 색임을 알려
		ape[i].peRed   = rgb[i].Red;
        ape[i].peGreen = rgb[i].Green;
        ape[i].peBlue  = rgb[i].Blue;
    }

	//다이렉트 팔레트 생성
    pdd->CreatePalette(DDPCAPS_8BIT, ape, &ddpal, NULL);

    return ddpal;
}

void set_palette( unsigned char *data )
{
	int i;

	outp( 0x3C8, 0 );

	for (i = 0; i < 768; i += 3 )
	{
		outp( 0x3C9, data[i  ] );
		outp( 0x3C9, data[i+1] );
		outp( 0x3C9, data[i+2] );
	}
}

//초기화가 실패했을 때라는군...
BOOL initFail( HWND hwnd )
{
    END();
	MessageBox( hwnd, "DirectDraw Init FAILED", TITLE, MB_OK );
	DestroyWindow( hwnd );
	return FALSE;
}

//PCX 로딩 보이는 페이지 빼고 가상페이지에만 로딩 
//윈도우즈 특성상 어쩔수 없음도 있고 내가 처리하기 귀찮음 !!!
void read_pcx( char *name, int num )
{
	FILE *fp;
	int i, x = 0, y = 0, mx, my;
	unsigned char ch, data;
	
    if ( (fp = fopen( name, "rb" )) != NULL )
    {
        fread( &header, sizeof(header), 1, fp );

        fseek( fp, -768, SEEK_END );
        fread( palette, 768, 1, fp );
		//for ( i = 0; i < 768; i++ ) palette[i] >>= 2;
		//set_palette( palette );

        fseek( fp, sizeof(header), SEEK_SET );
        mx = header.x2;
        if ( mx > 399 ) mx = 400;
        my = header.y2;
        if ( my > 299 ) my = 300;
        while(1)
        {
            ch = fgetc( fp );

            if ( (ch & 0xC0) == 0xC0 )
            {
                data = getc( fp );
                for ( i = 0; i < (ch & 0x3F); i++ )
				page[num][ (y * 640) + x++ ] = data;
            }
            else page[num][ (y * 640) + x++ ] = ch;

            if ( x > mx ) { x = 0; y += 1; }
            if ( y > my ) break;
        }
    }
	fclose( fp );
}

void fade_run( int p )
{
	int i;
	unsigned char r, g, b;

	outp( 0x03C8, 0 );

	for ( i = 0; i < 768; i += 3 )
	{
		 r = (palette[i  ] * p)/100; outp( 0x03C9, r );
		 g = (palette[i+1] * p)/100; outp( 0x03C9, g );
		 b = (palette[i+2] * p)/100; outp( 0x03C9, b );
	}
}

//다이렉트 X 의 점찍기
void put_pixel( int x, int y, BYTE color, int pg )
{
	if ( x > 399 || x < 0 || y > 299 || y < 0 ) return;
	else
	{
		switch( pg )
		{
			default: 
				page[pg][(y * 640) + x] = color;
			break;
			case 0:
				DDSURFACEDESC ddsd;
				ddsd.dwSize=sizeof(ddsd);

				page0->Lock(NULL,&ddsd,0,NULL);
				char *p = (char *)(ddsd.lpSurface);
				p[640* y + x] = color;
	
				page0->Unlock(NULL);
			break;
		}
	}
}

//다이렉트 X 의 가로선 긋기
void HLine( int s_x, int s_y, int e_x, BYTE color )
{
	int x = 0;
	for( x = s_x; x <= e_x; x++ )
        put_pixel( x, s_y, color, 1 );
}

//다이렉트 X 의 세로선 긋기
void VLine( int s_x, int s_y, int e_y, BYTE color )
{
	int y = 0;
	for( y = s_y; y <= e_y; y++ )
        put_pixel( s_x, y, color, 1 );
}

void draw_box( int s_x, int s_y, int e_x, int e_y, BYTE color )
{
	if(s_x < e_x && s_y < e_y)
	{
		HLine(s_x,s_y,e_x,color);
		HLine(s_x,e_y,e_x,color);
		VLine(s_x,s_y,e_y,color);
		VLine(e_x,s_y,e_y,color);
	}
}

void box_fill( int s_x, int s_y, int e_x, int e_y, BYTE color )
{
	int iiii;

	if(s_x < e_x && s_y < e_y)
	{
		for ( iiii = s_y; iiii <= e_y; iiii++ )
		{
			HLine(s_x,iiii,e_x,color );
		}
	}
}

void copy_page( int sourscrn, int tarscrn )
{
	switch( tarscrn )
	{
		default: 
			memmove( page[tarscrn], page[sourscrn], (size_t)192000L );
		break;
		case 0:
			DDSURFACEDESC ddsd;
			ddsd.dwSize=sizeof(ddsd);
			page0->Lock(NULL,&ddsd,0,NULL);
			char *p = (char *)(ddsd.lpSurface);
			memmove( p, page[sourscrn], 192000 );
			page0->Unlock(NULL);
		break;
	}
}

void clear_page( int p )
{
	switch( p )
	{
		default: memset( (char *)page[p], 0, 192000 ); break;
		case 0:
			DDSURFACEDESC ddsd;
			ddsd.dwSize=sizeof(ddsd);
			page0->Lock(NULL,&ddsd,0,NULL);
			char *p = (char *)(ddsd.lpSurface);
			memset( (char *)p, 0, 192000 );
			page0->Unlock(NULL);
		break;
	}
}

void put_sprite( int x1, int y1, int x2, int y2, char *p, int d )
{
    int x, y, t = 0;

    switch( d )
    {
        case 1:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = x1; x <= (x1+x2-1); x++, t++ )
            {
				if ( x > 399 || x < 0 || y > 299 || y < 0 ) continue;
				if ( p[t] != (char)255 ) page[1][ (y * 640) + x ] = p[t];
            }
        break;
        case 2:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = (x1+x2-1); x >= x1; x--, t++ )
            {
                if ( x > 399 || x < 0 || y > 299 || y < 0 ) continue;
                if ( p[t] != (char)255 ) page[1][ (y * 640) + x ] = p[t];
            }
        break;
    }
}

void put_white( int x1, int y1, int x2, int y2, char *p, int d )
{
    int x, y, t = 0;

    switch( d )
    {
        case 1:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = x1; x <= (x1+x2-1); x++, t++ )
            {
				if ( x > 399 || x < 0 || y > 299 || y < 0 ) continue;
				if ( p[t] != (char)255 ) page[1][ (y * 640) + x ] = (char)255;
            }
        break;
        case 2:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = (x1+x2-1); x >= x1; x--, t++ )
            {
                if ( x > 399 || x < 0 || y > 299 || y < 0 ) continue;
                if ( p[t] != (char)255 ) page[1][ (y * 640) + x ] = (char)255;
            }
        break;
    }
}

void copy_image( int src, int x1, int y1, int x2, int y2, int des, int x3, int y3 )
{
    int I;

    if ( x1 > x2 ) SWAP( x1, x2 );
    if ( y1 > y2 ) SWAP( y1, y2 );

	switch( des )
	{
		default: 
		    for( I = 0; I < ( y2 - y1 + 1 ); I++ )
				memcpy( page[des] + x3 + (y3 + I) * 640, page[src] + x1 + (y1 + I) * 640, (size_t)(x2 - x1 + 1) ); break;
		case 0:
			DDSURFACEDESC ddsd;
			ddsd.dwSize=sizeof(ddsd);
			page0->Lock(NULL,&ddsd,0,NULL);
			char *p = (char *)(ddsd.lpSurface);
		    for( I = 0; I < ( y2 - y1 + 1 ); I++ )
				memcpy( p + x3 + (y3 + I) * 640, page[src] + x1 + (y1 + I) * 640, (size_t)(x2 - x1 + 1) ); 
			page0->Unlock(NULL);
		break;
	}
}

void copy_image2( int src, int x1, int y1, int x2, int y2, int des, int x3, int y3 )
{
    int I ,j;

    if ( x1 > x2 ) SWAP( x1, x2 );
    if ( y1 > y2 ) SWAP( y1, y2 );

	switch( des )
	{
		default: 
		    for( j = y1; j < y2 + 1 ; j++ )
			{
				for( I = x1; I < x2 + 1 ;I++ )
				{	
					if( *(page[src] + I + j * 640) != 255 )  *(page[des]+(x3+ I-x1 )+(y3+ j-y1 )*640)=*(page[src]+I+j*640); 
				}
			}
		break;
		case 0:
			DDSURFACEDESC ddsd;
			ddsd.dwSize=sizeof(ddsd);
			page0->Lock(NULL,&ddsd,0,NULL);
			char *p = (char *)(ddsd.lpSurface);
		    for( j = y1; j < y2 + 1 ; j++ )
			{
				for( I = x1; I < x2 + 1 ;I++ )
				{
					if( *(page[src] + I + j * 640) != 255 )  *(p+(x3+ I-x1 )+(y3+ j-y1 )*640)=*(page[src]+I+j*640); 
				}
			}
			page0->Unlock(NULL);
		break;
    }
}

static void FRAME2( int mSec )
{
    long     tick;

    tick = (32768 * (long)mSec) / 1000;         
    for (; tick > 0; tick--)
    {
        while(inp(0x61) & 0x10);
        while(!(inp(0x61) & 0x10));
    }
}

void read_font( void )
{
    FILE *fp;

    if ( (fp = fopen("LYHHAN.FNT", "rb") ) == NULL )
    {
        fclose(fp);
        return;
    }

    fread(HF1, 1280, 1, fp);
    fread(HF2, 704, 1, fp);
    fread(HF3, 896, 1, fp);
    fclose(fp);

    if( (fp = fopen("LYHENG.FNT", "rb") ) == NULL)
    {
        fclose(fp);
        return;
    }
    fread(EF, 2048, 1, fp);
    fclose(fp);
}

void or_img( byte *src, byte *dest)
{
    int I;

    for ( I = 0; I < 8; I++ ) dest[I] |= src[I];
}

void put_font( int x, int y, byte *fnt, int color, int p )
{
    int I, k, m = 0, n = 0;
    unsigned char dat = 0x80;

    for ( I = 0; I < 8; I++ )
    for ( k = 0; k < 8; k++ )
    {
        if ( y < 0 || y + I > 299 ) continue;
        if ((fnt[m] & (dat >> n)) == (dat >> n)) put_pixel( x + k, y + I, color, p );
        if ( (++n) == 8 ) { n = 0; m += 1; }
    }
}

void gul( int x, int y, char *s, int color, int page )
{
    byte data1, data2;
    byte first, mid, last;
    int I, b1, b2, b3;

    for ( I = 0; I < (int)strlen(s); I++ )
    {
        data1 = *( s + I );

        memset( gul_bitmap, 0, 8 );

        if ( data1 > 127 )
        {
            data2 = *( s + (++I) );

            first = ( data1 & 124 ) >> 2;
            mid   = ( data1 & 3   ) * 8 + (data2 >> 5);
            last  = ( data2 & 31  );

            first = table[0][first];
            mid   = table[1][mid];
            last  = table[2][last];

            b3    = midtable[0][mid];

            if (!last)
            {
                b2 = fsttable[0][first];
                b1 = midtable[1][mid];
            }
            else
            {
                b2 = fsttable[1][first];
                b1 = midtable[2][mid];
            }
            if (first) or_img(HF1[b1][first], gul_bitmap );
            if (mid  ) or_img(HF2[b2][mid  ], gul_bitmap );
            if (last ) or_img(HF3[b3][last ], gul_bitmap );

            put_font( x, y, gul_bitmap, color, page );
            put_font( x, y, gul_bitmap, color, page );
            x += 9;
        }
        else
        {
            memmove( &gul_bitmap, &EF[ data1 ], 8 );
            put_font( x, y, gul_bitmap, color, page );
            put_font( x, y, gul_bitmap, color, page );
            x += 9;
        }
    }
}

void lyh_gul( int x, int y, int jaju, int p )
{
    char a[10];

    itoa( jaju, a, 10 );
    gul( x, y, a, 255, p );
}

//윈도의 생성과 다이렉트 X 의 초기화라는데....
static BOOL InitGrp( HINSTANCE hInstance, int nCmdShow )
{
	HWND			hwnd;
	WNDCLASS		wc;
	DDSURFACEDESC	ddsd;
	DDSCAPS			ddscaps;
	HRESULT			ddrval;

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground = NULL;
    wc.lpszMenuName = "이용한";
    wc.lpszClassName = "이용한";
    RegisterClass( &wc );

    hwnd = CreateWindowEx(
        0,
        "이용한",
        "이용한",
        WS_POPUP,
        0,
        0,
        GetSystemMetrics( SM_CXSCREEN ),
        GetSystemMetrics( SM_CYSCREEN ),
        NULL,
        NULL,
        hInstance,
        NULL );

    if( !hwnd )
    {
		return FALSE;
    }
	ShowWindow ( hwnd, nCmdShow );
	UpdateWindow ( hwnd );

	//다이렉트 드로우 오브젝트 생성
	ddrval = DirectDrawCreate( NULL, &lpDD, NULL );
	if( ddrval != DD_OK )
	{
		return initFail( hwnd );
	}
	
	//협력 레벨 설정
	ddrval = lpDD->SetCooperativeLevel( hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN );
	if( ddrval != DD_OK )
	{
		return initFail( hwnd );
	}

	ddrval = lpDD->SetDisplayMode(400,300,8);
    if(ddrval != DD_OK)
    {
		return initFail( hwnd );
    }
	
	//기초 표면 생성
	ZeroMemory(&ddsd, sizeof(ddsd));
	ddsd.dwSize = sizeof(ddsd);
	ddsd.dwFlags = DDSD_CAPS;
	
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    ddrval = lpDD->CreateSurface(&ddsd,&page0, NULL);
    
    /*if( ddrval != DD_OK )
	{
		return initFail( hwnd );
	}*/

    /*
	//클리퍼 오브젝트 생성, 클리핑 영역 세팅
	ddrval = lpDD->CreateClipper( 0, &lpClipper, NULL );
	if( ddrval != DD_OK )
	{
		return initFail( hwnd );
	}

	ddrval = lpClipper->SetHWnd( 0, hwnd );
	if( ddrval != DD_OK )
	{
		return initFail ( hwnd );
	}

    ddrval = page0->SetClipper( lpClipper );
	if( ddrval != DD_OK )
	{
		return initFail( hwnd );
	}
	*/
	lpDDPal = Load_Palette( lpDD, ".\\ARG\\LYHWIN.PAL" );
	if( lpDDPal ) page0->SetPalette( lpDDPal );

	return TRUE;
}

void start( void )
{
	page_on();
	ShowCursor(FALSE);
	randomize();
	Sound = new CDXSound;
	Sound->Create( hwnd );
}

void end( void )
{
	page_off();
	ShowCursor(TRUE);
	delete Sound;
}
