void start( void )
{
    if ( MODDetectCard( &Port, &IRQ, &DRQ ) )
    {
        printf( "Sound Blaster not Found.\n" ); getch();
        SOUND = 0;
    } else SOUND = 1, MODPlayModule( Mus, 8, 8000, Port, IRQ, DRQ, PM_TIMER );
    playMidiLoopCounter = 20; /* £¡—¡ÑÁ·© ¤e¥¢ µeº ˆ•® */
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
}

void sprite_load( char *name )
{

    FILE *f;

    int ij;
    char *bigyo, hstr[28] = "Arix Sprite Capture Ver 2.0";

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
    char *gl[103] = { "                e—e ¬aœq—i ",   //0
                      "",            //1
                      "      ‰A·± ‹¡ÒB              ·¡ ¶wÐe",//2
                      "                         ·¡ ¶w¬w",                               //3
                      "                         ·¡ £¥µw",      //4
                      "", //5
                      "      ‰A·± Ïa¡‹aœ£·         ·¡ ¶wÐe",//6
                      "", //7
                      "      ¬a¶…—a               ‰·ˆ¸aža¯©",     //8
                      "",                                          //9
                      "      ·q  ´b              ‰·ˆ¸aža¯©",                                                      //10
                      "",                                                    //11
                      "      ‰A·± ÉA¯aÈá            ·¡ ¶wÐe",                 //12
                      "",                          //13
                      "", //14
                      "",                    //15
                      " e—i‰¡ a¬á....",   //16
                      "",                               //17
                      "ÓA¶... ¸÷ i µ¡œ… e·¡Š…¶a", //18
                      "·¡¤å ¸bÎ‘·e á¢ µ¡œ ˆév¯s“¡”a",   //19
                      "9¶©”i ¦Èá ¸bÎ‘·i Ðaa•¡ ¡µ e—i´ö¯s“¡”a", //20
                      "´aŸa¤a·¡ËaŸi ¯¡¸bÐ–ˆá—e¶a",                      //21
                      "‹aœå•A 98‘e 12¶© 7·©¦¡ ‹a e –‰¡",//22
                      "‰A·± e ¹A¸b Ða‹¡¡ Ð–¯s“¡”a",              //23
                      "·¡ ‰A·±· ¯¡¸b·e Ðe 8¶©¦Èá Ðeˆá ˆ{·e•A",     //24
                      "·¡¹A´¡ ‰a¶ µÅ¬÷Ð–Š…¶a",                                                //25
                      "µb¯¡ µE—··¡ ´ô‰¡ °éœ÷ÐaŠ…¶a",                                                //27
                      "µE—··¡a •A¡¡  e—a“e‰A ¹± »¡‰a¶¡¬á...",                                                //28
                      "¹A·© Ó±—i´ö”å ˆõ·e ‘Aµ¡»¡µ¡ µA£IµA¬á",                                                //29
                      "·¡µ¡Ÿ¡ Ä“Â¡Ði˜ˆa ¹A·© Ó±—i´ö¯s“¡”a",    //30
                      "•·¸b Ðaa  e—ia¡e ·©·©·¡ ¤‰w·i",    //31
                      "»¡¶¡¬á Íe»³Ð´¡ Ða“¡...  i¡", //32
                      "ÎaÑe·¡ ´e–Aºa.", //33
                      "¶¥œ“e ¶å•¡»a¶w·a¡  e—ia Ð–“e•A", //34
                      "¸áÓ »³µA¬å ´a¢ ·¡¬w ´ô“e‰A", //35
                      "q· »³µA¬å µAœáˆa a‰¡", //36
                      "¯©Ð—·¡ ´e–E”a“eŠ…¶a",                                     //37
                      "‹aœ¬á ”w¦…ˆe ¶å•¡»a“e ¸ó´á–‰¡", //38
                      "•¡¯a¶w·a¡  e—i´ö¯s“¡”a",                                      //39
                      "·¡ÐÐ º­A¶a", //40
                      "·¡ ‰A·± –á¡•¡ ‰­¢  e—i´á¬á",                                     //41
                      "µ©Ÿ¡‰V¯s“¡”a", //42
                      "¸£¶‰A Ðº­A¶a", //43
                      "‹aœñ ·¡ e....", //44
                      "", //45
                      "Ë³",                                     //46
                      "", //47
                      "­IBËa ÑÁ¡eµA¬á A R I X Ç¡Ÿi",                                     //48
                      "•·¯¡µA ’Ÿa¯¡¡e ÇaA—¡Ëaˆa 99¡..", //49
                      "",                                    //50
                      "", //51
                      "", //52
                      "",                                     //53
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
    while( !scan[_ESC] ) {}
    end(), exit(0);
}

