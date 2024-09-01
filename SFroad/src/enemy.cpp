//"ENEMY.C" ¸â ÀáŸ¡ ¦¦…
#include "value.h"
#include "extern.h"

void ENEMY :: at_off( void )
{
    if ( FLAG == 7 ) s_enemy();
    WALK = OFF, ATTACK = OFF, JUMP = OFF, MOVE = OFF, DAMAGE = OFF, SPECIAL = OFF;
    FLAG = 0, HIT_TYPE = 1, DAMAGE_TYPE = 0, SHIELD = OFF;
    for ( i = 0; i < 30; i++ ) at[i] = 0;
}

void ENEMY :: Ti( int t )
{
    for ( i = 0; i <= last_act; i++ ) TI[i] = t;
}

void ENEMY :: set_SXSY( int t )
{
    switch( t )
    {
        case 1:
            switch( Dir )
            {
                case 1:
                    for ( i = 0; i <= last_act; i++ )
                    sx[i] = 0, sy[i] = SY - EY[ACT[i]];
                break;
                case 2:
                    for ( i = 0; i <= last_act; i++ )
                    sx[i] = SX - EX[ACT[i]], sy[i] = SY - EY[ACT[i]];
                break;
            }
        break;
        case 2:
            for ( i = 0; i <= last_act; i++ )
            sx[i] = (SX - EX[ACT[i]])/2, sy[i] = (SY - EY[ACT[i]])/2;
        break;
    }
}

void ENEMY :: act_churi( int t )
{
    if ( TIME++ > TI[act] ) TIME = 0, act++;
    switch( t )
    {
        case 1:
            if ( act > last_act ) act = 0;
        break;
        case 2:
            if ( act > last_act ) act = last_act;
        break;
    }
}

void ENEMY :: init_enemy( int x, int y, int t, int e, int m, int mj, int d )
{
    at_off(); MV = m;
    PX = x, TYPE = t, act = 0, TIME = 0, Dir = d, FLAG = 1, HIT_TYPE = 1;
    LIFE = 1, en_count = 0; if ( e > 1435 ) e = 1435;
    if ( e > 287 ) en_count++, e -= 287;
    if ( e > 287 ) en_count++, e -= 287;
    if ( e > 287 ) en_count++, e -= 287;
    if ( e > 287 ) en_count++, e -= 287;
    if ( e > 287 ) en_count++, e -= 287;
    EN_MAX = e, ENERGY = e;
    switch( TYPE )
    {
        case 1: // ‹¡¥¥¸â 1
            ACT[0] = 1, DEAD_FLAG = 11;
            last_act = 0, SX = 56, SY = 93, Ti( 2 );
        break;
        case 2: // ‹¡¥¥¸â 2
            ACT[0] = 21, DEAD_FLAG = 30;
            last_act = 0, SX = 56, SY = 84, Ti( 2 );
        break;
        case 3: // ‹¡¥¥¸â 3
            ACT[0] = 37, DEAD_FLAG = 48;
            last_act = 0, SX = 58, SY = 85, Ti( 2 );
        break;
        case 4: // ˆi‰¡Ÿ¡ ¸â
            ACT[0] = 57, DEAD_FLAG = 71;
            last_act = 0, SX = 85, SY = 96, Ti( 2 );
        break;
        case 5: // ‹¡¥¥¸â 4
            switch( mj )
            {
                case 1: ACT[0] = 75; break;
                case 2: ACT[0] = 85; break;
            }
            DEAD_FLAG = 84;
            last_act = 0, SX = 73, SY = 88, Ti( 2 );
        break;
        case 6: // ‹¡¥¥¸â 5
            switch( mj )
            {
                case 1: ACT[0] = 96; break;
                case 2: ACT[0] = 110; break;
            }
            DEAD_FLAG = 109;
            last_act = 0, SX = 68, SY = 89, Ti( 2 );
        break;
        case 7: // ‹¡¥¥¸â 6
            switch( mj )
            {
                case 1: ACT[0] = 121; break;
                case 2: ACT[0] = 137; break;
            }
            DEAD_FLAG = 136;
            last_act = 0, SX = 67, SY = 89, Ti( 2 );
        break;
        case 8: //´³¬sÐe ¸â
            ACT[0] = 148; DEAD_FLAG = 156;
            last_act = 0, SX = 58, SY = 91, Ti( 2 );
        break;
        case 9: //¸Çµ· ¸â
            switch( mj )
            {
                case 1: ACT[0] = 165; break;
                case 2: ACT[0] = 166; break;
            }
            DEAD_FLAG = 181;
            last_act = 0, SX = 64, SY = 100, Ti( 2 );
        break;
        case 10: //Äi¸“·¡
            ACT[0] = 190, DEAD_FLAG = 207, MV = 1;
            last_act = 0, SX = 57, SY = 97, Ti( 2 );
        break;
        case 11: //ˆá·¥
            ACT[0] = 217, DEAD_FLAG = 229, MV = 1;
            last_act = 0, SX = 75, SY = 111, Ti( 2 );
        break;
        case 12: //Ê—Ê—·¡
            ACT[0] = 236, DEAD_FLAG = 249, MV = 1;
            last_act = 0, SX = 77, SY = 92, Ti( 2 );
        break;
        case 13: //µa¸a
            ACT[0] = 267, DEAD_FLAG = 279;
            last_act = 0, SX = 45, SY = 93, Ti( 2 );
        break;
        case 14: // ‹¡¥¥¸â 7
            switch( mj )
            {
                case 1: ACT[0] = 287; break;
                case 2: ACT[0] = 301; break;
            }
            DEAD_FLAG = 300;
            last_act = 0, SX = 66, SY = 89, Ti( 2 );
        break;
        case 15: //¥¡¯a 1
            ACT[0] = 320, ACT[1] = 321, ACT[2] = 322, ACT[3] = 323, ACT[4] = 322, ACT[5] = 321;
            DEAD_FLAG = 346;
            last_act = 5, SX = 71, SY = 110, Ti( 3 );
        break;
        case 16: //¥¡¯a 2
            ACT[0] = 355, ACT[1] = 356, ACT[2] = 357, ACT[3] = 358;
            DEAD_FLAG = 385;
            last_act = 3, SX = 87, SY = 113, Ti( 3 );
        break;
        case 17: //¥¡¯a 3
            ACT[0] = 394, ACT[1] = 395, ACT[2] = 396, ACT[3] = 397, ACT[4] = 398, ACT[5] = 399;
            DEAD_FLAG = 426;
            last_act = 5, SX = 78, SY = 97, Ti( 3 );
        break;
        case 18: //¥¡¯a 4
            ACT[0] = 438, ACT[1] = 439, ACT[2] = 440, ACT[3] = 439;
            DEAD_FLAG = 469;
            last_act = 3, SX = 66, SY = 112, Ti( 3 );
        break;
        case 19: //¥¡¯a 5
            ACT[0] = 478, ACT[1] = 479, ACT[2] = 480, ACT[3] = 479;
            DEAD_FLAG = 505;
            last_act = 3, SX = 66, SY = 111, Ti( 5 );
        break;
    }
    PY = y;
    set_SXSY( 1 );
}

void ENEMY :: s_enemy( void )
{
    TIME = 0, FLAG = 1, THROW = OFF, HIT_TYPE = 1, last_act = 1; Ti( 2 );
    switch( TYPE )
    {
        case 1: //‹¡¥¥¸â 1
            ACT[0] = 1, ACT[1] = 1;
        break;
        case 2: //‹¡¥¥¸â 2
            ACT[0] = 21, ACT[1] = 21;
        break;
        case 3: //‹¡¥¥¸â 3
            ACT[0] = 39, ACT[1] = 39;
        break;
        case 4: //ˆi‰¡Ÿ¡ ¸â
            ACT[0] = 57, ACT[1] = 57;
        break;
        case 5: //‹¡¥¥¸â 4
            ACT[0] = 76, ACT[1] = 76;
        break;
        case 6: //‹¡¥¥¸â 5
            ACT[0] = 97, ACT[1] = 97;
        break;
        case 7: //‹¡¥¥¸â 6
            ACT[0] = 123, ACT[1] = 123;
        break;
        case 8: //´³¬sÐe ¸â
            ACT[0] = 149, ACT[1] = 149;
        break;
        case 9: //¸Çµ· ¸â
            ACT[0] = 169, ACT[1] = 169;
        break;
        case 10: //Äi¸“·¡
            ACT[0] = 191, ACT[1] = 191;
        break;
        case 11: //ˆá·¥
            ACT[0] = 217, ACT[1] = 217;
        break;
        case 12: //Ê—Ê—·¡
            ACT[0] = 236, ACT[1] = 236;
        break;
        case 13: //µa¸a
            ACT[0] = 259, ACT[1] = 259;
        break;
        case 14: //‹¡¥¥¸â 7
            ACT[0] = 288, ACT[1] = 288;
        break;
        case 15: //¥¡¯a 1
            ACT[0] = 320, ACT[1] = 321, ACT[2] = 322, ACT[3] = 323, ACT[4] = 322, ACT[5] = 321;
            last_act = 5, Ti( 3 );
        break;
        case 16: //¥¡¯a 2
            ACT[0] = 355, ACT[1] = 356, ACT[2] = 357, ACT[3] = 358;
            last_act = 3, Ti( 3 );
        break;
        case 17: //¥¡¯a 3
            ACT[0] = 394, ACT[1] = 395, ACT[2] = 396, ACT[3] = 397, ACT[4] = 398, ACT[5] = 399;
            last_act = 5, Ti( 3 );
        break;
        case 18: //¥¡¯a 4
            ACT[0] = 438, ACT[1] = 439, ACT[2] = 440, ACT[3] = 439;
            last_act = 3, Ti( 5 );
        break;
        case 19: //¥¡¯a 5
            ACT[0] = 478, ACT[1] = 479, ACT[2] = 480, ACT[3] = 479;
            last_act = 3, Ti( 5 );
        break;
    }
    act = 0; set_SXSY( 1 );
}

