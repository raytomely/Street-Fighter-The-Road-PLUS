#include <MALLOC.H>
#include <STDLIB.H>

#include "LYHWAT.CPP"
#include "MODEX.H"
extern "C"
{
    #include "MIDI.H"
}
#include "SOUND.H"
#include "VALUE.C"
#include "ETC01.C"
#include "ETC02.C"
#include "SKILL.C"
#include "PLAYER.C"
#include "ENEMY.C"
#include "ENEMY2.C"
#include "CHECK.C"

int FRAME_RATE = 1, FRAME_TIME;

void music_init( void )
{
    switch( ROUND )
    {
        case 1:
            switch( ROUND2 )
            {
                case 1: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC1.ARM", 0 ); break;
                case 2: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC2.ARM", 0 ); break;
            }
        break;
        case 2:
            switch( ROUND2 )
            {
                case 1: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC3.ARM", 0 ); break;
                case 4: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC4.ARM", 0 ); break;
            }
        break;
        case 3:
            switch( ROUND2 )
            {
                case 1: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC5.ARM", 0 ); break;
                case 2: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC2.ARM", 0 ); break;
                case 4: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC4.ARM", 0 ); break;
            }
        break;
        case 4:
            switch( ROUND2 )
            {
                case 1: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC6.ARM", 0 ); break;
                case 2: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC7.ARM", 0 ); break;
            }
        break;
        case 5:
            switch( ROUND2 )
            {
                case 1: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC8.ARM", 0 ); break;
                case 3: if ( SOUND2 ) playMidiData( ".\\ARM\\MUSIC9.ARM", 0 ); break;
            }
        break;
        case 6:
            if ( SOUND2 ) playMidiData( ".\\ARM\\MUSICA.ARM", 0 );
        break;
    }
}

