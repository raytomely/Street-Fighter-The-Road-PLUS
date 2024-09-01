//"ENEMY2.C" ¸â —i· ¬—¬÷ Ðq®
#include "value.h"
#include "extern.h"

void enemy_init1( void )
{
    switch( ROUND2 )
    {
        case 1:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 371, 140, 5, 55, 0, 2, 1 );
                //case 0: EN[0].init_enemy( 341, 140, 19, 55, 0, 1, 2 );
                        IT[0].item_create( 441, 64, 1, random( 3 ) + 3 );
                break;
                case 1: EN[1].init_enemy( 391, 140, 2, 75, 1, 1, 1 );
                        EN[2].init_enemy( -100, 130, 1, 78, 1, 1, 1 );
                        EN[3].init_enemy( 420, 90, 9, 102, 0, 1, 2 );
                        IT[1].item_create( 371, 145, 6, 4 );
                        IT[2].item_create( 420, 180, 6, random( 4 ) + 1 );
                break;
                case 2: EN[4].init_enemy( 391, 140, 4, 75, 1, 1, 1 );
                        EN[5].init_enemy( -100, 130, 3, 73, 1, 1, 1 );
                        EN[6].init_enemy( 390, 90, 1, 82, 1, 1, 2 );
                break;
                case 3: EN[7].init_enemy( 391, 140, 2, 102, 1, 1, 1 );
                        EN[8].init_enemy( -100, 130, 4, 89, 1, 1, 1 );
                        EN[9].init_enemy( 390, 90, 6, 82, 1, 1, 2 );
                break;
            }
        break;
        case 2:
            switch( s_flag )
            {
                case 1: EN[0].init_enemy( 391, 140, 6, 85, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, 7, 83, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 8, 90, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 1, 87, 1, 1, 2 );
                break;
                case 2: EN[4].init_enemy( 391, 140, 6, 85, 1, 2, 2 );
                        EN[5].init_enemy( -100, 130, 2, 73, 1, 1, 1 );
                        EN[6].init_enemy( 390, 90, 3, 82, 1, 1, 2 );
                        IT[1].item_create( 371, 155, 6, random( 5 ) + 11 );
                break;
                case 3: EN[7].init_enemy( 391, 140, 10, 122, 1, 1, 1 );
                        EN[8].init_enemy( -100, 130, 12, 132, 1, 1, 1 );
                        EN[9].init_enemy( 380, 90, 7, 82, 1, 1, 2 );
                break;
            }
        break;
        case 3:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 1, 85, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, 2, 83, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 3, 90, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 4, 87, 1, 1, 2 );
                        IT[1].item_create( 371, 145, 6, random( 6 ) + 1 );
                        IT[2].item_create( 420, 180, 6, random( 9 ) + 7 );
                break;
                case 1: EN[4].init_enemy( 391, 140, 5, 85, 1, 1, 1 );
                        EN[5].init_enemy( -100, 130, 6, 73, 1, 1, 1 );
                        EN[6].init_enemy( 380, 90, 7, 82, 1, 1, 2 );
                        EN[7].init_enemy( -100, 90, 8, 82, 1, 1, 2 );
                        EN[29].init_enemy( 621, 120, 15, 735, 0, 1, 2 ), EN[29].BOSS = 1; break;
                break;
                case 2: EN[8].init_enemy( 391, 140, 10, 125, 1, 1, 1 );
                        EN[9].init_enemy( -100, 130, 9, 125, 1, 1, 1 );
                        EN[10].init_enemy( 390, 90, 13, 135, 1, 1, 2 );
                        EN[11].init_enemy( -100, 90, 2, 145, 1, 1, 2 );
                        EN[12].init_enemy( 391, 140, 1, 135, 1, 1, 2 ); break;
                break;
            }
        break;
    }
}