void ENEMY :: walk_create( void )
{
    FLAG = 2, last_act = 3, Ti( 2 );
    switch( TYPE )
    {
        case 1: //‹¡¥¥¸â 1
            ACT[0] = 0, ACT[1] = 1, ACT[2] = 2, ACT[3] = 1;
        break;
        case 2: //‹¡¥¥¸â 2
            ACT[0] = 19, ACT[1] = 20, ACT[2] = 21, ACT[3] = 20;
        break;
        case 3: //‹¡¥¥¸â 3
            ACT[0] = 37, ACT[1] = 38, ACT[2] = 39, ACT[3] = 38;
        break;
        case 4: //ˆi‰¡Ÿ¡ ¸â
            ACT[0] = 55, ACT[1] = 56, ACT[2] = 57, ACT[3] = 56;
        break;
        case 5: //‹¡¥¥¸â 4
            last_act = 4, Ti( 4 );
            ACT[0] = 78, ACT[1] = 76, ACT[2] = 77, ACT[3] = 78, ACT[4] = 77;
        break;
        case 6: //‹¡¥¥¸â 5
            last_act = 6, Ti( 4 );
            ACT[0] = 97, ACT[1] = 98, ACT[2] = 99, ACT[3] = 100, ACT[4] = 101, ACT[5] = 102, ACT[6] = 100;
        break;
        case 7: //‹¡¥¥¸â 6
            last_act = 5, Ti( 4 );
            ACT[0] = 122, ACT[1] = 123, ACT[2] = 124, ACT[3] = 125, ACT[4] = 126, ACT[5] = 127;
        break;
        case 8: //´³¬sÐe ¸â
            last_act = 3, Ti( 2 );
            ACT[0] = 150, ACT[1] = 149, ACT[2] = 151, ACT[3] = 149;
        break;
        case 9: //¸Çµ· ¸â
            last_act = 4, Ti( 5 );
            ACT[0] = 167, ACT[1] = 168, ACT[2] = 169, ACT[3] = 170, ACT[4] = 171;
        break;
        case 10: //Äi¸“·¡
            last_act = 4, Ti( 5 );
            ACT[0] = 190, ACT[1] = 191, ACT[2] = 192, ACT[3] = 190, ACT[4] = 193;
        break;
        case 11: //ˆá·¥
            last_act = 2, Ti( 5 );
            ACT[0] = 216, ACT[1] = 217, ACT[2] = 218;
        break;
        case 12: //Ê—Ê—·¡
            last_act = 3, Ti( 5 );
            ACT[0] = 236, ACT[1] = 237, ACT[2] = 238, ACT[3] = 239;
        break;
        case 13: //µa¸a
            last_act = 3, Ti( 5 );
            ACT[0] = 259, ACT[1] = 260, ACT[2] = 261, ACT[3] = 260;
        break;
        case 14: //‹¡¥¥¸â 7
            last_act = 4, Ti( 5 );
            ACT[0] = 288, ACT[1] = 289, ACT[2] = 290, ACT[3] = 289, ACT[4] = 291;
        break;
        case 15: //¥¡¯a 1
            last_act = 5, Ti( 5 );
            ACT[0] = 324, ACT[1] = 325, ACT[2] = 324, ACT[3] = 326, ACT[4] = 327, ACT[5] = 326;
        break;
        case 16: //¥¡¯a 2
            last_act = 3, Ti( 5 );
            ACT[0] = 359, ACT[1] = 360, ACT[2] = 361, ACT[3] = 360;
        break;
        case 17: //¥¡¯a 3
            last_act = 11, Ti( 2 );
            ACT[0] = 400, ACT[1] = 401, ACT[2] = 400, ACT[3] = 394, ACT[4] = 402, ACT[5] = 403;
            ACT[6] = 404, ACT[7] = 405, ACT[8] = 404, ACT[9] = 403, ACT[10] = 402, ACT[11] = 394;
        break;
        case 18: //¥¡¯a 4
            last_act = 3, Ti( 5 );
            ACT[0] = 441, ACT[1] = 438, ACT[2] = 442, ACT[3] = 438;
        break;
        case 19: //¥¡¯a 5
            last_act = 5, Ti( 5 );
            ACT[0] = 481, ACT[1] = 482, ACT[2] = 481, ACT[3] = 483, ACT[4] = 479, ACT[5] = 483;
        break;
    }
    set_SXSY( 1 );
    WALK = ON, MOVE = ON;
}

void ENEMY :: punch_create( void )
{
    FLAG = 3, act = 0, TIME = 0, HIT_TYPE = 1, last_act = 2, Ti( 2 ), TI[1] = 4;
    switch( TYPE )
    {
        case 1: //‹¡¥¥¸â 1
            POW = 15; ACT[0] = 3, ACT[1] = 4, ACT[2] = 3, at[1] = 1; voc_play( 0 );
        break;
        case 2: //‹¡¥¥¸â 2
            POW = 17; ACT[0] = 22, ACT[1] = 23, ACT[2] = 22, at[1] = 1; voc_play( 0 );
        break;
        case 3: //‹¡¥¥¸â 3
            POW = 16; ACT[0] = 40, ACT[1] = 41, ACT[2] = 40, at[1] = 1; voc_play( 0 );
        break;
        case 4: //ˆi‰¡Ÿ¡ ¸â
            at[1] = 1; voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 14; ACT[0] = 58, ACT[1] = 59, ACT[2] = 58; break;
                case 2: POW = 20; ACT[0] = 60, ACT[1] = 61, ACT[2] = 60; at[1] = 2; break;
            }
        break;
        case 5: //‹¡¥¥¸â 4
            POW = 15; ACT[0] = 80, ACT[1] = 81, ACT[2] = 80, at[1] = 1; voc_play( 0 );
        break;
        case 6: //‹¡¥¥¸â 5
            at[1] = 1; voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 14; ACT[0] = 103, ACT[1] = 104, ACT[2] = 103; break;
                case 2: POW = 18; ACT[0] = 105, ACT[1] = 106, ACT[2] = 105; at[1] = 2; break;
            }
        break;
        case 7: //‹¡¥¥¸â 6
            at[1] = 1; voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 14; ACT[0] = 128, ACT[1] = 129, ACT[2] = 128; break;
                case 2: POW = 18; ACT[0] = 130, ACT[1] = 131, ACT[2] = 130; at[1] = 2; break;
                case 3: POW = 21; GY = 7, GY2 = 0, next = 0, HIT_TYPE = 2;
                    ACT[0] = 132, ACT[1] = 133, ACT[2] = 132; JUMP = ON;
                    last_act = 2; Ti( 2 ); TI[0] = 6, TI[1] = 4, at[1] = 2, PY2 = PY;
                break;
            }
        break;
        case 8: //´³¬sÐe ¸â
            POW = 10; ACT[0] = 153, ACT[1] = 154, ACT[2] = 153, at[1] = 1; voc_play( 0 );
        break;
        case 9: //¸Çµ· ¸â
            last_act = 3; voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 40; ACT[0] = 172, ACT[1] = 173, ACT[2] = 174, ACT[3] = 175; at[2] = 1; Ti( 4 ); TI[2] = 6; break;
                case 2: POW = 52; ACT[0] = 172, ACT[1] = 176, ACT[2] = 177, ACT[3] = 176; at[2] = 1; Ti( 4 ); TI[2] = 6; break;
            }
        break;
        case 10: //Äi¸“·¡
            voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 25; ACT[0] = 194, ACT[1] = 195, ACT[2] = 194; at[1] = 1; break;
                case 2: POW = 23; ACT[0] = 199, ACT[1] = 200, ACT[2] = 199; at[1] = 2; GX = 10, GX2 = 0; TI[1] = 10; break;
                case 3: POW = 33; GY = 9, GY2 = 0, next = 0, HIT_TYPE = 2, GX = distance%15, GX2 = 0; if ( GX < 2 ) GX = 2;
                    ACT[0] = 199, ACT[1] = 201, ACT[2] = 202, ACT[3] = 203, ACT[4] = 204; JUMP = ON;
                    last_act = 4; Ti( 2 ); TI[1] = 7, TI[2] = 8, at[3] = 2, at[4] = 2, PY2 = PY;
                break;
                case 4: POW = 43; ACT[0] = 196, ACT[1] = 197, ACT[2] = 198; TI[1] = 4, TI[2] = 22; break;
            }
        break;
        case 11: //ˆá·¥
            voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 42; ACT[0] = 224, ACT[1] = 225, ACT[2] = 224; Ti( 4 ), TI[1] = 6; at[1] = 1; break;
                case 3: POW = 50; GX = 8, GX2 = 0, next = 0; voc_play2( 18 );
                    ACT[0] = 220, ACT[1] = 221, ACT[2] = 222, ACT[3] = 221, ACT[4] = 223;
                    last_act = 4; Ti( 3 ); TI[4] = 11; at[0] = 1, at[1] = 1, at[2] = 1, at[3] = 1, at[4] = 2;
                break;
                case 2: POW = 63; GY = 9, GY2 = 0, next = 0, HIT_TYPE = 2;
                    ACT[0] = 219, ACT[1] = 226, ACT[2] = 219; JUMP = ON;
                    last_act = 2; Ti( 2 ); TI[1] = 40, at[1] = 2, PY2 = PY;
                break;
            }
        break;
        case 12: //Ê—Ê—·¡
            voc_play( 0 ); at[1] = 1;
            switch( ATTACK_TYPE )
            {
                case 1: POW = 22; ACT[0] = 240, ACT[1] = 241, ACT[2] = 240; Ti( 4 ), TI[1] = 6; break;
                case 2: POW = 24; ACT[0] = 242, ACT[1] = 243; Ti( 4 ), TI[1] = 8; break;
                case 3: POW = 33; GX = 10, GX2 = 0, next = 0; voc_play2( 18 );
                    ACT[0] = 242, ACT[1] = 243, ACT[2] = 244, ACT[3] = 245, ACT[4] = 246;
                    last_act = 4; Ti( 3 ); at[1] = 2, at[2] = 2, at[3] = 2, at[4] = 2;
                break;
            }
        break;
        case 13: //µa¸a
            switch( ATTACK_TYPE )
            {
                case 1: POW = 22; last_act = 4, ACT[0] = 262, ACT[1] = 263, ACT[2] = 264, ACT[3] = 263, ACT[4] = 262; at[1] = 1; at[3] = 1, Ti( 3 ), TI[1] = 5, TI[3] = 5; break;
                case 2: POW = 24; ACT[0] = 265, ACT[1] = 266, ACT[2] = 265; at[1] = 1; break;
                case 3: POW = 33; GY = 11, GY2 = 0, next = 0, HIT_TYPE = 2;
                    ACT[0] = 267, ACT[1] = 268, ACT[2] = 269, ACT[3] = 270, ACT[4] = 271, ACT[5] = 272, ACT[6] = 273, ACT[7] = 274; JUMP = ON;
                    last_act = 7; Ti( 2 ); TI[4] = 11, TI[7] = 6, at[7] = 2, PY2 = PY;
                break;
            }
        break;
        case 14: //‹¡¥¥¸â 7
            at[1] = 1; voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 15; ACT[0] = 292, ACT[1] = 293, ACT[2] = 292; break;
                case 2: POW = 19; ACT[0] = 296, ACT[1] = 297, ACT[2] = 296; at[1] = 2; break;
                case 3: POW = 22; GY = 7, GY2 = 0, next = 0, HIT_TYPE = 2;
                    ACT[0] = 294, ACT[1] = 295, ACT[2] = 294; JUMP = ON;
                    last_act = 2; Ti( 2 ); TI[0] = 6, TI[1] = 4, at[1] = 2, PY2 = PY;
                break;
            }
        break;
        case 15: //¥¡¯a 1
            voc_play( 0 );
            switch( ATTACK_TYPE )
            {
                case 1: POW = 40; ACT[0] = 328, ACT[1] = 329, ACT[2] = 328, at[1] = 1; break;
                case 2: last_act = 4, POW = 45; ACT[0] = 330, ACT[1] = 331, ACT[2] = 332, ACT[3] = 331, ACT[4] = 330; at[2] = 2, Ti( 2 ), TI[2] = 5; break;
                case 3: POW = 43; GY = 7, GY2 = 0, next = 0, HIT_TYPE = 2;
                    ACT[0] = 333, ACT[1] = 334, ACT[2] = 335, ACT[3] = 337, ACT[4] = 338, ACT[5] = 339, ACT[6] = 338, ACT[7] = 337; JUMP = ON;
                    last_act = 7; Ti( 2 ); TI[1] = 6, at[4] = 2, PY2 = PY;
                break; //¸ñÏa‰·‰b
                case 4: POW = 47; ACT[0] = 340, ACT[1] = 341, ACT[2] = 342, ACT[3] = 343; at[2] = 2; GX = 13, GX2 = 0; TI[0] = 7; break;
            }
            SPECIAL = ON;
        break;
        case 16: //¥¡¯a 2
            switch( ATTACK_TYPE )
            {
                case 1: last_act = 4; POW = 40; ACT[0] = 362, ACT[1] = 363, ACT[2] = 364, ACT[3] = 363, ACT[4] = 362, at[2] = 1; voc_play( 0 ); break;
                case 2: last_act = 10; POW = 45; ACT[0] = 365, ACT[1] = 366, ACT[2] = 367, ACT[3] = 368, ACT[4] = 369, ACT[5] = 370, ACT[6] = 371, ACT[7] = 372, ACT[8] = 373, ACT[9] = 372, ACT[10] = 378;
                        at[2] = 1, at[3] = 1, at[4] = 1, at[5] = 1, at[7] = 2, Ti( 2 ), TI[7] = 5; voc_play( 0 );
                break;
                case 3: POW = 50; GY = 17, GY2 = 0, next = 0, HIT_TYPE = 2; voc_play( 26 );
                    ACT[0] = 378, ACT[1] = 379, ACT[2] = 380, ACT[3] = 381, ACT[4] = 380, ACT[5] = 382; JUMP = ON;
                    last_act = 5; Ti( 2 ); TI[1] = 26, TI[3] = 36, at[3] = 2, PY2 = PY;
                break; //¸ñÏa‰·‰b
                case 4: last_act = 4, POW = 47; ACT[0] = 374, ACT[1] = 375, ACT[2] = 376, ACT[3] = 377, ACT[4] = 378; at[2] = 2; GX = 13, GX2 = 0; Ti( 2 ), TI[2] = 10; voc_play( 0 ); break;
            }
            SPECIAL = ON;
        break;
        case 17: //¥¡¯a 3
            switch( ATTACK_TYPE )
            {
                case 1: last_act = 5; POW = 20; ACT[0] = 406, ACT[1] = 407, ACT[2] = 408, ACT[3] = 409, ACT[4] = 408, ACT[5] = 407, at[3] = 1; Ti( 2 ), voc_play( 0 ); break;
                case 2: last_act = 6; POW = 30; ACT[0] = 410, ACT[1] = 411, ACT[2] = 412, ACT[3] = 413, ACT[4] = 414, ACT[5] = 413, ACT[6] = 415, at[4] = 2; Ti( 2 ), voc_play( 0 ); break;
                case 3: last_act = 2, POW = 32; ACT[0] = 416, ACT[1] = 417, ACT[2] = 416; at[1] = 2; GX = 13, GX2 = 0; Ti( 2 ), TI[1] = 10; voc_play( 0 ); break;
                case 4: last_act = 5, POW = 43; ACT[0] = 418, ACT[1] = 419, ACT[2] = 420, ACT[3] = 421, ACT[4] = 422, ACT[5] = 423; TI[2] = 4, TI[5] = 22; voc_play( 28 ); break;
                case 5: last_act = 2, ACT[0] = 424, ACT[1] = 424, ACT[2] = 424; Ti( 5 ); voc_play( 27 ); break;
            }
            SPECIAL = ON;
        break;
        case 18: //¥¡¯a 4
            switch( ATTACK_TYPE )
            {
                case 1: last_act = 3; POW = 20; ACT[0] = 443, ACT[1] = 444, ACT[2] = 445, ACT[3] = 446, at[2] = 1; Ti( 2 ), voc_play( 0 ); break;
                case 2: last_act = 3; POW = 30; ACT[0] = 447, ACT[1] = 448, ACT[2] = 449, ACT[3] = 450, at[2] = 2; Ti( 2 ), voc_play( 0 ); break;
                case 3: last_act = 4, POW = 40; ACT[0] = 451, ACT[1] = 452, ACT[2] = 453, ACT[3] = 454, ACT[4] = 455; Ti( 2 ), TI[4] = 22; voc_play( 30 ); break;
                case 4: last_act = 3, POW = 40; ACT[0] = 451, ACT[1] = 456, ACT[2] = 457, ACT[3] = 455; TI[3] = 22; voc_play( 30 ); break;
                case 5: last_act = 2, ACT[0] = 459, ACT[1] = 460, ACT[2] = 461; Ti( 5 ); TI[2] = 22; voc_play( 31 ); break;
            }
            SPECIAL = ON;
        break;
        case 19: //¥¡¯a 5
            switch( ATTACK_TYPE )
            {
                case 1: last_act = 2; POW = 30; ACT[0] = 484, ACT[1] = 485, ACT[2] = 484, at[1] = 1; Ti( 2 ), voc_play( 0 ); break;
                case 2: last_act = 4; POW = 35; ACT[0] = 486, ACT[1] = 487, ACT[2] = 488, ACT[3] = 487, ACT[4] = 486, at[2] = 2; Ti( 3 ), voc_play( 0 ); break;
                case 3: last_act = 6, POW = 40; ACT[0] = 489, ACT[1] = 490, ACT[2] = 491, ACT[3] = 492, ACT[4] = 493, ACT[5] = 494, ACT[6] = 495; at[3] = 1, at[4] = 2, Ti( 4 ); voc_play( 0 ); break;
                case 4: last_act = 3, POW = 45; ACT[0] = 496, ACT[1] = 497, ACT[2] = 498, ACT[3] = 499; Ti( 3 ), TI[2] = 22; voc_play( 25 ); break;
            }
            SPECIAL = ON;
        break;
    }
    set_SXSY( 1 ), ATTACK = ON, MOVE = ON;
    if ( TYPE == 18 && ATTACK_TYPE == 2 ) sy[3] = 0;
}

