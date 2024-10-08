#include "value.h"
#include "extern.h"
#include "midi.h"
#include "modex.h"
#include "sfroad_sdl.h"

void start( void )
{
    if ( MODDetectCard( &Port, &IRQ, &DRQ ) )
    {
        printf( "Sound Blaster not Found.\n" ); getch();
        SOUND = 0;
    } else SOUND = 1, MODPlayModule( Mus, 8, 8000, Port, IRQ, DRQ, PM_TIMER );
    playMidiLoopCounter = 20; /* �������� �e�� �e�� ���� */
    ret = initMPU401( 0x330 );
    SOUND2 = 1;
    if ( ret != 0 )
    {
        ret = initMPU401( 0x320 );
        if ( ret != 0 )
        {
            printf("MIDI Device not found!.\n"); getch();
            SOUND2 = 0;
        }
    }
    init_key();
    read_font();
    set360x270x256_X();
    //VGAmode();
    page_on();
    randomize();
    SFroad_SDL_init();
}

void end( void )
{
    endMidiPlay();
    MODStopModule();
    for ( i = 0; i < 90; i++ ) if ( ETC[i] != NULL ) free( ETC[i] );
    for ( i = 0; i < 600; i++ ) if ( E[i] != NULL ) free( E[i] );
    for ( i = 0; i < 300; i++ ) if ( P[i] != NULL ) free( P[i] );
    for ( i = 0; i < 50; i++ ) if ( Eff[i] != NULL ) MODFreeSample( Eff[i] );
    //for ( i = 0; i < 10; i++ ) if ( Mus[i] != NULL ) MODFreeModule( Mus[i] );
    page_off();
    del_key();
    TEXTmode();
    SFroad_SDL_quit();
}