void enemy_init2( void )
{
    switch( ROUND2 )
    {
        case 1:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 371, 110, 8, 75, 0, 1, 1 );
                        EN[1].init_enemy( 510, 90, 9, 110, 0, 2, 1 );
                        IT[0].item_create( 451, 199, 2, random( 6 ) + 1 );
                        IT[1].item_create( 495, 199, 2, random( 15 ) + 1 );
                break;
                case 1: EN[2].init_enemy( 391, 140, 3, 115, 1, 1, 1 );
                        EN[3].init_enemy( -100, 130, 14, 128, 1, 1, 1 );
                        EN[4].init_enemy( 420, 90, 10, 102, 1, 1, 2 );
                        EN[5].init_enemy( 420, 140, 4, 92, 1, 1, 2 );
                        IT[2].item_create( 371, 180, 6, random( 4 ) + 1 );
                        IT[3].item_create( 520, 146, 5, random( 15 ) + 1 );
                break;
                case 2: EN[6].init_enemy( 391, 140, 4, 95, 1, 1, 1 );
                        EN[7].init_enemy( -100, 130, 10, 93, 1, 1, 1 );
                        EN[8].init_enemy( 390, 90, 11, 222, 1, 1, 2 );
                break;
            }
        break;
        case 2:
            switch( s_flag )
            {
                case 1: EN[0].init_enemy( 391, 140, 6, 95, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, 8, 103, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 2, 100, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 13, 107, 1, 1, 2 );
                break;
            }
        break;
        case 3:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 4, 115, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, 5, 113, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 6, 100, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 7, 117, 1, 1, 2 );
                        IT[4].item_create( 371, 145, 2, random( 6 ) + 1 );
                        IT[5].item_create( 420, 145, 2, random( 9 ) + 7 );
                break;
                case 1: EN[4].init_enemy( 391, 140, 1, 85, 0, 1, 2 );
                        EN[5].init_enemy( 430, 130, 2, 93, 0, 1, 2 );
                        EN[6].init_enemy( 380, 90, 14, 102, 1, 1, 2 );
                        EN[7].init_enemy( -100, 90, 9, 122, 1, 1, 1 );
                break;
                case 2: EN[8].init_enemy( 391, 140, 12, 135, 1, 1, 1 );
                        EN[9].init_enemy( -100, 130, 7, 135, 1, 1, 1 );
                        EN[10].init_enemy( 390, 90, 6, 145, 1, 1, 2 );
                        EN[11].init_enemy( -100, 90, 12, 125, 1, 1, 2 );
                        EN[12].init_enemy( 391, 140, 8, 155, 1, 1, 2 ); break;
                break;
            }
        break;
        case 4:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, random( 8 ) + 1, 115, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, random( 8 ) + 1, 113, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, random( 8 ) + 1, 100, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, random( 8 ) + 1, 117, 1, 1, 2 );
                        IT[6].item_create( 371, 165, 4, random( 6 ) + 1 );
                        IT[7].item_create( 440, 165, 4, random( 9 ) + 7 );
                break;
                case 1: EN[4].init_enemy( 391, 120, random( 9 ) + 1, 85, 0, 1, 2 );
                        EN[5].init_enemy( 430, 100, random( 10 ) + 1, 93, 0, 1, 2 );
                        EN[6].init_enemy( 380, 90, random( 10 ) + 1, 102, 1, 1, 2 );
                        EN[7].init_enemy( -100, 90, random( 10 ) + 1, 122, 1, 1, 1 );
                        EN[29].init_enemy( 621, 140, 16, 1000, 0, 1, 2 ); EN[29].BOSS = 1; break;
                break;
                case 2: EN[8].init_enemy( 391, 140, random( 9 ) + 1, 135, 1, 1, 1 );
                        EN[9].init_enemy( -100, 130, random( 9 ) + 1, 135, 1, 1, 1 );
                        EN[10].init_enemy( 390, 90, random( 9 ) + 1, 145, 1, 1, 2 );
                        EN[11].init_enemy( -100, 90, random( 9 ) + 1, 125, 1, 1, 2 );
                break;
            }
        break;
    }
}

