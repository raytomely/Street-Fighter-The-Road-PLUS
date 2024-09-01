//µÕÅ± ³¡¶w Arix œa·¡§aœáŸ¡ Ver 1.0
//·¡ˆõ·e ”a¯¡  e—e µÕÅ±¶w·¡”a. ‹a ·¡·A“e ˆa ¯¥Àå»¡· ´á“a ·AË©¤wµA¬á
//ÐaaŸi ”a¶… ¤h´v“e•A(¸i¬—ˆb´eq) ¯©Ð—¯¡Ç¡‰¡ a“¡Œa Ða—aˆa É·¼¡ i´aˆa¤áv”a
//´á“a X¸a¯¢·¡ ·¡ ˜a¶á Ïa¡‹aœ‘·i  b µ©v“e»¡ ¡¡Ÿa»¡ e ‹a Ðe¬aœq ˜¢…µA
// g·e ¬aœq—i·¡(aŸi Í¡Ðq) Ï¡ÐŸi ”wÐ–”a‰¡ ¬—ˆbÐa“¡  i•¡ ´eaµ© ¸÷•¡¡ ÑÁˆae”a
//‹a ¸a¯¢·e ´a a ¹A¡w”¡ ¡µº‚‰¡ Ða“e·© a”a Íˆa w¯¥Ða‹© ˆe¸éÓ¡ §¥”a
//‹a X¸a¯¢ ˜¢…µA a· ‹a•·´e· ¸aža“e Ðe®…ˆe i´aˆa‰¡ ÐeÀq  e—i‰¡ ·¶”å
//¯aÑÁ ”á¡—a 2“e Óe¸â•¡ ´ô·¡ ¬aœa¹v”a. ¸÷ i ¶¥É·Ða‰¡ ¦…Ða”a.
//·¡‹i·i ¥¡¯¡¡e ¸é” ¯¥Àå»¡· ´á“a ·AË©¤w·i ¹¡¯±Ða¯¡‹¡ ¤aœs“¡”a
//¯¥Àå»¡µA“e £¡´eÐa»¡ e aˆ{·e Ï¡Ð¸aˆa ™¡ ´eaÈaa‹© §©¡a ·¡ ‹i·i ³e”a.
//Àq‰¡¡ ·¡ œa·¡§aœáŸ¡“e ˆa ¯©b·¡ ´e–A¬á q· ˆõ·i ˆá· ‹a”¡ µ«‰a¬á
//¬a¶wÐ–·a“¡ ´·ÐÐ º¯¡‹¡ ¤aœs“¡”a
//                    1998. 6. 10µA ³e u·a¡ ”a¯¡ œa·¡§aœáŸ¡ ŠÂ‚

#include <stdio.h>
#include <string.h>
//#include <dos.h>
#include <stdlib.h>
//#include <iostream>
#include <conio.h>
//#include <math.h>
#include <time.h>
//#include <mem.h>
//#include <i86.h>
//#include <io.h>

#include "extern.h"
#include "sfroad_sdl.h"

#define SWAP(a,b)  {a^=b;b^=a;a^=b;}
#define randomize() srand(time(NULL))
#define random(i) (rand()%i)
#define COPY(A,B) for(loop=0;loop<32;loop++) *(B+loop)=*(A+loop);
#define OR(A,B) for(loop=0;loop<32;loop++) *(B+loop)|=*(A+loop);

unsigned char press_key = 0;
char *page[10];
unsigned char palette[768];
typedef unsigned char byte;

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

byte gul_bitmap[8];    //‹i© 1

void VGAmode( void )
{
    union REGS regs;
    regs.h.al = 0x13;
    regs.h.ah = 0x00;
    int386( 0x10, &regs, &regs );
}

void TEXTmode( void )
{
    union REGS regs;
    regs.h.al = 0x03;
    regs.h.ah = 0x00;
    int386( 0x10, &regs, &regs );
}

void page_on( void )
{
    int i;

    //page[0] = (char *)0xA0000l;

    for ( i = 1; i < 10; i++ ) page[i] = (char *)malloc( 97200 );
}

void page_off( void )
{
    int i;

    for ( i = 1; i < 10; i++ ) free( page[i] );
}