void ENEMY :: jump_create( void )
{
    FLAG = 5, act = 0, TIME = 0, GY = 6, GY2 = 0, next = 0, HIT_TYPE = 2;
    switch( TYPE )
    {
        case 15: //¥¡¯a 1
            ACT[0] = 333, ACT[1] = 334, ACT[2] = 335, ACT[3] = 336, ACT[4] = 335, ACT[5] = 334;
            TI[0] = 1, TI[1] = 11, TI[2] = 2, TI[3] = 2, TI[4] = 15, TI[5] = 1;
            last_act = 5; set_SXSY( 1 );
            sy[3] = 0;
        break;
    }
    JUMP = ON, PY2 = PY;
}

void ENEMY :: stand_create( void )
{
    FLAG = 7, act = 0, TIME = 0, last_act = 7, Ti( 3 ), TI[0] = 6;
    switch( TYPE )
    {
        case 1: //‹¡¥¥¸â 1
            ACT[0] = 11, ACT[1] = 14, ACT[2] = 15, ACT[3] = 16, ACT[4] = 15, ACT[5] = 14, ACT[6] = 15, ACT[7] = 6;
        break;
        case 2: //‹¡¥¥¸â 2
            ACT[0] = 30, ACT[1] = 35, ACT[2] = 34, ACT[3] = 35, ACT[4] = 34, ACT[5] = 35, ACT[6] = 34, ACT[7] = 25;
        break;
        case 3: //‹¡¥¥¸â 3
            ACT[0] = 48, ACT[1] = 52, ACT[2] = 53, ACT[3] = 52, ACT[4] = 53, ACT[5] = 52, ACT[6] = 53, ACT[7] = 43;
        break;
        case 4: //ˆi‰¡Ÿ¡ ¸â
            ACT[0] = 71, ACT[1] = 72, ACT[2] = 73, ACT[3] = 72, ACT[4] = 73, ACT[5] = 72, ACT[6] = 73, ACT[7] = 63;
        break;
        case 5: //‹¡¥¥¸â 4
            last_act = 8; Ti( 3 ), TI[0] = 6;
            ACT[0] = 84, ACT[1] = 85, ACT[2] = 86, ACT[3] = 87, ACT[4] = 88, ACT[5] = 87, ACT[6] = 86, ACT[7] = 87, ACT[8] = 89;
        break;
        case 6: //‹¡¥¥¸â 5
            last_act = 8; Ti( 3 ), TI[0] = 6;
            ACT[0] = 109, ACT[1] = 110, ACT[2] = 111, ACT[3] = 112, ACT[4] = 113, ACT[5] = 112, ACT[6] = 111, ACT[7] = 112, ACT[8] = 114;
        break;
        case 7: //‹¡¥¥¸â 6
            last_act = 8; Ti( 3 ), TI[0] = 6;
            ACT[0] = 136, ACT[1] = 137, ACT[2] = 138, ACT[3] = 139, ACT[4] = 140, ACT[5] = 139, ACT[6] = 138, ACT[7] = 139, ACT[8] = 141;
        break;
        case 8: //´³¬sÐe ¸â
            last_act = 2; Ti( 3 ), TI[0] = 6;
            ACT[0] = 156, ACT[1] = 157, ACT[2] = 158;
        break;
        case 9: //¸Çµ· ¸â
            last_act = 2; Ti( 3 ), TI[0] = 6;
            ACT[0] = 181, ACT[1] = 182, ACT[2] = 183;
        break;
        case 10: //Äi¸“·¡
            last_act = 1; Ti( 3 ), TI[0] = 6;
            ACT[0] = 207, ACT[1] = 199;
        break;
        case 11: //ˆá·¥
            last_act = 1; Ti( 3 ), TI[0] = 6;
            ACT[0] = 229, ACT[1] = 219;
        break;
        case 12: //Ê—Ê—·¡
            last_act = 3; Ti( 3 ), TI[0] = 6;
            ACT[0] = 249, ACT[1] = 250, ACT[2] = 251, ACT[3] = 252;
        break;
        case 13: //µa¸a
            last_act = 1; Ti( 3 ), TI[0] = 6;
            ACT[0] = 279, ACT[1] = 267;
        break;
        case 14: //‹¡¥¥¸â 7
            last_act = 8; Ti( 3 ), TI[0] = 6;
            ACT[0] = 300, ACT[1] = 301, ACT[2] = 302, ACT[3] = 303, ACT[4] = 304, ACT[5] = 303, ACT[6] = 302, ACT[7] = 303, ACT[8] = 305;
        break;
        case 15: //¥¡¯a 1
            last_act = 3; Ti( 3 ), TI[0] = 6;
            ACT[0] = 346, ACT[1] = 347, ACT[2] = 348, ACT[3] = 320;
        break;
        case 16: //¥¡¯a 2
            last_act = 4; Ti( 3 ), TI[0] = 6;
            ACT[0] = 385, ACT[1] = 386, ACT[2] = 387, ACT[3] = 378, ACT[4] = 365;
        break;
        case 17: //¥¡¯a 3
            last_act = 3; Ti( 3 ), TI[0] = 6;
            ACT[0] = 426, ACT[1] = 427, ACT[2] = 428, ACT[3] = 429;
        break;
        case 18: //¥¡¯a 4
            last_act = 4; Ti( 3 ), TI[0] = 6;
            ACT[0] = 469, ACT[1] = 450, ACT[2] = 470, ACT[3] = 471, ACT[4] = 443;
        break;
        case 19: //¥¡¯a 5
            last_act = 3; Ti( 3 ), TI[0] = 6;
            ACT[0] = 505, ACT[1] = 506, ACT[2] = 507, ACT[3] = 508;
        break;
    }
    set_SXSY( 1 );
}