void enemy_init3( void )
{
    switch( ROUND2 )
    {
        case 1:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 371, 110, 14, 375, 0, 1, 1 );
                        EN[1].init_enemy( 510, 90, 8, 210, 0, 1, 1 );
                        IT[0].item_create( 371, 64, 1, random( 15 ) + 1 );
                        IT[1].item_create( 520, 146, 3, random( 15 ) + 1 );
                        IT[2].item_create( 620, 96, 3, random( 15 ) + 1 );
                break;
                case 1: EN[2].init_enemy( 391, 140, 1, 215, 1, 1, 2 );
                        EN[3].init_enemy( -100, 130, 2, 328, 1, 1, 1 );
                        EN[4].init_enemy( 420, 90, 3, 202, 1, 1, 2 );
                        EN[5].init_enemy( -100, 140, 4, 292, 1, 1, 1 );
                        EN[6].init_enemy( 420, 140, 5, 292, 1, 1, 2 );
                        EN[7].init_enemy( -100, 140, 6, 292, 1, 1, 1 );
                        EN[8].init_enemy( 420, 140, 7, 292, 1, 1, 2 );
                        NEXT_ENEMY = 2;
                break;
                case 2:
                    switch( NEXT_ENEMY )
                    {
                        case 2:
                            EN[9].init_enemy( 391, 140, 8, 295, 1, 1, 2 );
                            EN[10].init_enemy( -100, 130, 8, 223, 1, 1, 1 );
                            EN[11].init_enemy( 390, 90, 8, 222, 1, 1, 2 );
                        break;
                        case 1:
                            EN[12].init_enemy( 391, 140, 9, 295, 1, 1, 2 );
                            EN[13].init_enemy( -100, 130, 9, 293, 1, 1, 1 );
                            EN[14].init_enemy( 390, 90, 9, 222, 1, 1, 2 );
                        break;
                        case 0:
                            EN[15].init_enemy( 391, 140, 10, 295, 1, 1, 2 );
                            EN[16].init_enemy( -100, 130, 10, 293, 1, 1, 1 );
                            EN[17].init_enemy( 390, 90, 10, 222, 1, 1, 2 );
                        break;
                    }
                break;
            }
        break;
        case 2:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 11, 295, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, 12, 203, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 13, 200, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 10, 207, 1, 1, 1 );
                break;
                case 1: EN[4].init_enemy( 391, 140, 14, 95, 1, 1, 2 );
                        EN[5].init_enemy( -100, 130, 8, 103, 1, 1, 1 );
                        EN[6].init_enemy( 420, 90, 7, 100, 1, 1, 2 );
                        EN[7].init_enemy( -100, 110, 9, 107, 1, 1, 1 );
                break;
            }
        break;
        case 3:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 4, 215, 1, 1, 1 );
                        EN[1].init_enemy( -100, 130, 5, 213, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 6, 200, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 7, 217, 1, 1, 2 );
                        IT[0].item_create( 371, 115, 6, random( 6 ) + 1 );
                        IT[1].item_create( 450, 115, 6, random( 9 ) + 7 );
                break;
                case 1: EN[4].init_enemy( 391, 140, 8, 285, 0, 1, 2 );
                        EN[5].init_enemy( 430, 130, 9, 293, 0, 1, 2 );
                        EN[6].init_enemy( 380, 90, 10, 202, 1, 1, 2 );
                        EN[7].init_enemy( -100, 90, 11, 222, 1, 1, 1 );
                break;
                case 2: EN[8].init_enemy( 391, 140, 12, 235, 1, 1, 1 );
                        EN[9].init_enemy( -100, 130, 13, 235, 1, 1, 1 );
                        EN[10].init_enemy( 390, 90, 14, 245, 1, 1, 2 );
                        EN[11].init_enemy( -100, 90, 1, 225, 1, 1, 2 );
                        EN[12].init_enemy( 391, 140, 2, 255, 1, 1, 2 );
                break;
            }
        break;
        case 4:
            switch( s_flag )
            {
                case 0: EN[29].init_enemy( 391, 120, 17, 1200, 1, 1, 1 ); EN[29].BOSS = 1; break;
            }
        break;
    }
}