void put_pixel( int x, int y, char c, int p )
{
    if ( x > 359 || x < 0 || y > 269 || y < 0 ) return;
    else page[p][ ( y * 360 ) + x ] = c;
}

void line_X( int xl, int xh, int y, char col, int p )
{
    //int temp;

    if ( xl > xh ) SWAP( xl, xh );

    memset( page[p]+xl+360*y, col, (xh-xl)+1 );
}

void line_Y( int x, int yl, int yh, char col, int p )
{
    int i; //,temp;

    if ( yl > yh ) SWAP( yl, yh );

    for( i = 0; i < (yh - yl + 1); i++ )
    {
        *(page[p] + x + (i + yl) * 360 ) = col;
    }
}

void draw_box( int x1, int y1, int x2, int y2, char col, int p )
{
    if ( x1 > x2 ) SWAP( x1, x2 );
    if ( y1 > y2 ) SWAP( y1, y2 );

    line_X( x1, x2, y1, col, p );
    line_X( x1, x2, y2, col, p );

    line_Y( x1, y1+1, y2-1, col, p );
    line_Y( x2, y1+1, y2-1, col, p );
}

void box_fill( int s_x, int s_y, int e_x, int e_y, char color, int pa )
{
    int iiii;

    if (s_x < e_x && s_y < e_y)
    {
        for ( iiii = s_y; iiii <= e_y; iiii++ )
        {
            line_X(s_x,e_x,iiii,color, pa );
        }
    }
}

void put_sprite( int x1, int y1, int x2, int y2, char *p, int d )
{
    int x, y, t = 0;

    switch( d )
    {
        case 1:
            for ( y = y1; y <= (y1+y2-1); y++ )
            {
                for ( x = x1; x <= (x1+x2-1); x++, t++ )
                {
                    if ( x > 359 || x < 0 || y > 269 || y < 0 ) continue;
                    if ( p[t] != (char)255 ) page[1][ (y * 360) + x ] = p[t];
                }
            }
        break;
        case 2:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = (x1+x2-1); x >= x1; x--, t++ )
            {
                if ( x > 359 || x < 0 || y > 269 || y < 0 ) continue;
                if ( p[t] != (char)255 ) page[1][ (y * 360) + x ] = p[t];
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
            {
                for ( x = x1; x <= (x1+x2-1); x++, t++ )
                {
                    if ( x > 399 || x < 0 || y > 269 || y < 0 ) continue;
                    if ( p[t] != (char)255 ) page[1][ (y * 360) + x ] = 255;
                }
            }
        break;
        case 2:
            for ( y = y1; y <= (y1+y2-1); y++ )
            for ( x = (x1+x2-1); x >= x1; x--, t++ )
            {
                if ( x > 399 || x < 0 || y > 269 || y < 0 ) continue;
                if ( p[t] != (char)255 ) page[1][ (y * 360) + x ] = 255;
            }
        break;
    }
}

void clear_page( int p )
{
    memset( (char *)page[p], 0, 97200 );
}

void copy_page( char *souscrn, char *tarscrn )
{
    memmove( tarscrn, souscrn, (size_t)97200L );
}

void copy_image( char *src, int x1, int y1, int x2, int y2, char *des, int x3, int y3 )
{
    int I;

    if ( x1 > x2 ) SWAP( x1, x2 );
    if ( y1 > y2 ) SWAP( y1, y2 );

    for( I = 0; I < ( y2 - y1 + 1 ); I++ )
    memcpy( des + x3 + (y3 + I) * 360, src + x1 + (y1 + I) * 360, (size_t)(x2 - x1 + 1) );
}

void copy_image2( char *src, int x1, int y1, int x2, int y2, char *des, int x3, int y3 )
{
    int I ,j;

    if ( x1 > x2 ) SWAP( x1, x2 );
    if ( y1 > y2 ) SWAP( y1, y2 );

    for( j = y1; j < y2 + 1 ; j++ )
    {
        for( I = x1; I < x2 + 1 ;I++ )
        {
            if( *(src + I + j * 360) != 255 )  *(des+(x3+ I-x1 )+(y3+ j-y1 )*360)=*(src+I+j*360);
        }
    }
}