void ENEMY :: damage_create( void )
{
    FLAG = 6, act = 0, TIME = 0; for ( i = 0; i < 30; i++ ) at[i] = 0;
    pyosi = 1;
    if ( SHIELD == ON && TYPE == 9 ) ting( random( EX[ACT[act]] ) + PX, random( (EY[ACT[act]]/2) ) + PY, 3 );
    switch( DAMAGE_TYPE )
    {
        case 1: //¬á¬á x‹¡
            DAMAGE_TIME = 25; last_act = 1, TI[0] = 3, TI[1] = 1, PY2 = PY;
            switch( NA.TYPE )
            {
                case 3: DAMAGE_TIME = 40; break;
            }
            switch( TYPE )
            {
                case 1: //‹¡¥¥¸â 1
                    ACT[0] = 5, ACT[1] = 1;
                break;
                case 2: //‹¡¥¥¸â 2
                    ACT[0] = 24, ACT[1] = 21;
                break;
                case 3: //‹¡¥¥¸â 3
                    ACT[0] = 42, ACT[1] = 38;
                break;
                case 4: //ˆi‰¡Ÿ¡ ¸â
                    ACT[0] = 62, ACT[1] = 56;
                break;
                case 5: //‹¡¥¥¸â 4
                    ACT[0] = 82, ACT[1] = 76;
                break;
                case 6: //‹¡¥¥¸â 5
                    ACT[0] = 107, ACT[1] = 97;
                break;
                case 7: //‹¡¥¥¸â 6
                    ACT[0] = 134, ACT[1] = 124;
                break;
                case 8: //´³¬sÐe ¸â
                    ACT[0] = 152, ACT[1] = 149;
                break;
                case 9: //¸Çµ· ¸â
                    ACT[0] = 178, ACT[1] = 169;
                break;
                case 10: //Äi¸“·¡
                    ACT[0] = 205, ACT[1] = 190;
                break;
                case 11: //ˆá·¥
                    ACT[0] = 227, ACT[1] = 217;
                break;
                case 12: //Ê—Ê—·¡
                    ACT[0] = 247, ACT[1] = 236;
                break;
                case 13: //µa¸a
                    ACT[0] = 277, ACT[1] = 259;
                break;
                case 14: //‹¡¥¥¸â 7
                    ACT[0] = 298, ACT[1] = 288;
                break;
                case 15: //¥¡¯a 1
                    ACT[0] = 344, ACT[1] = 321;
                break;
                case 16: //¥¡¯a 2
                    ACT[0] = 383, ACT[1] = 358;
                break;
                case 17: //¥¡¯a 3
                    ACT[0] = 418, ACT[1] = 394;
                break;
                case 18: //¥¡¯a 4
                    ACT[0] = 458, ACT[1] = 438;
                break;
                case 19: //¥¡¯a 5
                    ACT[0] = 502, ACT[1] = 479;
                break;
            }
        break;
        case 2: case 3: case 5: case 8: //ñ´á»¡‹¡
            switch( DAMAGE_TYPE )
            {
                case 2:
                    next = 0, TI[0] = 4, TI[1] = 19, TI[2] = 10;
                    last_act = 2; GY = 4, GY2 = 0;
                    if ( JUMP == OFF && DAMAGE == OFF ) PY2 = PY;
                break;
                case 3: case 8:
                    next = 0, TI[0] = 4, TI[1] = 19, TI[2] = 10;
                    last_act = 2; GY = 6, GY2 = 0; if ( JUMP == OFF && DAMAGE == OFF ) PY2 = PY;
                break;
                case 5:
                    next = 0, TI[0] = 12, TI[1] = 32, TI[2] = 10;
                    last_act = 2; GY = 9, GY2 = 0;
                    if ( JUMP == OFF && DAMAGE == OFF ) PY2 = PY;
                break;
            }
            switch( TYPE )
            {
                case 1: //‹¡¥¥¸â 1
                    ACT[0] = 9, ACT[1] = 10, ACT[2] = 11;
                break;
                case 2: //‹¡¥¥¸â 2
                    ACT[0] = 28, ACT[1] = 29, ACT[2] = 30;
                break;
                case 3: //‹¡¥¥¸â 3
                    ACT[0] = 46, ACT[1] = 47, ACT[2] = 48;
                break;
                case 4: //ˆi‰¡Ÿ¡ ¸â
                    ACT[0] = 69, ACT[1] = 70, ACT[2] = 71;
                break;
                case 5: //‹¡¥¥¸â 4
                    ACT[0] = 83, ACT[1] = 83, ACT[2] = 84;
                break;
                case 6: //‹¡¥¥¸â 5
                    ACT[0] = 108, ACT[1] = 108, ACT[2] = 109;
                break;
                case 7: //‹¡¥¥¸â 6
                    ACT[0] = 135, ACT[1] = 135, ACT[2] = 136;
                break;
                case 8: //´³¬sÐe ¸â
                    ACT[0] = 155, ACT[1] = 155, ACT[2] = 156;
                break;
                case 9: //¸Çµ· ¸â
                    ACT[0] = 180, ACT[1] = 180, ACT[2] = 181;
                break;
                case 10: //Äi¸“·¡
                    ACT[0] = 206, ACT[1] = 206, ACT[2] = 207;
                break;
                case 11: //ˆá·¥
                    ACT[0] = 228, ACT[1] = 228, ACT[2] = 229;
                break;
                case 12: //Ê—Ê—·¡
                    ACT[0] = 248, ACT[1] = 248, ACT[2] = 249;
                break;
                case 13: //µa¸a
                    ACT[0] = 278, ACT[1] = 278, ACT[2] = 279;
                break;
                case 14: //‹¡¥¥¸â 7
                    ACT[0] = 299, ACT[1] = 299, ACT[2] = 300;
                break;
                case 15: //¥¡¯a 1
                    ACT[0] = 345, ACT[1] = 345, ACT[2] = 346, TI[1] = 10;
                break;
                case 16: //¥¡¯a 2
                    ACT[0] = 384, ACT[1] = 384, ACT[2] = 385;
                break;
                case 17: //¥¡¯a 3
                    ACT[0] = 425, ACT[1] = 425, ACT[2] = 426;
                break;
                case 18: //¥¡¯a 4
                    ACT[0] = 467, ACT[1] = 468, ACT[2] = 469;
                break;
                case 19: //¥¡¯a 5
                    ACT[0] = 503, ACT[1] = 504, ACT[2] = 505;
                break;
            }
        break;
        case 4:   //Ä…µA‰A ”å¹a»¡‹¡
            switch( NA.Dir )
            {
                case 1: Dir2 = 2; Dir = 2; break;
                case 2: Dir2 = 1; Dir = 1; break;
            }
            next = 0; last_act = 6; Ti( 4 ), TI[3] = 6, TI[4] = 7, TI[5] = 7, GY = 4, GY2 = 0, PY2 = PY;
            HIT_TYPE = 2;
            switch( TYPE )
            {
                case 1: //‹¡¥¥¸â 1
                    ACT[0] = 5, ACT[1] = 6, ACT[2] = 7, ACT[3] = 8, ACT[4] = 9, ACT[5] = 10, ACT[6] = 11;
                break;
                case 2: //‹¡¥¥¸â 2
                    ACT[0] = 24, ACT[1] = 25, ACT[2] = 26, ACT[3] = 27, ACT[4] = 28, ACT[5] = 29, ACT[6] = 30;
                break;
                case 3: //‹¡¥¥¸â 3
                    ACT[0] = 42, ACT[1] = 43, ACT[2] = 44, ACT[3] = 45, ACT[4] = 46, ACT[5] = 47, ACT[6] = 48;
                break;
                case 4: //ˆi‰¡Ÿ¡ ¸â
                    ACT[0] = 62, ACT[1] = 63, ACT[2] = 64, ACT[3] = 65, ACT[4] = 69, ACT[5] = 70, ACT[6] = 71;
                break;
                case 5: //‹¡¥¥¸â 4
                    ACT[0] = 82, ACT[1] = 89, ACT[2] = 90, ACT[3] = 91, ACT[4] = 83, ACT[5] = 83, ACT[6] = 84;
                break;
                case 6: //‹¡¥¥¸â 5
                    ACT[0] = 107, ACT[1] = 114, ACT[2] = 115, ACT[3] = 116, ACT[4] = 108, ACT[5] = 108, ACT[6] = 109;
                break;
                case 7: //‹¡¥¥¸â 6
                    ACT[0] = 134, ACT[1] = 141, ACT[2] = 142, ACT[3] = 143, ACT[4] = 135, ACT[5] = 135, ACT[6] = 136;
                break;
                case 8: //´³¬sÐe ¸â
                    ACT[0] = 152, ACT[1] = 158, ACT[2] = 159, ACT[3] = 160, ACT[4] = 155, ACT[5] = 155, ACT[6] = 156;
                break;
                case 9: //¸Çµ· ¸â
                    ACT[0] = 178, ACT[1] = 183, ACT[2] = 184, ACT[3] = 185, ACT[4] = 180, ACT[5] = 180, ACT[6] = 181;
                break;
                case 10: //Äi¸“·¡
                    ACT[0] = 205, ACT[1] = 208, ACT[2] = 209, ACT[3] = 210, ACT[4] = 206, ACT[5] = 206, ACT[6] = 207;
                break;
                case 11: //ˆá·¥
                    ACT[0] = 227, ACT[1] = 227, ACT[2] = 230, ACT[3] = 231, ACT[4] = 228, ACT[5] = 228, ACT[6] = 229;
                break;
                case 12: //Ê—Ê—·¡
                    ACT[0] = 247, ACT[1] = 252, ACT[2] = 253, ACT[3] = 254, ACT[4] = 248, ACT[5] = 248, ACT[6] = 249;
                break;
                case 13: //µa¸a
                    ACT[0] = 277, ACT[1] = 280, ACT[2] = 281, ACT[3] = 282, ACT[4] = 278, ACT[5] = 278, ACT[6] = 279;
                break;
                case 14: //‹¡¥¥¸â 7
                    ACT[0] = 298, ACT[1] = 305, ACT[2] = 306, ACT[3] = 307, ACT[4] = 299, ACT[5] = 299, ACT[6] = 300;
                break;
                case 15: //¥¡¯a 1
                    ACT[0] = 344, ACT[1] = 344, ACT[2] = 349, ACT[3] = 350, ACT[4] = 345, ACT[5] = 345, ACT[6] = 346;
                break;
                case 16: //¥¡¯a 2
                    ACT[0] = 383, ACT[1] = 383, ACT[2] = 388, ACT[3] = 389, ACT[4] = 384, ACT[5] = 384, ACT[6] = 385;
                break;
                case 17: //¥¡¯a 3
                    ACT[0] = 418, ACT[1] = 419, ACT[2] = 430, ACT[3] = 431, ACT[4] = 425, ACT[5] = 425, ACT[6] = 426;
                break;
                case 18: //¥¡¯a 4
                    ACT[0] = 458, ACT[1] = 472, ACT[2] = 472, ACT[3] = 473, ACT[4] = 467, ACT[5] = 468, ACT[6] = 469;
                break;
                case 19: //¥¡¯a 5
                    ACT[0] = 502, ACT[1] = 502, ACT[2] = 509, ACT[3] = 510, ACT[4] = 503, ACT[5] = 504, ACT[6] = 505;
                break;
            }
        break;
        case 6:   //ˆa·©µA‰A ”å¹a»¡‹¡
            switch( NA.Dir )
            {
                case 1: Dir2 = 2; Dir = 2; break;
                case 2: Dir2 = 1; Dir = 1; break;
            }
            next = 0, last_act = 4; Ti( 4 ), TI[1] = 6, TI[3] = 8, GY = 2, GY2 = 0;
            PY2 = PY, HIT_TYPE = 2;
            switch( TYPE )
            {
                case 1: //‹¡¥¥¸â 1
                    ACT[0] = 6, ACT[1] = 17, ACT[2] = 12, ACT[3] = 13, ACT[4] = 11;
                break;
                case 2: //‹¡¥¥¸â 2
                    ACT[0] = 25, ACT[1] = 31, ACT[2] = 32, ACT[3] = 33, ACT[4] = 30;
                break;
                case 3: //‹¡¥¥¸â 3
                    ACT[0] = 42, ACT[1] = 49, ACT[2] = 50, ACT[3] = 51, ACT[4] = 48;
                break;
                case 4: //ˆi‰¡Ÿ¡ ¸â
                    ACT[0] = 62, ACT[1] = 66, ACT[2] = 67, ACT[3] = 68, ACT[4] = 71;
                break;
                case 5: //‹¡¥¥¸â 4
                    ACT[0] = 89, ACT[1] = 92, ACT[2] = 93, ACT[3] = 94, ACT[4] = 84;
                break;
                case 6: //‹¡¥¥¸â 5
                    ACT[0] = 114, ACT[1] = 117, ACT[2] = 118, ACT[3] = 119, ACT[4] = 109;
                break;
                case 7: //‹¡¥¥¸â 6
                    ACT[0] = 141, ACT[1] = 144, ACT[2] = 145, ACT[3] = 146, ACT[4] = 136;
                break;
                case 8: //´³¬sÐe ¸â
                    ACT[0] = 158, ACT[1] = 161, ACT[2] = 162, ACT[3] = 163, ACT[4] = 156;
                break;
                case 9: //¸Çµ· ¸â
                    ACT[0] = 183, ACT[1] = 186, ACT[2] = 187, ACT[3] = 188, ACT[4] = 181;
                break;
                case 10: //Äi¸“·¡
                    ACT[0] = 208, ACT[1] = 211, ACT[2] = 212, ACT[3] = 213, ACT[4] = 207;
                break;
                case 11: //ˆá·¥
                    ACT[0] = 227, ACT[1] = 232, ACT[2] = 233, ACT[3] = 234, ACT[4] = 229;
                break;
                case 12: //Ê—Ê—·¡
                    ACT[0] = 252, ACT[1] = 255, ACT[2] = 256, ACT[3] = 257, ACT[4] = 249;
                break;
                case 13: //µa¸a
                    ACT[0] = 280, ACT[1] = 283, ACT[2] = 284, ACT[3] = 285, ACT[4] = 279;
                break;
                case 14: //‹¡¥¥¸â 7
                    ACT[0] = 305, ACT[1] = 308, ACT[2] = 309, ACT[3] = 310, ACT[4] = 300;
                break;
                case 15: //¥¡¯a 1
                    ACT[0] = 344, ACT[1] = 351, ACT[2] = 352, ACT[3] = 353, ACT[4] = 346;
                break;
                case 16: //¥¡¯a 2
                    ACT[0] = 383, ACT[1] = 390, ACT[2] = 391, ACT[3] = 392, ACT[4] = 385;
                break;
                case 17: //¥¡¯a 3
                    ACT[0] = 418, ACT[1] = 432, ACT[2] = 433, ACT[3] = 434, ACT[4] = 426;
                break;
                case 18: //¥¡¯a 4
                    ACT[0] = 458, ACT[1] = 474, ACT[2] = 475, ACT[3] = 476, ACT[4] = 469;
                break;
                case 19: //¥¡¯a 5
                    ACT[0] = 502, ACT[1] = 511, ACT[2] = 512, ACT[3] = 513, ACT[4] = 505;
                break;
            }
        break;
        case 7:   //·¡µ¡Ÿ¡µA‰A ”å¹a»¡‹¡
            switch( NA.Dir )
            {
                case 1: Dir2 = 2; Dir = 2; break;
                case 2: Dir2 = 1; Dir = 1; break;
            }
            next = 0, last_act = 5; Ti( 4 ), TI[2] = 6, TI[3] = 7, TI[4] = 7, GY = 4, GY2 = 0, PY2 = PY;
            HIT_TYPE = 2;
            switch( TYPE )
            {
                case 1: //‹¡¥¥¸â 1
                    ACT[0] = 5, ACT[1] = 5, ACT[2] = 6, ACT[3] = 9, ACT[4] = 10, ACT[5] = 11;
                break;
                case 2: //‹¡¥¥¸â 2
                    ACT[0] = 24, ACT[1] = 24, ACT[2] = 25, ACT[3] = 28, ACT[4] = 29, ACT[5] = 30;
                break;
                case 3: //‹¡¥¥¸â 3
                    ACT[0] = 43, ACT[1] = 43, ACT[2] = 42, ACT[3] = 46, ACT[4] = 47, ACT[5] = 48;
                break;
                case 4: //ˆi‰¡Ÿ¡ ¸â
                    ACT[0] = 63, ACT[1] = 63, ACT[2] = 62, ACT[3] = 69, ACT[4] = 70, ACT[5] = 71;
                break;
                case 5: //‹¡¥¥¸â 4
                    ACT[0] = 82, ACT[1] = 82, ACT[2] = 89, ACT[3] = 83, ACT[4] = 83, ACT[5] = 84;
                break;
                case 6: //‹¡¥¥¸â 5
                    ACT[0] = 107, ACT[1] = 107, ACT[2] = 114, ACT[3] = 108, ACT[4] = 108, ACT[5] = 109;
                break;
                case 7: //‹¡¥¥¸â 6
                    ACT[0] = 141, ACT[1] = 141, ACT[2] = 135, ACT[3] = 135, ACT[4] = 135, ACT[5] = 136;
                break;
                case 8: //´³¬sÐe ¸â
                    ACT[0] = 158, ACT[1] = 158, ACT[2] = 152, ACT[3] = 155, ACT[4] = 155, ACT[5] = 156;
                break;
                case 9: //¸Çµ· ¸â
                    ACT[0] = 183, ACT[1] = 183, ACT[2] = 178, ACT[3] = 180, ACT[4] = 180, ACT[5] = 181;
                break;
                case 10: //Äi¸“·¡
                    ACT[0] = 208, ACT[1] = 208, ACT[2] = 205, ACT[3] = 206, ACT[4] = 206, ACT[5] = 207;
                break;
                case 11: //ˆá·¥
                    ACT[0] = 227, ACT[1] = 227, ACT[2] = 227, ACT[3] = 228, ACT[4] = 228, ACT[5] = 229;
                break;
                case 12: //Ê—Ê—·¡
                    ACT[0] = 252, ACT[1] = 252, ACT[2] = 247, ACT[3] = 248, ACT[4] = 248, ACT[5] = 249;
                break;
                case 13: //µa¸a
                    ACT[0] = 280, ACT[1] = 280, ACT[2] = 277, ACT[3] = 278, ACT[4] = 278, ACT[5] = 279;
                break;
                case 14: //‹¡¥¥¸â 7
                    ACT[0] = 305, ACT[1] = 305, ACT[2] = 298, ACT[3] = 299, ACT[4] = 299, ACT[5] = 300;
                break;
                case 15: //¥¡¯a 1
                    ACT[0] = 344, ACT[1] = 344, ACT[2] = 344, ACT[3] = 345, ACT[4] = 345, ACT[5] = 346;
                break;
                case 16: //¥¡¯a 2
                    ACT[0] = 383, ACT[1] = 383, ACT[2] = 383, ACT[3] = 384, ACT[4] = 384, ACT[5] = 385;
                break;
                case 17: //¥¡¯a 3
                    ACT[0] = 418, ACT[1] = 418, ACT[2] = 419, ACT[3] = 425, ACT[4] = 425, ACT[5] = 426;
                break;
                case 18: //¥¡¯a 4
                    ACT[0] = 458, ACT[1] = 458, ACT[2] = 472, ACT[3] = 467, ACT[4] = 468, ACT[5] = 469;
                break;
                case 19: //¥¡¯a 5
                    ACT[0] = 502, ACT[1] = 502, ACT[2] = 502, ACT[3] = 503, ACT[4] = 504, ACT[5] = 505;
                break;
            }
        break;
        case 9: //¸â·¡ ¤w´áÐa‹¡
            FLAG = 8, HIT_TYPE = 1;
            switch( TYPE )
            {
                case 9: //¸Çµ· ¸â
                    last_act = 1; Ti( 5 ); TI[1] = 3;
                    ACT[0] = 179, ACT[1] = 179;
                break;
                case 13: //µa¸a
                    last_act = 8; Ti( 3 ); TI[2] = 11, TI[3] = 7, TI[4] = 7, TI[5] = 10, GY = 8, GY2 = 0;
                    ACT[0] = 275, ACT[1] = 276, ACT[2] = 273, ACT[3] = 272, ACT[4] = 271, ACT[5] = 270, ACT[6] = 269, ACT[7] = 268, ACT[8] = 267;
                    PY2 = PY, JUMP = ON;
                break;
            }
        break;
    }
    set_SXSY( 1 ), DAMAGE = ON, MOVE = ON;
}