void enemy_init4( void )
{
    switch( ROUND2 )
    {
        case 1:
            switch( s_flag )
            {
                case 1: EN[0].init_enemy( 371, 110, 1, 275, 1, 1, 2 );
                        EN[1].init_enemy( 510, 90, 9, 210, 1, 1, 2 );
                        EN[2].init_enemy( -100, 90, 4, 210, 1, 1, 1 );
                        EN[3].init_enemy( -100, 110, 11, 410, 1, 1, 1 );
                        IT[0].item_create( 371, 134, 6, random( 15 ) + 1 );
                        IT[1].item_create( 520, 146, 6, random( 15 ) + 1 );
                        IT[2].item_create( 620, 166, 6, random( 15 ) + 1 );
                break;
                case 2: EN[4].init_enemy( 391, 140, 8, 215, 1, 1, 2 );
                        EN[5].init_enemy( -100, 130, 9, 328, 1, 1, 1 );
                        EN[6].init_enemy( 420, 90, 10, 202, 1, 1, 2 );
                        EN[7].init_enemy( -100, 140, 11, 292, 1, 1, 1 );
                        EN[8].init_enemy( 420, 140, 12, 292, 1, 1, 2 );
                        EN[9].init_enemy( -100, 140, 13, 292, 1, 1, 1 );
                        EN[10].init_enemy( 420, 140, 14, 292, 1, 1, 2 );
                        NEXT_ENEMY = 1;
                break;
                case 3:
                    switch( NEXT_ENEMY )
                    {
                        case 1:
                            EN[11].init_enemy( 391, 140, 11, 295, 1, 1, 2 );
                            EN[12].init_enemy( -100, 130, 11, 223, 1, 1, 1 );
                            EN[13].init_enemy( 390, 90, 11, 222, 1, 1, 2 );
                        break;
                        case 0:
                            EN[14].init_enemy( 391, 140, 13, 295, 1, 1, 2 );
                            EN[15].init_enemy( -100, 130, 13, 293, 1, 1, 1 );
                            EN[16].init_enemy( 390, 90, 13, 222, 1, 1, 2 );
                        break;
                    }
                break;
                case 4:
                    EN[17].init_enemy( 391, 140, 12, 295, 1, 1, 2 );
                    EN[18].init_enemy( -100, 130, 12, 293, 1, 1, 1 );
                    EN[19].init_enemy( 390, 90, 12, 222, 1, 1, 2 );
                break;
                case 5:
                    EN[20].init_enemy( 391, 140, 4, 295, 1, 1, 2 );
                    EN[21].init_enemy( -100, 130, 4, 293, 1, 1, 1 );
                    EN[22].init_enemy( 390, 90, 4, 222, 1, 1, 2 );
                break;
                case 6:
                    EN[23].init_enemy( 391, 140, 9, 295, 1, 1, 2 );
                    EN[24].init_enemy( -100, 130, 9, 293, 1, 1, 1 );
                    EN[25].init_enemy( 390, 90, 9, 222, 1, 1, 2 );
                break;
            }
        break;
        case 2:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 8, 295, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, 13, 203, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, 13, 200, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, 10, 207, 1, 1, 1 );
                        IT[3].item_create( 371, 164, 6, random( 15 ) + 1 );
                        IT[4].item_create( 520, 146, 6, random( 15 ) + 1 );
                break;
                case 1: EN[4].init_enemy( 391, 140, 14, 95, 1, 1, 2 );
                        EN[5].init_enemy( -100, 130, 3, 103, 1, 1, 1 );
                        EN[6].init_enemy( 420, 90, 2, 100, 1, 1, 2 );
                        EN[7].init_enemy( -100, 110, 1, 107, 1, 1, 1 );
                break;
                case 2: EN[8].init_enemy( 391, 140, 9, 95, 1, 1, 2 );
                        EN[9].init_enemy( -100, 130, 11, 103, 1, 1, 1 );
                        EN[10].init_enemy( 420, 90, 12, 100, 1, 1, 2 );
                        EN[11].init_enemy( -100, 110, 2, 107, 1, 1, 1 );
                break;
            }
        break;
        case 3:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, 15, 415, 1, 1, 2 ); break;
            }
            NEXT_ENEMY2 = 3;
        break;
        case 4:
            switch( NEXT_ENEMY2 )
            {
                case 3:
                    EN[1].init_enemy( 391, 140, 11, 295, 1, 1, 2 );
                    EN[2].init_enemy( -100, 130, 11, 223, 1, 1, 1 );
                    EN[3].init_enemy( 390, 90, 11, 222, 1, 1, 2 );
                    NEXT_ENEMY = 3;
                break;
                case 2:
                    EN[4].init_enemy( 391, 140, 12, 295, 1, 1, 2 );
                    EN[5].init_enemy( -100, 130, 12, 293, 1, 1, 1 );
                    EN[6].init_enemy( 390, 90, 12, 222, 1, 1, 2 );
                break;
                case 1:
                    EN[7].init_enemy( 391, 140, 10, 295, 1, 1, 2 );
                    EN[8].init_enemy( -100, 130, 10, 293, 1, 1, 1 );
                    EN[9].init_enemy( 390, 90, 10, 222, 1, 1, 2 );
                break;
                case 0:
                    EN[10].init_enemy( 391, 140, 10, 295, 1, 1, 2 );
                    EN[11].init_enemy( -100, 130, 13, 293, 1, 1, 1 );
                    EN[12].init_enemy( 390, 90, 13, 222, 1, 1, 2 );
                    NEXT_ENEMY = 0;
                break;
            }
        break;
        case 5:
            EN[29].init_enemy( 391, 120, 18, 1415, 1, 1, 2 ); EN[29].BOSS = 1;
        break;
    }
}