void put_zoom( int x1, int y1, int x2, int y2, char *srcscrn, int xx1, int yy1, int xx2, int yy2, char *desscrn )
{
    if( x1 > x2 ) SWAP( x1, x2 );
    if( y1 > y2 ) SWAP( y1, y2 );
    if( xx1 > xx2 ) SWAP( xx1, xx2 );
    if( yy1 > yy2 ) SWAP( yy1, yy2 );

    int dx = x2 - x1, dxx = xx2 - xx1, tempx;
    int dy = y2 - y1, dyy = yy2 - yy1, tempy;

    int ix,jx,iy,jy;//,x,y;

    if( dx >= 0 && dxx >= 0 && dy >= 0 && dyy >= 0 )
    {
        jx = 0;
        tempx = dxx;

        for( ix = 0; ix <= dxx; ix++ )
        {
            while( tempx < 0 )
            {
                tempx += dxx;
                jx++;
            }
            jy = 0;
            tempy = dyy;

            for( iy = 0; iy <= dyy; iy++ )
            {
                while( tempy < 0 )
                {
                    tempy += dyy;
                    jy++;
                }
                *(desscrn+ix+xx1+(iy+yy1)*320) = *(srcscrn+jx+x1+(jy+y1)*320);
                tempy -= dy;
            }
            tempx-=dx;
        }
    }
}

struct pcx_header2
{
    char maker;
    char ver;
    char code;
    char bit;
    int x1, y1, x2, y2, mx, my;
    char palette[48], mode, plane;
    int nubi, info, hres, vres;
    char extra[54];
} HEAD;

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

void set_palette( unsigned char *data )
{
    int i;

    outp( 0x3C8, 0 );

    for ( i = 0; i < 768; i += 3 )
    {
        outp( 0x3C9, data[i  ] );
        outp( 0x3C9, data[i+1] );
        outp( 0x3C9, data[i+2] );
    }
}

void load_palette( char *name )
{
    FILE *fp;
    int i;

    fp = fopen( name, "rb" );
    fread( &HEAD, 128, 1, fp );

    fseek( fp, -768, SEEK_END );
    fread( palette, 768, 1, fp );
    for ( i = 0; i < 768; i++ ) palette[i] >>= 2;
    set_palette( palette );
    fclose( fp );
}

void read_pcx( const char *name, int num )
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
        setSFroadPalette();
        fseek( fp, sizeof(header), SEEK_SET );
        mx = header.x2;
        if ( mx > 359 ) mx = 360;
        my = header.y2;
        if ( my > 269 ) my = 270;
        while(1)
        {
            ch = fgetc( fp );

            if ( (ch & 0xC0) == 0xC0 )
            {
                data = getc( fp );
                for ( i = 0; i < (ch & 0x3F); i++ )
                page[num][ (y * 360) + x++ ] = data;
            }
            else page[num][ (y * 360) + x++ ] = ch;

            if ( x > mx ) { x = 0; y += 1; }
            if ( y > my ) break;
        }
    }
    fclose( fp );
}

void fade_run( int p )
{
    /*int i;
    unsigned char r, g, b;

    outp( 0x03C8, 0 );

    for ( i = 0; i < 768; i += 3 )
    {
        r = (palette[i  ] * p)/100; outp( 0x03C9, r );
        g = (palette[i+1] * p)/100; outp( 0x03C9, g );
        b = (palette[i+2] * p)/100; outp( 0x03C9, b );
    }*/
    setBrightness(p);
    SDL_SetPalette(screen, SDL_LOGPAL|SDL_PHYSPAL, SFroadFadePalette, 0, 256);
}

void FRAME( int mSec )
{
    //long     tick;

    //tick = (32768 * (long)mSec) / 1000;          // Á¡”e¶áŸi Ìé¯a ”e¶á¡ ¤aŽ…”a.
    //
    // |-| |-| |-| |-| |-| |-| |-| |-| |   <- 61h ¤å»¡ §¡Ëa 4
    // | |_| |_| |_| |_| |_| |_| |_| |_|
    //          Ðeº‹¡ 32Khz
    //
    delay(mSec);
    /*for (; tick > 0; tick--)
    {
        while(inp(0x61) & 0x10);
        while(!(inp(0x61) & 0x10));
    }*/
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
        if ( y < 0 || y + I > 269 ) continue;
        if ((fnt[m] & (dat >> n)) == (dat >> n)) put_pixel( x + k, y + I, color, p );
        if ( (++n) == 8 ) { n = 0; m += 1; }
    }
}