void ENEMY :: enemy( void )
{
    if ( LIFE == 1 )
    {
        put_sprite( PX + sx[act], PY + sy[act], EX[ACT[act]], EY[ACT[act]], E[ACT[act]], Dir );
    }
}

void ENEMY :: jang_create( void )
{
    JDIR = Dir, JLIFE = 1, JTIME = 0, JCOUNT = 0, JFLAG = 1;
    switch( TYPE )
    {
        case 10:
            switch( JDIR )
            {
                case 1: JX = PX + 100, JY = PY + 10; break;
                case 2: JX = PX - 50, JY = PY + 10; break;
            }
        break;
        case 17:
            switch( JDIR )
            {
                case 1: JX = PX + 100, JY = PY + 20; break;
                case 2: JX = PX - 50, JY = PY + 20; break;
            }
        break;
        case 19:
            switch( JDIR )
            {
                case 1: JX = PX + 100, JY = PY + 50; break;
                case 2: JX = PX - 50, JY = PY + 50; break;
            }
        break;
        case 18:
            switch( ATTACK_TYPE )
            {
                case 3:
                    switch( JDIR )
                    {
                        case 1: JX = PX + 100, JY = PY + 20; break;
                        case 2: JX = PX - 50, JY = PY + 20; break;
                    }
                break;
                case 4:
                    switch( JDIR )
                    {
                        case 1: JX = PX + 100, JY = PY + 60; break;
                        case 2: JX = PX - 50, JY = PY + 60; break;
                    }
                break;
                case 5:
                    switch( JDIR )
                    {
                        case 1: JX = PX + 100, JY = PY - 15; break;
                        case 2: JX = PX - 50, JY = PY - 15; break;
                    }
                break;
            }
        break;
    }
}