void sprite_load( const char *name )
{

    FILE *f;

    int ij;
    char bigyo[28], hstr[28] = "Arix Sprite Capture Ver 2.0";

    if ( (f = fopen( ".\\SPR\\KEN.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 0; i < MAX_NUMBER; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &X[i], 2, 1, f ); fread( &Y[i], 2, 1, f );
                P[i] = (char *)malloc( X[i] * Y[i] );
                if ( P[i] == NULL ) exit(0);
                fread( P[i], X[i] * Y[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\GUILE.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 100; i < MAX_NUMBER + 100; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &X[i], 2, 1, f ); fread( &Y[i], 2, 1, f );
                P[i] = (char *)malloc( X[i] * Y[i] );
                if ( P[i] == NULL ) exit(0);
                fread( P[i], X[i] * Y[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\IORI.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 200; i < MAX_NUMBER + 200; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &X[i], 2, 1, f ); fread( &Y[i], 2, 1, f );
                P[i] = (char *)malloc( X[i] * Y[i] );
                if ( P[i] == NULL ) exit(0);
                fread( P[i], X[i] * Y[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\EN01.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 0; i < MAX_NUMBER; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\EN02.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 121; i < MAX_NUMBER + 121; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\EN03.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 240; i < MAX_NUMBER + 240; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\BOSS01.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 320; i < MAX_NUMBER + 320; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\BOSS02.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 355; i < MAX_NUMBER + 355; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\BOSS03.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 394; i < MAX_NUMBER + 394; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\BOSS04.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 438; i < MAX_NUMBER + 438; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\BOSS05.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 478; i < MAX_NUMBER + 478; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &EX[i], 2, 1, f ); fread( &EY[i], 2, 1, f );
                E[i] = (char *)malloc( EX[i] * EY[i] );
                if ( E[i] == NULL ) exit(0);
                fread( E[i], EX[i] * EY[i], 1, f );
            }
        }
    	fclose( f );
    }
    if ( (f = fopen( ".\\SPR\\ETC.SPR", "rb" )) != NULL )
    {
        fread( bigyo, 27, 1, f );
        if ( memcmp( hstr, bigyo, 27 ) == 0 )
        {
            fread( &MAX_NUMBER, 2, 1, f );
            for ( i = 0; i < MAX_NUMBER; i++ )
            {
                fread( &ij, 2, 1, f );
                fread( &ETX[i], 2, 1, f ); fread( &ETY[i], 2, 1, f );
                ETC[i] = (char *)malloc( ETX[i] * ETY[i] );
                if ( ETC[i] == NULL ) exit(0);
                fread( ETC[i], ETX[i] * ETY[i], 1, f );
            }
        }
    	fclose( f );
    }
}

void gl_start( void )
{
    int END_Y;
    const char *gl[103] = { "               �e�e �a�q�i ",   //0
                      "",            //1
                      "      �A�� ���B              �� �w�e",//2
                      "                         �� �w�w",                               //3
                      "                         �� ���w",      //4
                      "", //5
                      "      �A�� �a���a����         �� �w�e",//6
                      "", //7
                      "      �a���a               �����a�a��",     //8
                      "",                                          //9
                      "      �q  �b              �����a�a��",                                                      //10
                      "",                                                    //11
                      "      �A�� �A�a��            �� �w�e",                 //12
                      "",                          //13
                      "", //14
                      "",                    //15
                      "�e�i�� �a��....",   //16
                      "",                               //17
                      "�A��... ���i �����e�����a", //18
                      "���� �bΑ�e �ᢁ ���� ��v�s���a",   //19
                      "9���i ���� �bΑ�i �a�a�� ���e�i���s���a", //20
                      "�a�a�a���a�i ���bЖ��e�a",                      //21
                      "�a��A 98�e 12�� 7������ �a�e ����",//22
                      "�A���e �A�b �a���� Ж�s���a",              //23
                      "�� �A���� ���b�e �e 8������ �e�� �{�e�A",     //24
                      "���A�� �a�� �Ŭ�Ж���a",                                                //25
                      "�b�� �E���� �� ����a���a",                                                //27
                      "�E�����a �A�� �e�a�e�A �� ���a����...",                                                //28
                      "�A�� ӱ�i���� ���e �A������ �A�I�A��",                                                //29
                      "������ ē¡�i���a �A�� ӱ�i���s���a",    //30
                      "���b �a�a �e�i�a�e ������ ���w�i",    //31
                      "������ �e��Ё�� �a��... �i��", //32
                      "�a�e�� �e�A�a.", //33
                      "�����e �啡�a�w�a�� �e�i�a Ж�e�A", //34
                      "��Ӂ ���A�� �a�� ���w ���e�A", //35
                      "�q�� ���A�� �A��a �a��", //36
                      "��З�� �e�E�a�e���a",                                     //37
                      "�a���� �w���e �啡�a�e ��ᖁ��", //38
                      "���a�w�a�� �e�i���s���a",                                      //39
                      "��ЁЁ ���A�a", //40
                      "�� �A�� �ᝡ�� ���� �e�i���",                                     //41
                      "�����V�s���a", //42
                      "�����A Ё���A�a", //43
                      "�a�� ���e....", //44
                      "", //45
                      "˳",                                     //46
                      "", //47
                      "�I�B�a ���e�A�� A R I X ǡ�i",                                     //48
                      "�����A ���a���e �a�A���a�a 99��..", //49
                      "",                                     //50
                      "Ported By Raytomely in 2024",   //51
                      "...Thank to me",   //52
                      "For Finding and Porting this game",   //53
                      "", //54
                      "",                                     //55
                      "", //56
                      "", //57
                      "", //58
                      "",                                     //59
                      "", //60
                      "",                                       //61
                      "", //62
                      "",                           //63
                      "", //64
                      "", //65
                      "", //66
                      "", //67
                      "", //68
                      "", //69
                      "", //70
                      "", //71
                      "", //72
                      "", // 73
                      "",                    //74
                      "", //75
                      "", //76
                      "", //77
                      "",  //78
                      "", //79
                      "", //80
                      "", //81
                      "", //82
                      "", //83
                      "", //84
                      "", //85
                      "", //86
                      "", //87
                      "", //88
                      "", //89
                      "", //90
                      "", //91
                      "", //92
                      "", //93
                      "", //94
                      "", //95
                      "", //96
                      "", //97
                      "", //99
                      "", //100
                      "", //101
                      "", //102
                      "",
                      ""
                    };
    END_Y = 275;
    for ( i = 0; i < 103; i++ ) EY[i] = END_Y, END_Y += 10;
    END_Y = 0;
    clear_page( 1 ); copy_page_x( 1 ); fade_run( 100 );
    while( !scan[_ESC] )
    {
        processKeyboardInput(); sleep();
        clear_page( 1 );
        for ( i = 0; i < 53; i++ )
        {
            gul( 0, EY[i], gl[i], 255, 1 );
        }
        if ( END_Y++ > 2 ) { END_Y = 0; for ( i = 0; i < 53; i++ ) EY[i]--; }
        copy_page_x( 1 ); FRAME( 1 );
        if ( EY[51] < -20 ) break;
    }
    read_pcx( ".\\ARG\\LOGO.ARG", 1 ); copy_page_x( 1 );
    while( !scan[_ESC] ) {processKeyboardInput(); sleep();}
    end(), exit(0);
}