void stage_init( void ) //Ïiœ‹a 1¤å : ˆa“w, 2¤å : ”a·q·a¡ ñ´áˆq
{
    switch( ROUND )
    {
        case 1:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\ST101.ARG", 2 );
                    read_pcx( ".\\ARG\\ST102.ARG", 3 );
                    read_pcx( ".\\ARG\\ST103.ARG", 4 );
                    read_pcx( ".\\ARG\\ST104.ARG", 5 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 1, stage_flag[3] = 0;
                break;
                case 2:
                    music_init();
                    read_pcx( ".\\ARG\\ST105.ARG", 2 );
                    read_pcx( ".\\ARG\\ST106.ARG", 3 );
                    read_pcx( ".\\ARG\\ST107.ARG", 4 );
                    read_pcx( ".\\ARG\\ST108.ARG", 5 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 1, stage_flag[3] = 0;
                break;
                case 3:
                    read_pcx( ".\\ARG\\ST109.ARG", 2 );
                    read_pcx( ".\\ARG\\ST110.ARG", 3 );
                    read_pcx( ".\\ARG\\ST111.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 2;
                break;
            }
        break;
        case 2:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\ST201.ARG", 2 );
                    read_pcx( ".\\ARG\\ST202.ARG", 3 );
                    read_pcx( ".\\ARG\\ST203.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 2:
                    read_pcx( ".\\ARG\\ST204.ARG", 2 );
                    read_pcx( ".\\ARG\\ST205.ARG", 3 );
                    stage_flag[0] = 1, stage_flag[1] = 0;
                break;
                case 3:
                    read_pcx( ".\\ARG\\ST206.ARG", 2 );
                    read_pcx( ".\\ARG\\ST207.ARG", 3 );
                    read_pcx( ".\\ARG\\ST208.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 4:
                    music_init();
                    read_pcx( ".\\ARG\\ST209.ARG", 2 );
                    read_pcx( ".\\ARG\\ST210.ARG", 3 );
                    read_pcx( ".\\ARG\\ST211.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 2;
                break;
            }
        break;
        case 3:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\ST301.ARG", 2 );
                    read_pcx( ".\\ARG\\ST302.ARG", 3 );
                    read_pcx( ".\\ARG\\ST303.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 2:
                    music_init();
                    read_pcx( ".\\ARG\\ST304.ARG", 2 );
                    read_pcx( ".\\ARG\\ST305.ARG", 3 );
                    stage_flag[0] = 1, stage_flag[1] = 0;
                break;
                case 3:
                    read_pcx( ".\\ARG\\ST306.ARG", 2 );
                    read_pcx( ".\\ARG\\ST307.ARG", 3 );
                    read_pcx( ".\\ARG\\ST308.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 4:
                    music_init();
                    read_pcx( ".\\ARG\\ST309.ARG", 2 );
                    stage_flag[0] = 2;
                break;
            }
        break;
        case 4:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\ST401.ARG", 2 );
                    read_pcx( ".\\ARG\\ST402.ARG", 3 );
                    read_pcx( ".\\ARG\\ST403.ARG", 4 );
                    read_pcx( ".\\ARG\\ST404.ARG", 5 );
                    read_pcx( ".\\ARG\\ST405.ARG", 6 );
                    read_pcx( ".\\ARG\\ST406.ARG", 7 );
                    read_pcx( ".\\ARG\\ST407.ARG", 8 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 1, stage_flag[3] = 3;
                    stage_flag[4] = 1, stage_flag[5] = 1, stage_flag[6] = 0;
                break;
                case 2:
                    music_init();
                    read_pcx( ".\\ARG\\ST408.ARG", 2 );
                    read_pcx( ".\\ARG\\ST409.ARG", 3 );
                    read_pcx( ".\\ARG\\ST410.ARG", 4 );
                    read_pcx( ".\\ARG\\ST411.ARG", 5 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 1, stage_flag[3] = 0;
                break;
                case 3:
                    read_pcx( ".\\ARG\\ST412.ARG", 2 );
                    stage_flag[0] = 0, stage_flag[1] = 0;
                break;
                case 4:
                    read_pcx( ".\\ARG\\ST413.ARG", 2 );
                    stage_flag[0] = 0, stage_flag[1] = 0;
                break;
                case 5:
                    read_pcx( ".\\ARG\\ST414.ARG", 2 );
                    stage_flag[0] = 2;
                break;
            }
        break;
        case 5:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\ST501.ARG", 2 );
                    read_pcx( ".\\ARG\\ST502.ARG", 3 );
                    read_pcx( ".\\ARG\\ST503.ARG", 4 );
                    read_pcx( ".\\ARG\\ST504.ARG", 5 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 1, stage_flag[3] = 0;
                break;
                case 2:
                    read_pcx( ".\\ARG\\ST505.ARG", 2 );
                    read_pcx( ".\\ARG\\ST506.ARG", 3 );
                    read_pcx( ".\\ARG\\ST507.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 3:
                    music_init();
                    read_pcx( ".\\ARG\\ST508.ARG", 2 );
                    read_pcx( ".\\ARG\\ST509.ARG", 3 );
                    read_pcx( ".\\ARG\\ST510.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 4:
                    read_pcx( ".\\ARG\\ST511.ARG", 2 );
                    read_pcx( ".\\ARG\\ST512.ARG", 3 );
                    read_pcx( ".\\ARG\\ST513.ARG", 4 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 0;
                break;
                case 5:
                    read_pcx( ".\\ARG\\ST514.ARG", 2 );
                    read_pcx( ".\\ARG\\ST515.ARG", 3 );
                    read_pcx( ".\\ARG\\ST516.ARG", 4 );
                    read_pcx( ".\\ARG\\ST517.ARG", 5 );
                    read_pcx( ".\\ARG\\ST518.ARG", 6 );
                    stage_flag[0] = 1, stage_flag[1] = 1, stage_flag[2] = 3, stage_flag[3] = 1, stage_flag[4] = 2;
                break;
            }
        break;
        case 6:
            switch( ROUND2 )
            {
                case 1:
                    music_init();
                    read_pcx( ".\\ARG\\STAGE6.ARG", 2 );
                    stage_flag[0] = 2;
                break;
            }
        break;
    }
}

void stage_scroll( void )
{
    SCROLL = OFF;
    if ( NA.PX > 148 && stage_flag[s_flag] == 1 ) { NA.PX -= 4; if ( NA.DASH == ON || NA.DASH == 2 ) scroll_x += 4; else scroll_x += 3; SCROLL = ON; }
    copy_image( page[PAGE], scroll_x, 0, 359, 269, page[1], 0, 0 );
    copy_image( page[PAGE+1], 0, 0, scroll_x, 269, page[1], 359 - scroll_x, 0 );
    if ( EN[0].LIFE == 0 && EN[1].LIFE == 0 && EN[2].LIFE == 0
          && EN[3].LIFE == 0 && EN[4].LIFE == 0 && EN[5].LIFE == 0
           && EN[6].LIFE == 0 && EN[7].LIFE == 0 && EN[8].LIFE == 0
            && EN[9].LIFE == 0 && EN[10].LIFE == 0 && EN[11].LIFE == 0
             && EN[12].LIFE == 0 && EN[13].LIFE == 0 && EN[14].LIFE == 0
          && EN[15].LIFE == 0 && EN[16].LIFE == 0 && EN[17].LIFE == 0
           && EN[18].LIFE == 0 && EN[19].LIFE == 0 && EN[20].LIFE == 0
            && EN[21].LIFE == 0 && EN[22].LIFE == 0 && EN[23].LIFE == 0
             && EN[24].LIFE == 0 && EN[25].LIFE == 0 && EN[26].LIFE == 0
          && EN[27].LIFE == 0 && EN[28].LIFE == 0 && EN[29].LIFE == 0 && (NA.FLAG == 1 || NA.FLAG == 2) )
    {
        if ( SCROLL_TIME++ > 12 && NEXT_ENEMY == 0 && stage_flag[s_flag] == 0 ) SCROLL_TIME = 0, START = 3;
        if ( stage_flag[s_flag] == 3 ) stage_flag[s_flag] = 1;
        if ( stage_flag[0] == 2 && CLEAR == 0 && ROUND == 6 ) CLEAR = 1, CLEAR_TIME = 0;
        if ( NEXT_ENEMY > 0 ) NEXT_ENEMY--, enemy_init();
        if ( NEXT_ENEMY2 > 0 ) NEXT_ENEMY2--, enemy_init();
    }
    if ( scroll_x > 359 ) scroll_x = 0, PAGE++, s_flag++, enemy_init();
}

void stage_start( void )
{
    if ( START == 1 )
    {
        copy_image( page[2], 0, START_Y, 359, 135, page[1], 0, START_Y );
        copy_image( page[2], 0, 135, 359, START_Y2, page[1], 0, 135 );
        START_Y -= 2; START_Y2 += 2; if ( START_Y2 >= 269 ) START_Y2 = 269;
        if ( START_Y <= 0 )
        {
            START = 2, START_Y = 0, START_Y2 = 269, SCROLL_TIME = 0, NA.JLIFE = 0;
            if ( stage_flag[0] == 0 ) enemy_init(), s_flag = 1;
        }
    }
    if ( START == 2 )
    {
        stage_scroll();
        NA.walk_create(); NA.player_churi(); NA.player(); NA.PX += 4; if ( NA.PX > 50 ) SCROLL_TIME = 0, START = 0, enemy_init(), NA.at_off();
    }
    if ( START == 3 )
    {
        stage_scroll(); NA.Dir = 1;
        NA.walk_create(); NA.player_churi(); NA.player(); NA.PX += 4; if ( NA.PX > 370 ) START = 4, START_Y = 135, START_Y2 = 135, SCROLL_TIME = 0;
    }
    if ( START == 4 )
    {
        copy_image( page[PAGE], 0, 0, 359, START_Y, page[1], 0, 135 - START_Y );
        copy_image( page[PAGE], 0, START_Y2, 359, 269, page[1], 0, 135 );
        START_Y -= 2; START_Y2 += 2; if ( START_Y2 >= 269 ) START_Y2 = 269;
        if ( START_Y <= 0 )
        {
            START_Y = 0, START_Y2 = 269, SCROLL_TIME = 0;
            ROUND2++, stage_init(), NA.PX = -50, NA.PY = 135;
            START = 1, START_Y = 135, START_Y2 = 135, PAGE = 2, s_flag = 0, NA.at_off();
        }
    }
}

void main( void )
{
    system ( "hcode /e" ); start();
    clear_page( 1 ); copy_page_x( 1 ); fade_run( 0 );
    read_pcx( ".\\ARG\\LOGO.ARG", 1 );
    copy_page_x( 1 ); for ( i = 0; i <= 100; i++ ) fade_run( i ), FRAME( 10 );
    for ( i = 0; i < 400; i++ ) FRAME( 10 );
    for ( i = 100; i >= 0; i-- ) fade_run( i ), FRAME( 10 );
    if ( SOUND2 ) playMidiData( ".\\ARM\\TITLE.ARM", 0 );
    clear_page( 1 ); copy_page_x( 1 ); fade_run( 100 );
    read_pcx( ".\\ARG\\TITLE.ARG", 1 );
    copy_page_x( 1 );

    while( !scan[_ENTER] )
    {}

    init_wav();
    sprite_load( ".\\SPR\\KEN.SPR" );
    read_pcx( ".\\ARG\\SELECT.ARG", 2 ); copy_page_x( 2 );
    CUR_X = 45; NA.init_player( 145, 155, PL_TYPE );
    while( 1 )
    {
        copy_page( page[2], page[1] );
        put_sprite( CUR_X, 20, ETX[48], ETY[48], ETC[48], 1 );
        if ( asci[_RTKEY] )
        {
            asci[_RTKEY] = 0; voc_play( 32 );
            CUR_X += 125, PL_TYPE++; if ( CUR_X > 295 ) CUR_X = 295;
            if ( PL_TYPE > 3 ) PL_TYPE = 3;
            NA.init_player( 145, 155, PL_TYPE );
        }
        if ( asci[_LTKEY] )
        {
            asci[_LTKEY] = 0; voc_play( 32 );
            CUR_X -= 125, PL_TYPE--; if ( CUR_X < 45 ) CUR_X = 45;
            if ( PL_TYPE < 1 ) PL_TYPE = 1;
            NA.init_player( 145, 155, PL_TYPE );
        }
        if ( scan[_ENTER] )
        {
            break;
        }
        if ( scan[_A] && scan[_R] && scan[_I] && scan[_X] ) CREDITS = 99;
        NA.player_churi(); NA.player();
        copy_page_x( 1 ); FRAME( 1 );
    }
    NA.init_player( 38, 135, PL_TYPE ); NA.PX = -50, enemy_init();
    START = 1, START_Y = 135, START_Y2 = 135;
    stage_init();
    while( !asci[_ESC] )
    {
        if ( asci[_PGUP] ) { asci[_PGUP] = 0, FRAME_RATE++; FRAME_TIME = 30; if ( FRAME_RATE > 30 ) FRAME_RATE = 30; }
        if ( asci[_PGDN] ) { asci[_PGDN] = 0, FRAME_RATE--; FRAME_TIME = 30; if ( FRAME_RATE < 0 ) FRAME_RATE = 0; }

        stage_start();
        if ( START == 0 )
        {
            stage_scroll();
            NA.player_churi(); NA.key_churi();
            NA.enemy_check(); for ( i = 0; i < 30; i++ ) EN[i].player_check();
            for ( ei = 0; ei < 30; ei++ ) { if ( EN[ei].LIFE == 1 ) { EN[ei].enemy_move(), EN[ei].enemy_churi(); } }
            for ( ei = 0; ei < 30; ei++ ) { if ( EN[ei].LIFE == 2 ) { EN[ei].enemy_dead2(); } }
            for ( PYOSI_Y = 0; PYOSI_Y < 350; PYOSI_Y++ )
            {
                if ( NA.DAMAGE == OFF && NA.SPECIAL == OFF && NA.JUMP == OFF && NA.DASH == OFF )
                {
                    if ( NA.PY + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.player();
                }
                if ( NA.DAMAGE == ON || NA.SPECIAL == ON || NA.JUMP == ON || NA.DASH == ON )
                {
                    if ( NA.PY2 + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.player();
                }
                if ( NA.PY + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.jang_move();
                for ( ei = 0; ei < 10; ei++ )
                {
                    if ( PYOSI_Y == IT[ei].PY + ETY[IT[ei].ACT] ) IT[ei].item();
                    if ( PYOSI_Y == IT2[ei].PY + ETY[IT2[ei].ACT] ) IT2[ei].item2();
                }
                for ( ei = 0; ei < 30; ei++ )
                {
                    if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].jang_move();
                    if ( EN[ei].DAMAGE == OFF && EN[ei].JUMP == OFF )
                    {
                        if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].enemy();
                    }
                    if ( EN[ei].DAMAGE == ON || EN[ei].JUMP == ON )
                    {
                        if ( EN[ei].PY2 + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].enemy();
                    }
                }
                if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].jang_move();
            }
            for ( i3 = 0; i3 < 30; i3++ ) TN[i3].ting_move();
            //lyh_gul( 0, 0, EN[0].PX, 1 );
            //lyh_gul( 30, 0, EN[0].PY + EN[0].SY, 1 );
            box_fill( 31, 20, 31 + NA.ENERGY, 24, 248, 1 );
            switch( NA.TYPE )
            {
                case 1: put_sprite( 0, 10, ETX[4], ETY[4], ETC[4], 1 ); break;
                case 2: put_sprite( 0, 10, ETX[4], ETY[4], ETC[5], 1 ); break;
                case 3: put_sprite( 0, 10, ETX[4], ETY[4], ETC[6], 1 ); break;
            }
            if ( PYOSI2 == 1 && EN_PYOSI_TIME++ < 70 )
            {
                switch( EN_TYPE )
                {
                    case 1: put_sprite( 0, 43, EX[18], EY[18], E[18], 1 ); break;
                    case 2: put_sprite( 0, 43, EX[18], EY[18], E[36], 1 ); break;
                    case 3: put_sprite( 0, 43, EX[18], EY[18], E[54], 1 ); break;
                    case 4: put_sprite( 0, 43, EX[18], EY[18], E[74], 1 ); break;
                    case 5: put_sprite( 0, 43, EX[18], EY[18], E[95], 1 ); break;
                    case 6: put_sprite( 0, 43, EX[18], EY[18], E[120], 1 ); break;
                    case 7: put_sprite( 0, 43, EX[18], EY[18], E[147], 1 ); break;
                    case 8: put_sprite( 0, 43, EX[18], EY[18], E[164], 1 ); break;
                    case 9: put_sprite( 0, 43, EX[18], EY[18], E[189], 1 ); break;
                    case 10: put_sprite( 0, 43, EX[18], EY[18], E[215], 1 ); break;
                    case 11: put_sprite( 0, 43, EX[18], EY[18], E[235], 1 ); break;
                    case 12: put_sprite( 0, 43, EX[18], EY[18], E[258], 1 ); break;
                    case 13: put_sprite( 0, 43, EX[18], EY[18], E[286], 1 ); break;
                    case 14: put_sprite( 0, 43, EX[18], EY[18], E[311], 1 ); break;
                    case 15: put_sprite( 0, 43, EX[18], EY[18], E[354], 1 ); break;
                    case 16: put_sprite( 0, 43, EX[18], EY[18], E[393], 1 ); break;
                    case 17: put_sprite( 0, 43, EX[18], EY[18], E[437], 1 ); break;
                    case 18: put_sprite( 0, 43, EX[18], EY[18], E[477], 1 ); break;
                    case 19: put_sprite( 0, 43, EX[18], EY[18], E[514], 1 ); break;
                }
                switch( EN_COUNT )
                {
                    case 0: box_fill( 32, 58, 32 + EN1_MAX, 64, 224, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 248, 1 );
                    break;
                    case 1: box_fill( 32, 58, 32 + EN1_MAX, 64, 248, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 235, 1 );
                    break;
                    case 2: box_fill( 32, 58, 32 + EN1_MAX, 64, 235, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 205, 1 );
                    break;
                    case 3: box_fill( 32, 58, 32 + EN1_MAX, 64, 205, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 190, 1 );
                    break;
                    case 4: box_fill( 32, 58, 32 + EN1_MAX, 64, 190, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 179, 1 );
                    break;
                    case 5: box_fill( 32, 58, 32 + EN1_MAX, 64, 179, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 161, 1 );
                    break;
                }
                draw_box( 32, 58, 32 + EN1_MAX, 64, 19, 1 );
            }
            if ( FRAME_TIME > 0 ) gul( 0, 259, "Frame Rate :", 255, 1 ), lyh_gul( 120, 259, FRAME_RATE, 1 ), FRAME_TIME--;
            gul( 60, 30, "*", 255, 1 ); lyh_gul( 80, 30, DATSU,  1 );
        }
        if ( START == -1 || START == -3 )
        {
            stage_scroll();
            for ( PYOSI_Y = 0; PYOSI_Y < 350; PYOSI_Y++ )
            {
                if ( NA.DAMAGE == OFF && NA.SPECIAL == OFF && NA.JUMP == OFF && NA.DASH == OFF )
                {
                    if ( NA.PY + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.player();
                }
                if ( NA.DAMAGE == ON || NA.SPECIAL == ON || NA.JUMP == ON || NA.DASH == ON )
                {
                    if ( NA.PY2 + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.player();
                }
                if ( NA.PY + Y[NA.ACT[NA.act]] + NA.sy[NA.act] == PYOSI_Y ) NA.jang_move();
                for ( ei = 0; ei < 10; ei++ )
                {
                    if ( PYOSI_Y == IT[ei].PY + ETY[IT[ei].ACT] ) IT[ei].item();
                    if ( PYOSI_Y == IT2[ei].PY + ETY[IT2[ei].ACT] ) IT2[ei].item2();
                }
                for ( ei = 0; ei < 30; ei++ )
                {
                    if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].jang_move();
                    if ( EN[ei].DAMAGE == OFF && EN[ei].JUMP == OFF )
                    {
                        if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].enemy();
                    }
                    if ( EN[ei].DAMAGE == ON || EN[ei].JUMP == ON )
                    {
                        if ( EN[ei].PY2 + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].enemy();
                    }
                }
                if ( EN[ei].PY + EY[EN[ei].ACT[EN[ei].act]] + EN[ei].sy[EN[ei].act] == PYOSI_Y ) EN[ei].jang_move();
            }
            for ( i3 = 0; i3 < 30; i3++ ) TN[i3].ting_move();
            box_fill( 31, 20, 31 + NA.ENERGY, 24, 248, 1 );
            switch( NA.TYPE )
            {
                case 1: put_sprite( 0, 10, ETX[4], ETY[4], ETC[4], 1 ); break;
                case 2: put_sprite( 0, 10, ETX[4], ETY[4], ETC[5], 1 ); break;
                case 3: put_sprite( 0, 10, ETX[4], ETY[4], ETC[6], 1 ); break;
            }
            if ( PYOSI2 == 1 && EN_PYOSI_TIME++ < 70 )
            {
                switch( EN_TYPE )
                {
                    case 1: put_sprite( 0, 43, EX[18], EY[18], E[18], 1 ); break;
                    case 2: put_sprite( 0, 43, EX[18], EY[18], E[36], 1 ); break;
                    case 3: put_sprite( 0, 43, EX[18], EY[18], E[54], 1 ); break;
                    case 4: put_sprite( 0, 43, EX[18], EY[18], E[74], 1 ); break;
                    case 5: put_sprite( 0, 43, EX[18], EY[18], E[95], 1 ); break;
                    case 6: put_sprite( 0, 43, EX[18], EY[18], E[120], 1 ); break;
                    case 7: put_sprite( 0, 43, EX[18], EY[18], E[147], 1 ); break;
                    case 8: put_sprite( 0, 43, EX[18], EY[18], E[164], 1 ); break;
                    case 9: put_sprite( 0, 43, EX[18], EY[18], E[189], 1 ); break;
                    case 10: put_sprite( 0, 43, EX[18], EY[18], E[215], 1 ); break;
                    case 11: put_sprite( 0, 43, EX[18], EY[18], E[235], 1 ); break;
                    case 12: put_sprite( 0, 43, EX[18], EY[18], E[258], 1 ); break;
                    case 13: put_sprite( 0, 43, EX[18], EY[18], E[286], 1 ); break;
                    case 14: put_sprite( 0, 43, EX[18], EY[18], E[311], 1 ); break;
                    case 15: put_sprite( 0, 43, EX[18], EY[18], E[354], 1 ); break;
                    case 16: put_sprite( 0, 43, EX[18], EY[18], E[393], 1 ); break;
                    case 17: put_sprite( 0, 43, EX[18], EY[18], E[437], 1 ); break;
                    case 18: put_sprite( 0, 43, EX[18], EY[18], E[477], 1 ); break;
                    case 19: put_sprite( 0, 43, EX[18], EY[18], E[514], 1 ); break;
                }
                switch( EN_COUNT )
                {
                    case 0: box_fill( 32, 58, 32 + EN1_MAX, 64, 224, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 248, 1 );
                    break;
                    case 1: box_fill( 32, 58, 32 + EN1_MAX, 64, 248, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 235, 1 );
                    break;
                    case 2: box_fill( 32, 58, 32 + EN1_MAX, 64, 235, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 205, 1 );
                    break;
                    case 3: box_fill( 32, 58, 32 + EN1_MAX, 64, 205, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 190, 1 );
                    break;
                    case 4: box_fill( 32, 58, 32 + EN1_MAX, 64, 190, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 179, 1 );
                    break;
                    case 5: box_fill( 32, 58, 32 + EN1_MAX, 64, 179, 1 );
                            box_fill( 32, 59, 32 + EN2_MAX, 63, 161, 1 );
                    break;
                }
                draw_box( 32, 58, 32 + EN1_MAX, 64, 19, 1 );
            }
            if ( START == -1 )
            {
                put_sprite( 110, 120, ETX[49], ETY[49], ETC[49], 1 );
                put_sprite( 120, 155, ETX[61], ETY[61], ETC[61], 1 );
                switch( CONTI )
                {
                    case 9: put_sprite( 250, 120, ETX[50], ETY[50], ETC[50], 1 ); break;
                    case 8: put_sprite( 250, 120, ETX[51], ETY[51], ETC[51], 1 ); break;
                    case 7: put_sprite( 250, 120, ETX[52], ETY[52], ETC[52], 1 ); break;
                    case 6: put_sprite( 250, 120, ETX[53], ETY[53], ETC[53], 1 ); break;
                    case 5: put_sprite( 250, 120, ETX[54], ETY[54], ETC[54], 1 ); break;
                    case 4: put_sprite( 250, 120, ETX[55], ETY[55], ETC[55], 1 ); break;
                    case 3: put_sprite( 250, 120, ETX[56], ETY[56], ETC[56], 1 ); break;
                    case 2: put_sprite( 250, 120, ETX[57], ETY[57], ETC[57], 1 ); break;
                    case 1: put_sprite( 250, 120, ETX[58], ETY[58], ETC[58], 1 ); break;
                    case 0: put_sprite( 250, 120, ETX[59], ETY[59], ETC[59], 1 ); break;
                }
                if ( CONT_TIME++ > 70 ) CONT_TIME = 0, CONTI--, voc_play( 32 );
                if ( asci[_ENTER] && CREDITS > 0 )
                {
                    CREDITS--, DATSU = 3, NA.ENERGY = 288; START = -3; asci[_ENTER] = 0;
                }
                if ( CREDITS < 0 || CONTI == 0 ) START = -2;
                gul( 140, 140, "CREDITS", 255, 1 ); lyh_gul( 215, 140, CREDITS, 1 );
            }
            if ( START == -3 )
            {
                switch( PL_TYPE )
                {
                    case 1: put_sprite( 0, 43, ETX[62], ETY[62], ETC[62], 1 ); break;
                    case 2: put_sprite( 0, 43, ETX[62], ETY[62], ETC[63], 1 ); break;
                    case 3: put_sprite( 0, 43, ETX[62], ETY[62], ETC[64], 1 ); break;
                }
                if ( asci[_ENTER] )
                {
                    START = 0; NA.init_player( 50, 135, PL_TYPE ); asci[_ENTER] = 0;
                    for ( i2 = 0; i2 < 30; i2++ ) if ( EN[i2].LIFE == 1 && EN[i2].MV == 1 ) EN[i2].DAMAGE_TYPE = 2, EN[i2].damage_create(), EN[i2].ENERGY -= 10;
                }
                if ( asci[_RTKEY] )
                {
                    asci[_RTKEY] = 0, PL_TYPE++; if ( PL_TYPE > 3 ) PL_TYPE = 3; voc_play( 32 );
                }
                if ( asci[_LTKEY] )
                {
                    asci[_LTKEY] = 0, PL_TYPE--; if ( PL_TYPE < 1 ) PL_TYPE = 1; voc_play( 32 );
                }
            }
            if ( FRAME_TIME > 0 ) gul( 0, 259, "Frame Rate :", 255, 1 ), lyh_gul( 120, 259, FRAME_RATE, 1 ), FRAME_TIME--;
            gul( 60, 30, "*", 255, 1 ); lyh_gul( 80, 30, DATSU,  1 );
        }
        if ( CLEAR == 1 )
        {
            switch( ROUND )
            {
                case 1: put_sprite( 110, 120, ETX[43], ETY[43], ETC[43], 1 ); break;
                case 2: put_sprite( 110, 120, ETX[43], ETY[43], ETC[44], 1 ); break;
                case 3: put_sprite( 110, 120, ETX[43], ETY[43], ETC[45], 1 ); break;
                case 4: put_sprite( 110, 120, ETX[43], ETY[43], ETC[46], 1 ); break;
                case 5: put_sprite( 110, 120, ETX[43], ETY[43], ETC[47], 1 ); break;
            }
            CLEAR_TIME++;
            if ( CLEAR_TIME > 200 )
            {
                for ( i = 100; i >= 0; i-- ) fade_run( i ), FRAME( 5 );
                clear_page( 1 ), clear_page( 2 ); copy_page_x( 1 ); PAGE = 2;
                ROUND++, NA.ENERGY = 288, NA.Dir = 1, ROUND2 = 1, s_flag = 0;
                for ( i = 0; i < 30; i++ ) EN[i].LIFE = 0;
                if ( ROUND == 7 )
                {
                    if ( SOUND2 ) playMidiData( ".\\ARM\\ENDING.ARM", 0 );
                    break;
                }
                stage_init(); NA.PX = -50, NA.PY = 135, enemy_init(), scroll_x = 0;
                START = 1, START_Y = 135, START_Y2 = 135, CLEAR = 0, CLEAR_TIME = 0;
            }
        }
        if ( START == -2 )
        {
            stage_scroll();
            put_sprite( 110, 120, ETX[60], ETY[60], ETC[60], 1 );
            if ( scan[_ENTER] || scan[_ESC] ) break;
        }
        copy_page_x( 1 ); FRAME( FRAME_RATE );
        //if ( scan[_A] ) CLEAR = 1;
        if ( asci[_P] ) { asci[_P] = 0; while( !asci[_P] ) { if ( scan[_O] ) break; asci[_P] = 0; asci[_O] = 0; } }
    }
    if ( ROUND == 7 ) gl_start();
    end();
    printf( "Street Fighter The Road PLUS\n" );
    printf( "Copyright (c) 1998 Arix Team Present.\n" );
    printf( "Thank you for playing...\n\n" );
}