void ENEMY :: jang_move( void )
{
    if ( JLIFE == 1 )
    {
        switch( JDIR )
        {
            case 1: JX += 6; break;
            case 2: JX -= 6; break;
        }
        switch( TYPE )
        {
            case 10:
                put_sprite( JX, JY, EX[214], EY[214], E[214], JDIR );
                if ( JCOUNT++ > 22 ) JLIFE = 0;
                if (
                    (JX < NA.DT_X2)
                    && (NA.DT_X1 < JX+EX[214] )
                    && (JY < NA.DT_Y2 )
                    && (NA.DT_Y1 < JY+EY[214])
                    && ( (BADAK_Y < NA.BADAK_Y + 9)
                    && (BADAK_Y > NA.BADAK_Y - 4) )
                    && NA.DAMAGE == OFF && NA.SPECIAL == OFF
                   )
                {
                    NA.DAMAGE_TYPE = 2, NA.ENERGY -= POW;
                    NA.damage_create(); JLIFE = 0, voc_play( 17 );
                    ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
                }
            break;
            case 17:
                switch( JFLAG )
                {
                    case 1: put_sprite( JX, JY, EX[435], EY[435], E[435], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 2; break;
                    case 2: put_sprite( JX, JY, EX[436], EY[436], E[436], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 1; break;
                }
                if ( JCOUNT++ > 22 ) JLIFE = 0;
                if (
                    (JX < NA.DT_X2)
                    && (NA.DT_X1 < JX+EX[435] )
                    && (JY < NA.DT_Y2 )
                    && (NA.DT_Y1 < JY+EY[435])
                    && ( (BADAK_Y < NA.BADAK_Y + 9)
                    && (BADAK_Y > NA.BADAK_Y - 4) )
                    && NA.DAMAGE == OFF && NA.SPECIAL == OFF
                   )
                {
                    NA.DAMAGE_TYPE = 2, NA.ENERGY -= POW;
                    NA.damage_create(); JLIFE = 0, voc_play( 29 );
                    ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
                }
            break;
            case 19:
                switch( JFLAG )
                {
                    case 1: put_sprite( JX, JY, EX[500], EY[500], E[500], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 2; break;
                    case 2: put_sprite( JX, JY, EX[501], EY[501], E[501], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 1; break;
                }
                if ( JCOUNT++ > 22 ) JLIFE = 0;
                if (
                    (JX < NA.DT_X2)
                    && (NA.DT_X1 < JX+EX[500] )
                    && (JY < NA.DT_Y2 )
                    && (NA.DT_Y1 < JY+EY[500])
                    && ( (BADAK_Y < NA.BADAK_Y + 9)
                    && (BADAK_Y > NA.BADAK_Y - 4) )
                    && NA.DAMAGE == OFF && NA.SPECIAL == OFF
                   )
                {
                    NA.DAMAGE_TYPE = 2, NA.ENERGY -= POW;
                    NA.damage_create(); JLIFE = 0, voc_play( 29 );
                    ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
                }
            break;
            case 18:
                switch( ATTACK_TYPE )
                {
                    case 3: case 4:
                        switch( JFLAG )
                        {
                            case 1: put_sprite( JX, JY, EX[465], EY[465], E[465], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 2; break;
                            case 2: put_sprite( JX, JY, EX[466], EY[466], E[466], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 1; break;
                        }
                        if ( JCOUNT++ > 22 ) JLIFE = 0;
                        if (
                            (JX < NA.DT_X2)
                            && (NA.DT_X1 < JX+EX[465] )
                            && (JY < NA.DT_Y2 )
                            && (NA.DT_Y1 < JY+EY[465])
                            && ( (BADAK_Y < NA.BADAK_Y + 9)
                            && (BADAK_Y > NA.BADAK_Y - 4) )
                            && NA.DAMAGE == OFF && NA.SPECIAL == OFF
                           )
                        {
                            NA.DAMAGE_TYPE = 2, NA.ENERGY -= POW;
                            NA.damage_create(); JLIFE = 0, voc_play( 29 );
                            ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
                        }
                    break;
                    case 5:
                        switch( JFLAG )
                        {
                            case 1: put_sprite( JX, JY, EX[462], EY[462], E[462], JDIR ); if ( JTIME++ > 6 ) JTIME = 0, JFLAG = 2; break;
                            case 2: put_sprite( JX, JY, EX[463], EY[463], E[463], JDIR ); if ( JTIME++ > 6 ) JTIME = 0, JFLAG = 3; break;
                            case 3: put_sprite( JX, JY, EX[464], EY[464], E[464], JDIR ); break;
                        }
                        if ( JCOUNT++ > 22 ) JLIFE = 0;
                        if (
                            (JX < NA.DT_X2)
                            && (NA.DT_X1 < JX+EX[464] )
                            && (JY < NA.DT_Y2 )
                            && (NA.DT_Y1 < JY+EY[464])
                            && ( (BADAK_Y < NA.BADAK_Y + 9)
                            && (BADAK_Y > NA.BADAK_Y - 4) )
                            && NA.DAMAGE == OFF && NA.SPECIAL == OFF
                           )
                        {
                            NA.DAMAGE_TYPE = 2, NA.ENERGY -= POW;
                            NA.damage_create(); JLIFE = 0, voc_play( 29 );
                            ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
                        }
                    break;
                }
            break;
        }
    }
}

void ENEMY :: enemy_move( void )
{
    distance = abs( PX - NA.PX );
    //if ( PX < NA.PX ) distance = abs( NA.PX - PX );
    if ( MV == 0 && distance < random( 70 ) + 70 ) MV = 1, s_enemy();
    switch( HIT_TYPE )
    {
        case 1: BADAK_Y = PY + EY[ACT[act]] + sy[act]; break;
        case 2: BADAK_Y = PY2 + SY; break;
    }
    switch( Dir )
    {
        case 1: AT_X1 = PX + (EX[ACT[act]] + sx[act])/2, AT_X2 = PX + EX[ACT[act]] + sx[act], AT_Y1 = PY + sy[act], AT_Y2 = PY + (EY[ACT[act]] + sy[act]);
                DT_X1 = PX + sx[act], DT_X2 = PX + EX[ACT[act]] + sx[act], DT_Y1 = PY + sy[act], DT_Y2 = PY + EY[ACT[act]] + sy[act];
        break;
        case 2: AT_X1 = PX + sx[act], AT_X2 = PX + (EX[ACT[act]] + sx[act])/2, AT_Y1 = PY + sy[act], AT_Y2 = PY + (EY[ACT[act]] + sy[act]);
                DT_X1 = PX + sx[act], DT_X2 = PX + EX[ACT[act]] + sx[act], DT_Y1 = PY + sy[act], DT_Y2 = PY + EY[ACT[act]] + sy[act];
        break;
    }
    if ( MV == 1 )
    {
        if ( JUMP == OFF && DAMAGE == OFF && ATTACK == OFF && THROW == OFF )
        {
            if ( PX < NA.PX ) Dir = 1;
            if ( PX > NA.PX ) Dir = 2;
        }
        enemy_dead( 1 );
        if ( FLAG != 1 && MOVE == OFF && DAMAGE == OFF ) s_enemy();
        if ( DAMAGE_TIME > 0 ) DAMAGE_TIME--;
        if ( (NA.ATTACK == ON || NA.SPECIAL == ON) && (random( 4 ) + 1) == 1 && NA.THROW == OFF && TYPE == 9 && ATTACK == OFF ) SHIELD = ON;
        if ( (NA.ATTACK == ON || NA.SPECIAL == ON) && (random( 14 ) + 1) == 1 && NA.THROW == OFF && TYPE == 13 && ATTACK == OFF ) SHIELD = ON;
        if ( MOVE == OFF && DAMAGE_TIME == 0 )
        {
            switch( TYPE )
            {
                case 1: case 4: case 10: //‹¡¥¥¸â 1, ˆi‰¡Ÿ¡ ¸â, Äi¸s·¡
                    RANDOM = random( 15 ) + 1;
                    if ( RANDOM == 1 && Dir == 2 ) SUN = 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 1 && Dir == 1 ) SUN = 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = 2, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 1 ) SUN = 4, walk_create(), COUNT = random( 30 ) + 30;
                    if ( NA.FLAG != 8 )
                    {
                        if ( distance < 80 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 1 && ATTACK == OFF ) ATTACK_WAIT = 0, punch_create();
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 4 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 13 && TYPE == 10 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 1, punch_create();
                        if ( distance < 140 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 10 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 2, punch_create();
                        if ( distance < 150 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 17 && TYPE == 10 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 4, punch_create();
                        if ( distance > 180 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 17 && TYPE == 10 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                    }
                break;
                case 2: case 3: case 14: //‹¡¥¥¸â 2, ‹¡¥¥¸â 3, ‹¡¥¥¸â 7
                    RANDOM = random( 25 ) + 1;
                    if ( RANDOM == 1 && Dir == 2 ) SUN = 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 1 && Dir == 1 ) SUN = 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = 2, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 1 ) SUN = 4, walk_create(), COUNT = random( 30 ) + 30;
                    if ( NA.FLAG != 8 )
                    {
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 2 && ATTACK == OFF ) ATTACK_WAIT = 0, punch_create();
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 3 && ATTACK == OFF ) ATTACK_WAIT = 0, punch_create();
                        if ( distance < 100 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 14 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 3 ) + 1, punch_create();
                    }
                break;
                case 5: case 6: case 7: case 11: case 12: //‹¡¥¥¸â 4, ‹¡¥¥¸â 5, ‹¡¥¥¸â 6, ˆá·¥, Ê—Ê—·¡
                    RANDOM = random( 25 ) + 1;
                    if ( RANDOM == 1 && Dir == 2 ) SUN = random( 2 ) + 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = random( 2 ) + 3, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 3 && Dir == 1 ) SUN = random( 2 ) + 7, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 4 && Dir == 1 ) SUN = random( 2 ) + 9, walk_create(), COUNT = random( 30 ) + 30;
                    if ( NA.FLAG != 8 )
                    {
                        if ( distance < 40 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 14 && TYPE == 5 && ATTACK == OFF ) ATTACK_WAIT = 0, punch_create();
                        if ( distance < 50 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 13 && TYPE == 6 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 60 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 14 && TYPE == 7 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 3 ) + 1, punch_create();
                        if ( distance < 98 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 13 && TYPE == 11 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance > 170 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 14 && TYPE == 11 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance < 98 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 12 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance > 170 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 15 && TYPE == 12 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                    }
                break;
                case 8: //´³¬sÐe ¸â
                    RANDOM = random( 30 ) + 1;
                    if ( Dir == 2 && NA.Dir == 2 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 ) SUN = 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( Dir == 1 && NA.Dir == 1 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 ) SUN = 3, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = 5, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 1 ) SUN = 6, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 1 && Dir == 2 ) SUN = 7, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 1 && Dir == 1 ) SUN = 7, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = 8, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 1 ) SUN = 10, walk_create(), COUNT = random( 30 ) + 30;
                    if ( NA.FLAG != 8 )
                    {
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 2 && TYPE == 8 && ATTACK == OFF ) ATTACK_WAIT = 0, punch_create();
                    }
                break;
                case 9: case 13: case 15: case 16: case 17: case 18: case 19: // ¸Çµ· ¸â, µa¸a, ¥¡¯a 1, ¥¡¯a 2, ¥¡¯a 3, ¥¡¯a 4, ¥¡¯a 5
                    RANDOM = random( 5 ) + 1;
                    if ( RANDOM == 1 && Dir == 2 ) SUN = random( 2 ) + 1, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 2 && Dir == 2 ) SUN = random( 2 ) + 3, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 3 && Dir == 1 ) SUN = random( 2 ) + 7, walk_create(), COUNT = random( 30 ) + 30;
                    if ( RANDOM == 4 && Dir == 1 ) SUN = random( 2 ) + 9, walk_create(), COUNT = random( 30 ) + 30;
                    if ( NA.FLAG != 8 )
                    {
                        if ( distance < 110 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 12 && TYPE == 9 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 90 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 12 && TYPE == 13 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 180 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 12 && TYPE == 13 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance < 120 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 15 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 144 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 15 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance > 170 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 15 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 4, punch_create();
                        if ( distance < 130 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 16 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 164 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 16 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 4, punch_create();
                        if ( distance > 190 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 16 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance < 150 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 17 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance < 190 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 17 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 221 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 17 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 4, punch_create();
                        if ( distance > 230 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 17 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 5, punch_create();
                        if ( distance < 100 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 18 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 191 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 18 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 3, punch_create();
                        if ( distance > 192 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 18 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 5, punch_create();
                        if ( distance < 100 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 19 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = random( 2 ) + 1, punch_create();
                        if ( distance < 190 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 19 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 3, punch_create();
                        if ( distance > 192 && NA.BADAK_Y > BADAK_Y - 4 && NA.BADAK_Y < BADAK_Y + 9 && ATTACK_WAIT++ > 1 && TYPE == 19 && ATTACK == OFF ) ATTACK_WAIT = 0, ATTACK_TYPE = 4, punch_create();
                    }
                break;
            }
        }
    }
}

void ENEMY :: enemy_churi( void )
{
    if ( PYOSI == 0 && pyosi == 1 && PYOSI_T++ > 5 ) PYOSI = 1, pyosi = 0, PYOSI_T = 0;
    if ( PYOSI == 1 )
    {
        EN_TYPE = TYPE, EN_PYOSI_TIME = 0, PYOSI2 = 1, EN1_MAX = EN_MAX, EN2_MAX = ENERGY;
        PYOSI = 0, EN_COUNT = en_count;
    }
    if ( SCROLL == ON && (NA.DASH == ON || NA.DASH == 2) ) PX -= 4; else if ( SCROLL == ON && NA.DASH == OFF ) PX -= 3;
    if ( MV == 1 )
    {
        if ( PX + EX[ACT[act]] + sx[act] < -21 ) PX = -21 - EX[ACT[act]] + sx[act];
        if ( PX + sx[act] > 381 ) PX = 381 - sx[act];
        if ( PY + SY < 191 && JUMP == OFF && SPECIAL == OFF && DAMAGE == OFF && THROW == OFF && ATTACK == OFF ) PY = 191 - SY;
        if ( PY + EY[ACT[act]] + sy[act] > 254 ) PY = 254 - EY[ACT[act]] - sy[act];
    }
    if ( BOSS == 1 && ENERGY <= 0 ) FRAME( 25 );
    switch( FLAG )
    {
        case 1: act_churi( 1 ); break;
        case 2:   //ˆè‹¡
            act_churi( 1 );
            switch( TYPE )
            {
                case 1: case 4: case 10: //‹¡¥¥¸â 1, ˆi‰¡Ÿ¡ ¸â, Äi¸“·¡
                    switch( SUN )
                    {
                        case 1: PX += 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX -= 3; PY-=2; if ( PX < NA.PX || PY + SY < 215 ) SUN = 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX -= 3; PY+=2; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PX += 3; PY-=2; if ( PX > NA.PX || PY + SY < 215 ) SUN = 5; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX += 3; PY+=2; if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 2: //‹¡¥¥¸â 2
                    switch( SUN )
                    {
                        case 1: PX += 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX -= 3; PY--; if ( PX < NA.PX || PY + SY < 215 ) SUN = 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX -= 3; PY++; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PX += 3; PY--; if ( PX > NA.PX || PY + SY < 215 ) SUN = 5; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX += 3; PY++; if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 3: case 14: //‹¡¥¥¸â 3, ‹¡¥¥¸â 7
                    switch( SUN )
                    {
                        case 1: PX += 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX -= 3; PY--; if ( PX < NA.PX || PY + SY < 215 ) SUN = 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PY++; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PY--; if ( PX > NA.PX || PY + SY < 215 ) SUN = 5; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX += 3; PY++; if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 5: case 6: case 7: case 11: case 12: //‹¡¥¥¸â 4, ‹¡¥¥¸â 5, ‹¡¥¥¸â 6, ˆá·¥, Ê—Ê—·¡
                    switch( SUN )
                    {
                        case 1: PX -= 3; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX += 2; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX -= 3; PY-= 2; if ( PY + SY < 191 || PX < NA.PX ) SUN = 5, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PX -= 3; PY+= 2; if ( PY + SY > 254 ) SUN = 6, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX -= 3, PY+= 2; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 6: PX -= 3, PY-= 2; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 7: PX += 3; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 8: PX-= 2; if ( COUNT-- < 0 ) at_off(); break;
                        case 9: PX += 3; PY-= 2; if ( PY + SY < 191 || PX > NA.PX ) SUN = 11, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 10: PX += 3; PY+= 2; if ( PY + SY > 254 || PX > NA.PX ) SUN = 12, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 11: PX += 3, PY-= 2; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 12: PX += 3, PY+= 2; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 8: //´³¬sÐe ¸â
                    switch( SUN )
                    {
                        case 1: PX -= 5; if ( PX < NA.PX + 30 ) COUNT = random( 30 ) + 30, punch_create(); if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX += 5; if ( PX + SX > NA.PX ) COUNT = random( 30 ) + 30, punch_create(); if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PY++; if ( COUNT-- < 0 ) at_off(); break;
                        case 6: PY--; if ( COUNT-- < 0 ) at_off(); break;
                        case 7: PX += 3; if ( COUNT-- < 0 ) at_off(); break;
                        case 8: PX -= 3; PY-=2; if ( PX < NA.PX || PY + SY < 215 ) SUN = 9; if ( COUNT-- < 0 ) at_off(); break;
                        case 9: PX -= 3; PY+=2; if ( COUNT-- < 0 ) at_off(); break;
                        case 10: PX += 3; PY-=2; if ( PX > NA.PX || PY + SY < 215 ) SUN = 11; if ( COUNT-- < 0 ) at_off(); break;
                        case 11: PX += 3; PY+=2; if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 9: case 17: case 18: case 19: //¸Çµ· ¸â, ¥¡¯a 3, ¥¡¯a 4, ¥¡¯a 5
                    switch( SUN )
                    {
                        case 1: PX -= 2; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX++; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX -= 2; PY--; if ( PY + SY < 191 || PX < NA.PX ) SUN = 5, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PX -= 2; PY++; if ( PY + SY > 254 ) SUN = 6, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX -= 2, PY++; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 6: PX -= 2, PY--; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;

                        case 7: PX += 2; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 8: PX--; if ( COUNT-- < 0 ) at_off(); break;
                        case 9: PX += 2; PY--; if ( PY + SY < 191 || PX > NA.PX ) SUN = 11, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 10: PX += 2; PY++; if ( PY + SY > 254 || PX > NA.PX ) SUN = 12, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 11: PX += 2, PY--; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 12: PX += 2, PY++; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
                case 13: case 15: case 16: //µa¸a, ¥¡¯a 1, ¥¡¯a 2
                    switch( SUN )
                    {
                        case 1: PX -= 4; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 2: PX+= 4; if ( COUNT-- < 0 ) at_off(); break;
                        case 3: PX -= 4; PY-= 2; if ( PY + SY < 191 || PX < NA.PX ) SUN = 5, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 4: PX -= 4; PY+= 2; if ( PY + SY > 254 ) SUN = 6, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 5: PX -= 4, PY+= 2; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 6: PX -= 4, PY-= 2; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;

                        case 7: PX += 4; if ( PX < NA.PX + NA.SX ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 8: PX-= 4; if ( COUNT-- < 0 ) at_off(); break;
                        case 9: PX += 4; PY-= 2; if ( PY + SY < 191 || PX > NA.PX ) SUN = 11, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 10: PX += 4; PY+=2; if ( PY + SY > 254 || PX > NA.PX ) SUN = 12, COUNT = random( 30 ) + 30; if ( COUNT-- < 0 ) at_off(); break;
                        case 11: PX += 4, PY-=2; if ( PY > NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                        case 12: PX += 4, PY+=2; if ( PY < NA.PY ) at_off(); if ( COUNT-- < 0 ) at_off(); break;
                    }
                break;
            }
        break;
        case 3: //‰·‰b
            switch( TYPE )
            {
                case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9:
                    if ( TIME++ > TI[act] ) TIME = 0, act++;
                    if ( act > last_act ) act = last_act, at_off();
                break;
                case 7: case 14:
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; switch( Dir ) { case 1: PX += 2; break; case 2: PX -= 2; break; }
                            act_churi( 2 ); if ( PY > PY2 ) PY = PY2, at_off();
                        break;
                    }
                break;
                case 10: //Äi¸s·¡
                    switch( ATTACK_TYPE )
                    {
                        case 1: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 2: if ( act > 0 ) { if ( GX2++ > 0 ) GX2 = 0, GX--; switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; } }
                            act_churi( 2 ); if ( GX <= 0 ) at_off();
                        break;
                        case 3: if ( act > 0 )
                                {
                                    PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; if ( TIME == 0 ) GX2++;
                                    if ( GX2 < 11 ) { switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; } }
                                }
                                act_churi( 0 ); if ( PY > PY2 ) PY = PY2, at_off();
                                if ( act > 4 ) act = 3;
                        break;
                        case 4:
                            act_churi( 0 );
                            if ( act == 2 && TIME == 0 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                        break;
                    }
                break;
                case 11: //ˆá·¥
                    switch( ATTACK_TYPE )
                    {
                        case 1: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: if ( GX2++ > 3 ) GX--, GX2 = 0; switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; }
                                if ( GX < 0 ) GX = 0;
                                act_churi( 0 ); if ( act > 3 && next++ < 1 ) act = 0;
                                if ( act > last_act ) at_off();
                        break;
                        case 2: if ( act > 0 )
                                {
                                    PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--;
                                    switch( Dir ) { case 1: PX += 3; break; case 2: PX -= 3; break; }
                                }
                                act_churi( 2 );
                                if ( PY > PY2 )
                                {
                                    switch( next )
                                    {
                                        case 0: voc_play( 11 ), next = 1; GY = 3; GY2 = 0; break;
                                        case 1: at_off(); break;
                                    }
                                    PY = PY2;
                                }
                        break;
                    }
                break;
                case 12: //Ê—Ê—·¡
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: if ( act > 0 ) { if ( GX2++ > 3 ) GX--, GX2 = 0; switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; } }
                                if ( GX < 0 ) GX = 0;
                                act_churi( 0 ); if ( act > 3 && next++ < 1 ) act = 1;
                                if ( act > last_act ) at_off();
                        break;
                    }
                break;
                case 13: //µa¸a
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3:
                            switch( Dir ) { case 1: PX += 2; break; case 2: PX -= 2; break; }
                            if ( act > 3 )
                            {
                                PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--;
                            }
                            act_churi( 2 ); if ( PY > PY2 ) PY = PY2, at_off();
                        break;
                    }
                break;
                case 15: //¥¡¯a 1
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; switch( Dir ) { case 1: PX += 4; break; case 2: PX -= 4; break; }
                            act_churi( 2 ); if ( PY > PY2 ) PY = PY2, at_off();
                        break;
                        case 4: if ( GX2++ > 0 ) GX2 = 0, GX--; switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; }
                            act_churi( 2 ); if ( GX <= 0 ) at_off();
                        break;
                    }
                break;
                case 16: //¥¡¯a 2
                    switch( ATTACK_TYPE )
                    {
                        case 1: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); if ( act < 6 ) { switch( Dir ) { case 1: PX += 5; break; case 2: PX -= 5; break; } } break;
                        case 3: if ( act > 0 ) { PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; } if ( act == 2 && TIME == 0 ) PX = NA.PX;
                            act_churi( 2 ); if ( PY > PY2 ) PY = PY2, at_off();
                        break;
                        case 4: if ( GX2++ > 0 ) GX2 = 0, GX--; if ( act == 2 ) { switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; } }
                            act_churi( 2 ); if ( GX <= 0 ) at_off();
                        break;
                    }
                break;
                case 17: //¥¡¯a 3
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: if ( GX2++ > 0 ) GX2 = 0, GX--; if ( act == 1 ) { switch( Dir ) { case 1: PX += GX; break; case 2: PX -= GX; break; } }
                            act_churi( 2 ); if ( GX <= 0 ) at_off();
                        break;
                        case 4:
                            act_churi( 0 );
                            if ( act == 4 && TIME == 0 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 5:
                            act_churi( 0 );
                            if ( act == 1 && TIME == 0 ) PX = random( 360 ), PY = random( 70 ) + 151; if ( act > last_act ) act = last_act, at_off();
                        break;
                    }
                break;
                case 18: //¥¡¯a 4
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: case 4:
                            act_churi( 0 );
                            if ( act == 3 && TIME == 0 && ATTACK_TYPE == 3 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                            if ( act == 2 && TIME == 0 && ATTACK_TYPE == 4 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 5:
                            act_churi( 0 );
                            if ( act == 2 && TIME == 0 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                        break;
                    }
                break;
                case 19: //¥¡¯a 5
                    switch( ATTACK_TYPE )
                    {
                        case 1: case 2: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off(); break;
                        case 3: act_churi( 0 ); if ( act > last_act ) act = last_act, at_off();
                            switch( Dir ) { case 1: PX += 4; break; case 2: PX -= 4; break; }
                        break;
                        case 4:
                            act_churi( 0 );
                            if ( act == 2 && TIME == 0 ) jang_create(); if ( act > last_act ) act = last_act, at_off();
                        break;
                    }
                break;
            }
        break;
        case 5: //¸ñÏa
            if ( act > 0 ) { PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--; }
            switch( Dir ) { case 1: PX -= 4; break; case 2: PX += 4; break; }
            act_churi( 2 );
            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
        break;
        case 6:  // x‹¡
            switch( DAMAGE_TYPE )
            {
                case 1:  //¬á¬á x‹¡
                    if ( TIME++ > TI[act] ) TIME = 0, act++;
                    if ( act >= last_act ) at_off();
                    if ( (NA.SPECIAL_TYPE == 2 || NA.SPECIAL_TYPE == 4) && NA.TYPE == 1 ) { switch( Dir ) { case 1: PX -= 3; break; case 2: PX += 3; break; } }
                break;
                case 2: case 3: case 5: //ñ´á»¡‹¡
                    act_churi( 2 );
                    PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--;
                    if ( next == 1 ) ting( random( EX[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                    if ( PY > PY2 )
                    {
                        switch( next )
                        {
                            case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; break;
                            case 1: stand_create(); enemy_dead( 2 ); break;
                        }
                        PY = PY2;
                    }
                    if ( DAMAGE_TYPE == 2 ) { switch( Dir ) { case 1: PX -= 3; break; case 2: PX += 3; break; } }
                    if ( DAMAGE_TYPE == 3 ) { switch( Dir ) { case 1: PX -= 6; break; case 2: PX += 6; break; } }
                    if ( DAMAGE_TYPE == 5 ) { switch( Dir ) { case 1: PX--; break; case 2: PX++; break; } }
                break;
                case 4: //Ä…µA‰A ”å¹a»¡‹¡
                    act_churi( 2 );
                    if ( TIME == 0 && act == 0 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX - (SX/2); break;
                            case 2: PX = NA.PX + (SX/2); break;
                        }
                    }
                    if ( TIME == 0 && act == 1 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX - (SX/2); PY = NA.PY - 10; break;
                            case 2: PX = NA.PX + (SX/2); PY = NA.PY - 10; break;
                        }
                    }
                    if ( TIME == 0 && act == 2 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX - (SX/2); PY = NA.PY - 45; break;
                            case 2: PX = NA.PX + (SX/2); PY = NA.PY - 45; break;
                        }
                    }
                    if ( TIME == 0 && act == 3 )
                    {
                        THROW = ON;
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX + (SX/3); PY = NA.PY - 65; break;
                            case 2: PX = NA.PX - (SX/3); PY = NA.PY - 65; break;
                        }
                    }
                    if ( act > 3 ) { PY -= GY; if ( GY2++ > 0 ) GY2 = 0, GY--; }
                    if ( next == 1 ) ting( random( EX[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                    if ( PY > PY2 && act > 3 )
                    {
                        switch( next )
                        {
                            case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; THROW = OFF; ENERGY -= 29; break;
                            case 1: stand_create(); enemy_dead( 2 ); break;
                        }
                        PY = PY2, pyosi = 1;
                    }
                    if ( act > 3 ) { switch( Dir ) { case 1: PX += 4; break; case 2: PX -= 4; break; } }
                break;
                case 6: //ˆa·©µA‰A ”å¹a»¡‹¡
                    act_churi( 2 );
                    if ( (TIME == 0 || TIME == 1) && act == 0 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX + (SX/2); break;
                            case 2: PX = NA.PX + (SX/4); break;
                        }
                    }
                    if ( TIME == 0 && act == 1 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX - (SX/3); PY = NA.PY - 40; break;
                            case 2: PX = NA.PX + (SX/3); PY = NA.PY - 40; break;
                        }
                    }
                    if ( TIME == 0 && act == 2 )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX + (SX/3); PY = NA.PY - 50; break;
                            case 2: PX = NA.PX + (SX/3); PY = NA.PY - 50; break;
                        }
                    }
                    if ( TIME == 0 && act == 3 )
                    {
                        THROW = ON, voc_play( 11 );
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX + SX; PY = NA.PY; break;
                            case 2: PX = NA.PX - SX; PY = NA.PY; break;
                        }
                    }
                    if ( act > 3 ) { THROW = OFF; PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--; }
                    if ( next == 1 ) ting( random( EX[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                    if ( PY > PY2 && act > 3 )
                    {
                        switch( next )
                        {
                            case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; ENERGY -= 33; break;
                            case 1: stand_create(); enemy_dead( 2 ); break;
                        }
                        PY = PY2, pyosi = 1;
                    }
                    if ( act > 3 ) { switch( Dir ) { case 1: PX += 4; break; case 2: PX -= 4; break; } }
                break;
                case 7: //·¡µ¡Ÿ¡µA‰A ”å¹a»¡‹¡
                    act_churi( 2 );
                    if ( TIME == 0 && (act == 0 || act == 1 || act == 2) )
                    {
                        switch( Dir2 )
                        {
                            case 1: PX = NA.PX - (SX/2); break;
                            case 2: PX = NA.PX + (SX/2); break;
                        }
                    }
                    if ( act == 2 && TIME == 0 ) THROW = ON;
                    if ( act > 2 ) { PY -= GY; if ( GY2++ > 0 ) GY2 = 0, GY--; }
                    if ( next == 1 ) ting( random( EX[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                    if ( PY > PY2 && act > 2 )
                    {
                       switch( next )
                       {
                            case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; THROW = OFF; ENERGY -= 25; break;
                            case 1: stand_create(); enemy_dead( 2 ); break;
                       }
                       PY = PY2, pyosi = 1;
                    }
                    if ( act > 2 ) { switch( Dir ) { case 1: PX -= 4; break; case 2: PX += 4; break; } }
                break;
                case 8: //º‚´áñ´á»¡‹¡
                    act_churi( 2 );
                    PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--;
                    if ( next == 1 ) ting( random( EX[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                    if ( PY > PY2 )
                    {
                        switch( next )
                        {
                            case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; break;
                            case 1: stand_create(); DEAD_F = 1, DEAD_TIME = 0, LIFE = 2, DEAD_C = 0; break;
                        }
                        PY = PY2;
                    }
                    switch( Dir ) { case 1: PX -= 6; break; case 2: PX += 6; break; }
                break;
            }
        break;
        case 7:   //·©´á¬á‹¡
            act_churi( 0 );
            if ( act > last_act )
            {
                at_off();
                if ( distance < 170 && TYPE == 15 ) ATTACK_TYPE = 2, punch_create();
                if ( distance < 170 && TYPE == 16 ) ATTACK_TYPE = 4, punch_create();
                if ( distance < 170 && TYPE == 17 ) ATTACK_TYPE = 4, punch_create();
                if ( distance < 170 && TYPE == 18 ) ATTACK_TYPE = 5, punch_create();
                if ( distance < 170 && TYPE == 19 ) ATTACK_TYPE = 4, punch_create();
            }
        break;
        case 8:   // b‹¡
            switch( TYPE )
            {
                case 9: //¸Çµ· ¸â
                    act_churi( 0 );
                    if ( act > last_act ) at_off();
                    switch( Dir ) { case 1: PX -= 2; break; case 2: PX += 2; break; }
                break;
                case 13: //µa¸a
                    SHIELD = OFF;
                    act_churi( 0 ); if ( act == 2 || act == 3 || act == 4 || act == 5 ) { PY -= GY; if ( GY2++ > 0 ) GY--, GY2 = 0; }
                    switch( Dir ) { case 1: PX -= 4; break; case 2: PX += 4; break; }
                    if ( PY > PY2 ) PY = PY2; if ( act > last_act ) at_off();
                break;
            }
        break;
    }
}

void ENEMY :: enemy_dead( int t )
{
    switch( t )
    {
        case 1:
            if ( ENERGY <= 0 && (FLAG == 1 || FLAG == 2) && en_count == 0 )
            {
                DAMAGE_TYPE = 8, damage_create();
                if ( BOSS == 1 ) { for ( i2 = 0; i2 < 29; i2++ ) EN[i2].ENERGY = 0; voc_play( 16 ), CLEAR = 1, CLEAR_TIME = 0; }
                switch( TYPE )
                {
                    case 13: voc_play( 19 ); break;
                    default: case 14:
                        voc_play( random( 4 ) + 13 );
                    break;
                    case 15: case 18: case 19: voc_play( 15 ); break;
                    case 16: voc_play( 16 ); break;
                }
            } else if ( ENERGY <= 0 && en_count > 0 ) en_count--, ENERGY = 287, EN_MAX = ENERGY;
        break;
        case 2:
            if ( ENERGY <= 0 && FLAG != 1 && FLAG != 2 && LIFE == 1 && en_count == 0 )
            {
                LIFE = 2, DEAD_TIME = 0, DEAD_C = 0, DEAD_F = 1;
                if ( BOSS == 1 ) { for ( i2 = 0; i2 < 29; i2++ ) EN[i2].ENERGY = 0; voc_play( 16 ), CLEAR = 1, CLEAR_TIME = 0; }
                switch( TYPE )
                {
                    case 13: voc_play( 19 ); break;
                    default: case 14:
                        voc_play( random( 4 ) + 13 );
                    break;
                    case 15: case 18: case 19: voc_play( 15 ); break;
                    case 16: voc_play( 16 ); break;
                }
            } else if ( ENERGY <= 0 && en_count > 0 ) en_count--, ENERGY = 287, EN_MAX = ENERGY;
        break;
    }
}

void ENEMY :: enemy_dead2( void )
{
    if ( SCROLL == ON && (NA.DASH == ON || NA.DASH == 2) ) PX -= 4; else if ( SCROLL == ON && NA.DASH == OFF ) PX -= 3;
    switch( DEAD_F )
    {
        case 1:
            switch( Dir )
            {
                case 1: put_sprite( PX, PY + SY - EY[DEAD_FLAG], EX[DEAD_FLAG], EY[DEAD_FLAG], E[DEAD_FLAG], Dir ); break;
                case 2: put_sprite( PX + SX - EX[DEAD_FLAG], PY + SY - EY[DEAD_FLAG], EX[DEAD_FLAG], EY[DEAD_FLAG], E[DEAD_FLAG], Dir ); break;
            }
        break;
    }
    if ( DEAD_TIME++ > 0 ) { DEAD_TIME = 0; if ( DEAD_F == 1 ) DEAD_F = 2; else DEAD_F = 1; DEAD_C++; }
    if ( DEAD_C > 20 ) LIFE = 0;
}