void gul( int x, int y, const char *s, int color, int page )
{
    byte data1, data2;
    byte first, mid, last;
    unsigned int I, b1, b2, b3;

    for ( I = 0; I < strlen(s); I++ )
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

// º¶aÇ¡
#define _ESC       0x01
#define _UPKEY     0x48
#define _DNKEY     0x50
#define _LTKEY     0x4b
#define _RTKEY     0x4d
#define _TAB       0x0f
#define __SPACE     0x39
#define _BACKSPACE 0x0e
#define _ALT       0x38
#define _CTRL      0x1d
#define _ENTER     0x1c
#define _INS       0x52
#define _DEL       0x53
#define _HOME      0x47
#define _END       0x4f
#define _PGUP      0x49
#define _PGDN      0x51
#define _LSHIFT    0x2a
#define _RSHIFT    0x36

// Ðq® Ç¡
#define _F1        0x3b
#define _F2        0x3c
#define _F3        0x3d
#define _F4        0x3e
#define _F5        0x3f
#define _F6        0x40
#define _F7        0x41
#define _F8        0x42
#define _F9        0x43
#define _F10       0x44
#define _F11       0x85
#define _F12       0x86

// ®•¸aÇ¡
#define _N1        0x02
#define _N2        0x03
#define _N3        0x04
#define _N4        0x05
#define _N5        0x06
#define _N6        0x07
#define _N7        0x08
#define _N8        0x09
#define _N9        0x0a
#define _N0        0x0b

// Shift + Ðq®Ç¡
#define _SF1       0x54
#define _SF2       0x55
#define _SF3       0x56
#define _SF4       0x57
#define _SF5       0x58
#define _SF6       0x59
#define _SF7       0x5a
#define _SF8       0x5b
#define _SF9       0x5c
#define _SF10      0x5d
#define _SF11      0x89
#define _SF12      0x8a

// Alt + Ðq®Ç¡
#define _AF1       0x68
#define _AF2       0x69
#define _AF3       0x6a
#define _AF4       0x6b
#define _AF5       0x6c
#define _AF6       0x6d
#define _AF7       0x6e
#define _AF8       0x6f
#define _AF9       0x70
#define _AF10      0x71
#define _AF11      0x8b
#define _AF12      0x8c

// Ctrl + Ðq®Ç¡
#define _CF1       0x5e
#define _CF2       0x5f
#define _CF3       0x60
#define _CF4       0x61
#define _CF5       0x62
#define _CF6       0x63
#define _CF7       0x64
#define _CF8       0x65
#define _CF9       0x66
#define _CF10      0x67
#define _CF11      0x87
#define _CF12      0x88

// ´iÌa¥U Ç¡
#define _A         0x1e
#define _B         0x30
#define _C         0x2e
#define _D         0x20
#define _E         0x12
#define _F         0x21
#define _G         0x22
#define _H         0x23
#define _I         0x17
#define _J         0x24
#define _K         0x25
#define _L         0x26
#define _M         0x32
#define _N         0x31
#define _O         0x18
#define _P         0x19
#define _Q         0x10
#define _R         0x13
#define _S         0x1f
#define _T         0x14
#define _U         0x16
#define _V         0x2f
#define _W         0x11
#define _X         0x2d
#define _Y         0x15
#define _Z         0x2c

static void (__interrupt __far *old_int09)();
void __interrupt __far new_int09();
void init_key(void);
void del_key(void);

unsigned char scan[128], asci[128];

// Keyboard interrupt....
void init_key(void)
{
    memset(scan, 0, 128);
    memset(asci, 0, 128);

    old_int09 = _dos_getvect(0x09);
    _dos_setvect(0x09,new_int09);
}

void del_key(void)
{
    _dos_setvect(0x09,old_int09);
}

void __interrupt __far new_int09()
{
    unsigned char port, code;

    //_disable();

    port = read_keyboard(); //inp(0x60);
    code = port & 127;

    if ((port < 128) && (scan[code] == 0)) {
           scan[code] = 1;
           asci[code] = 1;
           press_key = code;
    }
    else if(port > 127)     scan[code] = 0;

    //outp(0x20, 0x20);

    //_enable();
}
// Keyboard interrupt End