void enemy_init5( void )
{
    switch( ROUND2 )
    {
        case 1:
            switch( s_flag )
            {
                case 1: EN[0].init_enemy( 371, 110, random( 14 ) + 1, 375, 1, 1, 2 );
                        EN[1].init_enemy( 510, 90, random( 14 ) + 1, 310, 1, 1, 2 );
                        EN[2].init_enemy( -100, 90, random( 14 ) + 1, 310, 1, 1, 1 );
                        EN[3].init_enemy( -100, 110, random( 14 ) + 1, 310, 1, 1, 1 );
                        EN[4].init_enemy( -100, 110, random( 14 ) + 1, 310, 1, 1, 1 );
                break;
                case 2: EN[5].init_enemy( 391, 140, random( 14 ) + 1, 315, 1, 1, 2 );
                        EN[6].init_enemy( -100, 130, random( 14 ) + 1, 328, 1, 1, 1 );
                        EN[7].init_enemy( 420, 90, random( 14 ) + 1, 302, 1, 1, 2 );
                        EN[8].init_enemy( -100, 140, random( 14 ) + 1, 392, 1, 1, 1 );
                        EN[9].init_enemy( 420, 140, random( 14 ) + 1, 392, 1, 1, 2 );
                break;
                case 3: EN[10].init_enemy( 391, 140, random( 14 ) + 1, 315, 1, 1, 2 );
                        EN[11].init_enemy( -100, 130, random( 14 ) + 1, 328, 1, 1, 1 );
                        EN[12].init_enemy( 420, 90, random( 14 ) + 1, 302, 1, 1, 2 );
                        EN[13].init_enemy( -100, 140, random( 14 ) + 1, 392, 1, 1, 1 );
                        EN[14].init_enemy( 420, 140, random( 14 ) + 1, 392, 1, 1, 2 );
                break;
            }
        break;
        case 2:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, random( 14 ) + 1, 395, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, random( 14 ) + 1, 303, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, random( 14 ) + 1, 300, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[4].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[5].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                break;
                case 1: EN[6].init_enemy( 391, 140, random( 14 ) + 1, 395, 1, 1, 2 );
                        EN[7].init_enemy( -100, 130, random( 14 ) + 1, 303, 1, 1, 1 );
                        EN[8].init_enemy( 420, 90, random( 14 ) + 1, 300, 1, 1, 2 );
                        EN[9].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[10].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[11].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                break;
                case 2: EN[12].init_enemy( 391, 140, random( 14 ) + 1, 395, 1, 1, 2 );
                        EN[13].init_enemy( -100, 130, random( 14 ) + 1, 303, 1, 1, 1 );
                        EN[14].init_enemy( 420, 90, random( 14 ) + 1, 300, 1, 1, 2 );
                        EN[15].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[16].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                        EN[17].init_enemy( -100, 110, random( 14 ) + 1, 307, 1, 1, 1 );
                break;
            }
        break;
        case 3:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[4].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[5].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 1: EN[6].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[7].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[8].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[9].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[10].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[11].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 2: EN[12].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[13].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[14].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[15].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[16].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[17].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
            }
        break;
        case 4:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[4].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[5].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 1: EN[6].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[7].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[8].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[9].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[10].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[11].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 2: EN[12].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[13].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[14].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[15].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[16].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[17].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
            }
        break;
        case 5:
            switch( s_flag )
            {
                case 0: EN[0].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[1].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[2].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[3].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[4].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[5].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 1: EN[6].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[7].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[8].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[9].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[10].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[11].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 2: EN[12].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[13].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[14].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[15].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[16].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[17].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
                case 3: EN[18].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[19].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[20].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[21].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[22].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[23].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[29].init_enemy( 621, 120, 19, 1435, 0, 1, 2 ); EN[29].BOSS = 1;
                break;
                case 4: EN[24].init_enemy( 391, 140, random( 14 ) + 1, 425, 1, 1, 2 );
                        EN[25].init_enemy( -100, 130, random( 14 ) + 1, 353, 1, 1, 1 );
                        EN[26].init_enemy( 420, 90, random( 14 ) + 1, 350, 1, 1, 2 );
                        EN[27].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                        EN[28].init_enemy( -100, 110, random( 14 ) + 1, 357, 1, 1, 1 );
                break;
            }
        break;
    }
}

void enemy_init6( void )
{
    EN[0].init_enemy( 371, 110, 15, 1435, 1, 1, 2 );
    EN[1].init_enemy( -100, 90, 16, 1435, 1, 1, 1 );
    EN[2].init_enemy( 371, 90, 17, 1435, 1, 1, 2 );
    EN[3].init_enemy( -100, 110, 18, 1435, 1, 1, 1 );
    EN[4].init_enemy( 371, 130, 19, 1435, 1, 1, 2 );
}

void enemy_init( void )
{
    switch( ROUND )
    {
        case 1: enemy_init1(); break;
        case 2: enemy_init2(); break;
        case 3: enemy_init3(); break;
        case 4: enemy_init4(); break;
        case 5: enemy_init5(); break;
        case 6: enemy_init6(); break;
    }
}

