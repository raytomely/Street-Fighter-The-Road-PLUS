//"PLAYER.C" ÏiA·¡´á ÀáŸ¡Ða“e ¦¦…

void PLAYER :: at_off( void )
{
    ATTACK = OFF, JUMP = OFF, SPECIAL = OFF, MOVE = OFF, DAMAGE = OFF, DASH = OFF;
    for ( i = 0; i < 30; i++ ) at[i] = 0; HIT_TYPE = 1, THROW = OFF;
    SPECIAL_TYPE = 0, DAMAGE_TYPE = 0;
    asci[_CTRL] = 0, asci[_ALT] = 0, asci[_RSHIFT] = 0;
}

void AT_off( void )
{
    for ( i = 0; i < 30; i++ ) NA.at[i] = 0;
}

void PLAYER :: Ti( int t )
{
    for ( i = 0; i <= last_act; i++ ) TI[i] = t;
}

void PLAYER :: set_SXSY( int t )
{
    switch( t )
    {
        case 1:
            switch( Dir )
            {
                case 1:
                    for ( i = 0; i <= last_act; i++ )
                    sx[i] = 0, sy[i] = SY - Y[ACT[i]];
                break;
                case 2:
                    for ( i = 0; i <= last_act; i++ )
                    sx[i] = SX - X[ACT[i]], sy[i] = SY - Y[ACT[i]];
                break;
            }
        break;
        case 2:
            for ( i = 0; i <= last_act; i++ )
                sx[i] = (SX - X[ACT[i]])/2, sy[i] = (SY - Y[ACT[i]])/2;
        break;
    }
}

void PLAYER :: act_churi( int t )
{
    switch( t )
    {
        case 1:
            if ( TIME++ > TI[act] ) TIME = 0, act++;
            if ( act > last_act ) act = 0;
        break;
        case 2:
            if ( TIME++ > TI[act] ) TIME = 0, act++;
            if ( act > last_act ) act = last_act;
        break;
    }
}

void PLAYER :: init_player( int x, int y, int t )
{
    at_off(), ENERGY = 288;
    PX = x, TYPE = t, act = 0, TIME = 0, Dir = 1, FLAG = 1, LIFE = 1, HIT_TYPE = 1;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 0, ACT[1] = 1, ACT[2] = 2, ACT[3] = 3, ACT[4] = 2, ACT[5] = 1;
            last_act = 5, SX = 68, SY = 94, Ti( 1 );
        break;
        case 2: //ˆa·©
            ACT[0] = 100, ACT[1] = 101, ACT[2] = 102, ACT[3] = 103, ACT[4] = 102, ACT[5] = 101;
            last_act = 5, SX = 79, SY = 90, Ti( 1 );
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 200, ACT[1] = 201, ACT[2] = 202, ACT[3] = 203, ACT[4] = 204;
            last_act = 4, SX = 72, SY = 101, Ti( 4 );
        break;
    }
    PY = y;
    set_SXSY( 1 );
}

void PLAYER :: s_player( void )
{
    act = 0, TIME = 0, FLAG = 1;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 0, ACT[1] = 1, ACT[2] = 2, ACT[3] = 3, ACT[4] = 2, ACT[5] = 1;
            last_act = 5, Ti( 1 );
        break;
        case 2: //ˆa·©
            ACT[0] = 100, ACT[1] = 101, ACT[2] = 102, ACT[3] = 103, ACT[4] = 102, ACT[5] = 101;
            last_act = 5, Ti( 1 );
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 200, ACT[1] = 201, ACT[2] = 202, ACT[3] = 203, ACT[4] = 204;
            last_act = 4, Ti( 4 );
        break;
    }
    set_SXSY( 1 );
}

void PLAYER :: walk_create( void )
{
    FLAG = 2;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 4, ACT[1] = 5, ACT[2] = 6, ACT[3] = 7, ACT[4] = 8, ACT[5] = 9;
            last_act = 5; Ti( 1 );
        break;
        case 2: //ˆa·©
            ACT[0] = 104, ACT[1] = 105, ACT[2] = 106, ACT[3] = 107, ACT[4] = 108;
            last_act = 4; Ti( 2 );
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 205, ACT[1] = 206, ACT[2] = 212, ACT[3] = 207, ACT[4] = 208, ACT[5] = 209, ACT[6] = 210, ACT[7] = 211, ACT[8] = 213;
            last_act = 8; Ti( 2 ); 
        break;
    }
    set_SXSY( 1 );
}

void PLAYER :: punch1_create( void )
{
    FLAG = 3, act = 0, TIME = 0, AT_off();
    switch( TYPE )
    {
        case 1: //ÅE
            if ( JUMP == OFF )
            {
                ACT[0] = 10, ACT[1] = 11, ACT[2] = 10, POW = 10;
                last_act = 2, Ti( 0 ), set_SXSY( 1 ); at[1] = 1;
            }
            if ( JUMP == ON )
            {
                ACT[0] = 30, ACT[1] = 21, ACT[2] = 20, ACT[3] = 23;
                FLAG = 4, last_act = 3, set_SXSY( 1 ); at[0] = 2, HIT_TYPE = 2, POW = 15;
                Ti( 2 ), TI[0] = 7;
                if ( BAN == 4 || BAN == 6 )
                {
                    ACT[0] = 31, ACT[1] = 32, ACT[2] = 33, ACT[3] = 32, ACT[4] = 31, ACT[5] = 21, ACT[6] = 20, ACT[7] = 23, POW = 15;
                    last_act = 7, FLAG = 4, set_SXSY( 1 ); at[2] = 2, HIT_TYPE = 2, Ti( 2 ), TI[2] = 5;
                }
            }
            if ( DASH == ON )
            {
                ACT[0] = 31, ACT[1] = 86, ACT[2] = 21, ACT[3] = 20, ACT[4] = 23;
                FLAG = 6, last_act = 4, set_SXSY( 1 ); at[1] = 1, HIT_TYPE = 2, POW = 6;
                Ti( 2 ), TI[1] = 8, at[1] = 1;
            }
        break;
        case 2: //ˆa·©
            if ( JUMP == OFF )
            {
                ACT[0] = 109, ACT[1] = 110, ACT[2] = 111, POW = 9;
                last_act = 2, Ti( 0 ), set_SXSY( 1 ); at[1] = 1;
            }
            if ( JUMP == ON )
            {
                ACT[0] = 139, ACT[1] = 140, ACT[2] = 141, ACT[3] = 139, ACT[4] = 126;
                FLAG = 4, last_act = 4, set_SXSY( 1 ); at[2] = 2, HIT_TYPE = 2, POW = 13;
                Ti( 2 ), TI[2] = 7;
                if ( BAN == 4 || BAN == 6 )
                {
                    ACT[0] = 136, ACT[1] = 137, ACT[2] = 138, ACT[3] = 136, POW = 14;
                    last_act = 3, FLAG = 4, set_SXSY( 1 ); at[2] = 2, HIT_TYPE = 2, Ti( 2 ), TI[2] = 5;
                }
            }
            if ( DASH == ON )
            {
                ACT[0] = 142, ACT[1] = 143, ACT[2] = 144, ACT[3] = 145, ACT[4] = 146, ACT[5] = 126;
                FLAG = 6, last_act = 5, set_SXSY( 1 ); at[2] = 1, HIT_TYPE = 2, POW = 6;
                Ti( 1 ), TI[2] = 3;
            }
        break;
        case 3: //·¡µ¡Ÿ¡
            if ( JUMP == OFF )
            {
                ACT[0] = 214, ACT[1] = 215, ACT[2] = 214, POW = 12;
                last_act = 2, Ti( 0 ), set_SXSY( 1 ); at[1] = 1;
            }
            if ( JUMP == ON )
            {
                ACT[0] = 238, ACT[1] = 239, ACT[2] = 238, ACT[3] = 236, ACT[4] = 235, ACT[5] = 234;
                FLAG = 4, last_act = 5, set_SXSY( 1 ); at[1] = 2, HIT_TYPE = 2, POW = 16;
                Ti( 1 ), TI[1] = 7;
                if ( BAN == 4 || BAN == 6 )
                {
                    ACT[0] = 240, ACT[1] = 241, ACT[2] = 242, ACT[3] = 243, ACT[4] = 244, ACT[5] = 245, ACT[6] = 234, POW = 17;
                    last_act = 6, FLAG = 4, set_SXSY( 1 ); at[4] = 2, HIT_TYPE = 2, Ti( 1 ), TI[4] = 5;
                }
            }
            if ( DASH == ON )
            {
                ACT[0] = 268, ACT[1] = 269, ACT[2] = 270, ACT[3] = 271;
                FLAG = 6, last_act = 3, set_SXSY( 1 ); at[2] = 2, HIT_TYPE = 2, POW = 6;
                Ti( 2 ), TI[1] = 4, TI[2] = 3, TI[3] = 12, GY = 3, GY2 = 0;
            }
        break;
    }
    ATTACK = ON, MOVE = ON;
}

void PLAYER :: punch2_create( void )
{
    FLAG = 3, act = 0, TIME = 0, AT_off(), POW = 15;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 10, ACT[1] = 12, ACT[2] = 13, ACT[3] = 12, ACT[4] = 10;
            last_act = 4, Ti( 0 ); TI[2] = 3, at[2] = 1;
        break;
        case 2: //ˆa·©
            ACT[0] = 112, ACT[1] = 113, ACT[2] = 114, ACT[3] = 115, ACT[4] = 116, ACT[5] = 117;
            last_act = 4, Ti( 0 ); TI[3] = 3, at[3] = 1;
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 216, ACT[1] = 217, ACT[2] = 218, ACT[3] = 219, ACT[4] = 220, ACT[5] = 221;
            last_act = 5, Ti( 0 ); TI[1] = 2, TI[2] = 3, at[1] = 1;
        break;
    }
    set_SXSY( 1 );
    ATTACK = ON, MOVE = ON;
}

void PLAYER :: punch3_create( void )
{
    FLAG = 3, act = 0, TIME = 0, AT_off(), POW = 18;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 14, ACT[1] = 15, ACT[2] = 16, ACT[3] = 17;
            last_act = 3, Ti( 0 ), TI[1] = 3, TI[2] = 4, at[1] = 1, at[2] = 2;
        break;
        case 2: //ˆa·©
            ACT[0] = 118, ACT[1] = 119, ACT[2] = 120, ACT[3] = 121, ACT[4] = 122, ACT[5] = 123;
            last_act = 5, Ti( 0 ), TI[3] = 3, TI[4] = 4, at[3] = 1, at[4] = 2;
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 222, ACT[1] = 223, ACT[2] = 224, ACT[3] = 225, ACT[4] = 226, ACT[5] = 227, ACT[6] = 228, ACT[7] = 229, ACT[8] = 230, ACT[9] = 231, ACT[10] = 232;
            last_act = 10, Ti( 0 ); TI[6] = 3, TI[7] = 4, at[6] = 1, at[7] = 2;
        break;
    }
    set_SXSY( 1 );
    ATTACK = ON, MOVE = ON;
}

void PLAYER :: japki_create( void )
{
    FLAG = 9, act = 0, TIME = 0, AT_off(), POW = 22, PY2 = PY;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 71, ACT[1] = 72, ACT[2] = 73, ACT[3] = 74, ACT[4] = 75;
            last_act = 4, Ti( 4 ); TI[3] = 6;
            set_SXSY( 1 ); voc_play2( 8 );
        break;
        case 2: //ˆa·©
            ACT[0] = 174, ACT[1] = 175, ACT[2] = 176, ACT[3] = 177;
            last_act = 3, Ti( 4 ); TI[1] = 6, TI[3] = 8;
            set_SXSY( 1 );
            switch( Dir )
            {
                case 2:
                    for ( i = 1; i <= last_act; i++ )
                    sx[i] = 1, sy[i] = SY - Y[ACT[i]];
                break;
                case 1:
                    for ( i = 1; i <= last_act; i++ )
                    sx[i] = SX - X[ACT[i]], sy[i] = SY - Y[ACT[i]];
                break;
            }
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 291, ACT[1] = 292, ACT[2] = 293, ACT[3] = 294, ACT[4] = 295, ACT[5] = 296, ACT[6] = 297, ACT[7] = 298, ACT[8] = 299;
            last_act = 8, Ti( 3 ); TI[3] = 5;
            set_SXSY( 1 ); //voc_play( 8 );
        break;
    }
    SPECIAL = ON, MOVE = ON, THROW = ON;
}

void PLAYER :: joopki_create( void ) //ÏiA·¡´á—i· º““e ¡¡­e
{
    FLAG = 10, act = 0, TIME = 0, AT_off();
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 4, ACT[1] = 91, ACT[2] = 92, ACT[3] = 91, ACT[4] = 4;
            last_act = 4, Ti( 1 );
        break;
        case 2: //ˆa·©
            ACT[0] = 124, ACT[1] = 194, ACT[2] = 124;
            last_act = 2, Ti( 2 );
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 233, ACT[1] = 283, ACT[2] = 233;
            last_act = 2, Ti( 2 );
        break;
    }
    set_SXSY( 1 ); MOVE = ON;
}

void PLAYER :: jump_create( void )
{
    FLAG = 4, act = 0, TIME = 0, GY = 8, GY2 = 0, last_act = 8;
    switch( TYPE )
    {
        case 1: //ÅE
            ACT[0] = 18, ACT[1] = 19, ACT[2] = 20, ACT[3] = 21, ACT[4] = 22, ACT[5] = 21, ACT[6] = 20, ACT[7] = 23, ACT[8] = 18;
            set_SXSY( 1 );
            Ti( 2 ), TI[0] = 1, TI[1] = 6, TI[7] = 8;
            if ( BAN == 4 || BAN == 6 )
            {
                ACT[0] = 18, ACT[1] = 24, ACT[2] = 25, ACT[3] = 26, ACT[4] = 27, ACT[5] = 28, ACT[6] = 29, ACT[7] = 23, ACT[8] = 18;
                set_SXSY( 2 );
            }
        break;
        case 2: //ˆa·©
            ACT[0] = 124, ACT[1] = 125, ACT[2] = 126, ACT[3] = 127, ACT[4] = 128, ACT[5] = 127, ACT[6] = 126, ACT[7] = 125, ACT[8] = 124;
            set_SXSY( 1 );
            Ti( 2 ), TI[0] = 1, TI[1] = 6, TI[7] = 8;
            if ( BAN == 4 || BAN == 6 )
            {
                ACT[0] = 124, ACT[1] = 129, ACT[2] = 130, ACT[3] = 131, ACT[4] = 132, ACT[5] = 133, ACT[6] = 134, ACT[7] = 135, ACT[8] = 124;
                set_SXSY( 2 );
            }
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 233, ACT[1] = 234, ACT[2] = 235, ACT[3] = 236, ACT[4] = 237, ACT[5] = 236, ACT[6] = 235, ACT[7] = 234, ACT[8] = 233;
            set_SXSY( 1 );
            Ti( 2 ), TI[0] = 1, TI[1] = 6, TI[7] = 8;
            if ( DASH == ON )
            {
                switch( Dir )
                {
                    case 1: BAN = 6; break;
                    case 2: BAN = 4; break;
                }
                DASH = 2;
            }
        break;
    }
    JUMP = ON, MOVE = ON, PY2 = PY;
}

void PLAYER :: special_create( void )
{
    FLAG = 5, act = 0, TIME = 0;
    switch( TYPE )
    {
        case 1: //ÅEÚ1
            switch( SPECIAL_TYPE )
            {
                case 1: //µ¡ŸA‰E
                    voc_play2( 1 ), POW = 15;
                    ACT[0] = 51, ACT[1] = 52, ACT[2] = 53, ACT[3] = 54, ACT[4] = 55, ACT[5] = 56;
                    last_act = 5; set_SXSY( 1 ); at[1] = 1, at[2] = 3;
                    Ti( 2 ), TI[2] = 9, TI[3] = 6, TI[4] = 5, GY = 6, GY2 = 0;
                break;
                case 2: //´aÌaÈaÌa š‰E
                    voc_play2( 2 ), POW = 14;
                    ACT[0] = 40, ACT[1] = 41, ACT[2] = 42, ACT[3] = 87, ACT[4] = 88, ACT[5] = 89, ACT[6] = 90, ACT[7] = 47, ACT[8] = 48, ACT[9] = 49, ACT[10] = 50;
                    last_act = 10; set_SXSY( 1 );
                    switch( Dir )
                    {
                        case 1: sx[6] = 0; sx[4] = SX - X[ACT[4]], next = 0; break;
                        case 2: sx[4] = 0; sx[6] = SX - X[ACT[6]], next = 0; break;
                    }
                    sy[1] = 0, sy[2] = 0, sy[3] = 0, sy[4] = 0, sy[5] = 0, sy[6] = 0; at[4] = 1, at[6] = 1;
                    Ti( 1 ), TI[0] = 7, TI[3] = 0, TI[4] = 1, TI[5] = 0, TI[6] = 1, GY = 5, GY2 = 0;
                break;
                case 3: //´a¹¡‰E
                    voc_play2( 3 ), POW = 7;
                    ACT[0] = 34, ACT[1] = 35, ACT[2] = 36, ACT[3] = 37;
                    last_act = 3; set_SXSY( 1 );
                    Ti( 2 ), TI[3] = 22;
                break;
                case 4: //¤i—i´á Ÿ¡¿¢‹¡
                    voc_play2( 4 ), POW = 6;
                    ACT[0] = 76, ACT[1] = 77, ACT[2] = 78, ACT[3] = 79, ACT[4] = 80, ACT[5] = 81, ACT[6] = 82, ACT[7] = 83, ACT[8] = 84, ACT[9] = 85;
                    at[3] = 1, at[4] = 1, at[5] = 1, at[6] = 1, at[7] = 1, at[8] = 2;
                    last_act = 9; set_SXSY( 1 );
                    Ti( 1 ); TI[3] = 3;
                break;
                case 5: //ÅE· Ï©¬i‹¡
                    voc_play2( 2 ), POW = 30;
                    ACT[0] = 40, ACT[1] = 41, ACT[2] = 42, ACT[3] = 87, ACT[4] = 88, ACT[5] = 89, ACT[6] = 90, ACT[7] = 47, ACT[8] = 48, ACT[9] = 49, ACT[10] = 50;
                    last_act = 10; set_SXSY( 1 );
                    switch( Dir )
                    {
                        case 1: sx[6] = 0; sx[4] = SX - X[ACT[4]], next = 0; break;
                        case 2: sx[4] = 0; sx[6] = SX - X[ACT[6]], next = 0; break;
                    }
                    sy[1] = 0, sy[2] = 0, sy[3] = 0, sy[4] = 0, sy[5] = 0, sy[6] = 0; at[4] = 3, at[6] = 3;
                    Ti( 2 ), TI[0] = 9, TI[3] = 0, TI[4] = 1, TI[5] = 0, TI[6] = 1, TI[7] = 4, TI[8] = 4, TI[9] = 4, TI[10] = 4, GY = 6, GY2 = 0;
                break;
            }
        break;
        case 2: //ˆa·©
            switch( SPECIAL_TYPE )
            {
                case 1: //¤e”iÇ¢
                    ACT[0] = 148, ACT[1] = 149, ACT[2] = 147, ACT[3] = 150, ACT[4] = 151, ACT[5] = 152, ACT[6] = 153, ACT[7] = 154, ACT[8] = 155, ACT[9] = 156;
                    last_act = 9; set_SXSY( 1 ); sy[2] = 0, POW = 13;
                    Ti( 2 ), TI[3] = 0, TI[4] = 0, TI[5] = 0, TI[6] = 7, GY = 8, GY2 = 0;
                    at[3] = 1, at[4] = 1, at[5] = 1, at[6] = 5, voc_play2( 0 );
                break;
                case 2: //­¡“¢¦‘
                    ACT[0] = 157, ACT[1] = 158, ACT[2] = 159;
                    last_act = 2; set_SXSY( 1 ), POW = 7;
                    Ti( 2 ), TI[2] = 22, voc_play2( 12 );
                break;
                case 3: //ˆa·©· Ï©¬i‹¡
                    ACT[0] = 178, ACT[1] = 179, ACT[2] = 180, ACT[3] = 181, ACT[4] = 182, ACT[5] = 183, ACT[6] = 189, ACT[7] = 190, ACT[8] = 191, ACT[9] = 192, ACT[10] = 193;
                    ACT[11] = 184, ACT[12] = 185, ACT[13] = 186, ACT[14] = 187, ACT[15] = 188;
                    last_act = 15; set_SXSY( 1 ), POW = 31;
                    switch( Dir )
                    {
                        case 1: for ( i = 11; i <= last_act; i++ ) sx[i] = SX - X[ACT[i]], sy[i] = SY - Y[ACT[i]]; break;
                        case 2: for ( i = 11; i <= last_act; i++ ) sx[i] = 0, sy[i] = SY - Y[ACT[i]]; break;
                    } Ti( 2 );
                    at[1] = 3, at[2] = 3, at[3] = 3, at[7] = 3, at[8] = 3, at[9] = 3, at[12] = 3, at[13] = 3, at[14] = 3; voc_play2( 0 );
                break;
            }
        break;
        case 3: //·¡µ¡Ÿ¡
            switch( SPECIAL_TYPE )
            {
                case 1: //·¡µ¡Ÿ¡· µ¡ŸA‰E
                    voc_play2( 25 ); POW = 15;
                    ACT[0] = 255, ACT[1] = 256, ACT[2] = 257, ACT[3] = 258, ACT[4] = 259, ACT[5] = 260, ACT[6] = 261, ACT[7] = 262, ACT[8] = 233;
                    last_act = 8; set_SXSY( 1 ); at[1] = 1, at[2] = 1, at[3] = 3, at[4] = 3, at[5] = 3;
                    Ti( 2 ), TI[3] = 3, TI[4] = 3, TI[5] = 5, TI[6] = 5, TI[7] = 5, GY = 6, GY2 = 0;
                break;
                case 2: //·¡µ¡Ÿ¡· ´a¹¡‰E
                    voc_play2( 25 ); POW = 6;
                    ACT[0] = 246, ACT[1] = 247, ACT[2] = 248, ACT[3] = 249, ACT[4] = 250, ACT[5] = 251, ACT[6] = 252;
                    last_act = 6; set_SXSY( 1 );
                    Ti( 3 ), TI[2] = 10;
                break;
                case 3: //·¡µ¡Ÿ¡· Ï©¬i‹¡
                    ACT[0] = 285, ACT[1] = 286, ACT[2] = 287, ACT[3] = 288, ACT[4] = 289, ACT[5] = 290;
                    last_act = 5; set_SXSY( 1 ); at[1] = 1, at[2] = 3;
                    Ti( 2 ), TI[1] = 3, TI[2] = 5, GX = 5, GX2 = 0, POW = 24;
                break;
            }
        break;
    }
    SPECIAL = ON, MOVE = ON, PY2 = PY;
}

void PLAYER :: dash_create( void )
{
    FLAG = 6, act = 0, TIME = 0;
    switch( TYPE )
    {
        case 1: //ÅEÚ1
            ACT[0] = 18, ACT[1] = 19, ACT[2] = 20, ACT[3] = 21, ACT[4] = 22, ACT[5] = 21, ACT[6] = 20, ACT[7] = 23, ACT[8] = 18;
            last_act = 8; set_SXSY( 1 );
            Ti( 1 ); TI[1] = 2, TI[7] = 4, GY = 3, GY2 = 0;
        break;
        case 2: //ˆa·©
            ACT[0] = 124, ACT[1] = 125, ACT[2] = 126, ACT[3] = 127, ACT[4] = 128, ACT[5] = 127, ACT[6] = 126, ACT[7] = 125, ACT[8] = 124;
            last_act = 8; set_SXSY( 1 );
            Ti( 1 ); TI[1] = 2, TI[7] = 4, GY = 3, GY2 = 0;
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 263, ACT[1] = 264, ACT[2] = 265, ACT[3] = 266, ACT[4] = 265, ACT[5] = 264, ACT[6] = 263, ACT[7] = 267;
            last_act = 7; set_SXSY( 1 );
            Ti( 3 );
        break;
    }
    DASH = ON, MOVE = ON, PY2 = PY, HIT = 0;
}

void PLAYER :: damage_create( void )
{
    FLAG = 7, act = 0, TIME = 0;
    switch( TYPE )
    {
        case 1: //ÅEÚ1
            switch( DAMAGE_TYPE )
            {
                case 1: //¬á¬á x‹¡
                    ACT[0] = 57, ACT[1] = 58, ACT[2] = 59;
                    last_act = 2; set_SXSY( 1 ); Ti( 4 );
                break;
                case 2: //ñ´á»¡‹¡
                    ACT[0] = 60, ACT[1] = 61, ACT[2] = 62, ACT[3] = 63, ACT[4] = 64, ACT[5] = 65;
                    last_act = 5; set_SXSY( 1 );
                    Ti( 2 ); TI[2] = 12, GY = 4, GY2 = 0, next = 0;
                    if ( SPECIAL == OFF && DASH == OFF && JUMP == OFF ) PY2 = PY;
                break;
            }
        break;
        case 2: //ˆa·©
            switch( DAMAGE_TYPE )
            {
                case 1: //¬á¬á x‹¡
                    ACT[0] = 163, ACT[1] = 164, ACT[2] = 165, ACT[3] = 166;
                    last_act = 3; set_SXSY( 1 ); Ti( 4 );
                break;
                case 2: //ñ´á»¡‹¡
                    ACT[0] = 167, ACT[1] = 168, ACT[2] = 169;
                    last_act = 2; set_SXSY( 1 );
                    Ti( 3 ); TI[0] = 5, TI[1] = 12, GY = 4, GY2 = 0, next = 0;
                    if ( SPECIAL == OFF && DASH == OFF && JUMP == OFF ) PY2 = PY;
                break;
            }
        break;
        case 3: //·¡µ¡Ÿ¡
            switch( DAMAGE_TYPE )
            {
                case 1: //¬á¬á x‹¡
                    ACT[0] = 272, ACT[1] = 273;
                    last_act = 1; set_SXSY( 1 ); Ti( 6 );
                break;
                case 2: //ñ´á»¡‹¡
                    ACT[0] = 274, ACT[1] = 275, ACT[2] = 276, ACT[3] = 277, ACT[4] = 280, ACT[5] = 280;
                    last_act = 4; set_SXSY( 1 );
                    Ti( 2 ); GY = 4, GY2 = 0, next = 0;
                    if ( SPECIAL == OFF && DASH == OFF && JUMP == OFF ) PY2 = PY;
                break;
            }
        break;
    }
    DAMAGE = ON, MOVE = ON;
}

void PLAYER :: stand_create( void )
{
    FLAG = 8, act = 0, TIME = 0;
    switch( TYPE )
    {
        case 1: //ÅEÚ1
            ACT[0] = 65, ACT[1] = 66, ACT[2] = 67, ACT[3] = 68, ACT[4] = 69, ACT[5] = 70;
            last_act = 5; set_SXSY( 1 ); Ti( 2 ); TI[0] = 6;
        break;
        case 2: //ˆa·©
            ACT[0] = 169, ACT[1] = 170, ACT[2] = 171, ACT[3] = 172, ACT[4] = 173;
            last_act = 4; set_SXSY( 1 ); Ti( 2 ); TI[0] = 6;
        break;
        case 3: //·¡µ¡Ÿ¡
            ACT[0] = 280, ACT[1] = 281, ACT[2] = 282, ACT[3] = 283, ACT[4] = 284;
            last_act = 4; set_SXSY( 1 ); Ti( 2 ); TI[0] = 6;
        break;
    }
    MOVE = ON;
}

void PLAYER :: jang_create( void )
{
    JDIR = Dir, JLIFE = 1, JTIME = 0, JCOUNT = 0, JFLAG = 1, JACT = 38;
    switch( TYPE )
    {
        case 1: //ÅE
            switch( JDIR )
            {
                case 1: JX = PX + 98, JY = PY + 18; break;
                case 2: JX = PX - 74, JY = PY + 18; break;
            }
        break;
        case 2: //ˆa·©
            switch( JDIR )
            {
                case 1: JX = PX + 98, JY = PY + 18; break;
                case 2: JX = PX - 74, JY = PY + 18; break;
            }
            JACT = 160;
        break;
        case 3: //·¡µ¡Ÿ¡
            switch( JDIR )
            {
                case 1: JX = PX + 38, JY = PY + 39; break;
                case 2: JX = PX - 44, JY = PY + 39; break;
            }
            JACT = 253;
        break;
    }
}

void PLAYER :: jang_move( void )
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
            case 1: case 3:
                switch( JFLAG )
                {
                    case 1: put_sprite( JX, JY, X[JACT], Y[JACT], P[JACT], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 2; break;
                    case 2: put_sprite( JX, JY, X[JACT+1], Y[JACT+1], P[JACT+1], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 1; break;
                }
            break;
            case 2:
                switch( JFLAG )
                {
                    case 1: put_sprite( JX, JY, X[JACT], Y[JACT], P[JACT], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 2; break;
                    case 2: put_sprite( JX, JY, X[JACT+1], Y[JACT+1], P[JACT+1], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 3; break;
                    case 3: put_sprite( JX, JY, X[JACT+2], Y[JACT+2], P[JACT+2], JDIR ); if ( JTIME++ > 3 ) JTIME = 0, JFLAG = 1; break;
                }
            break;
        }
        if ( JCOUNT++ > 22 ) JLIFE = 0;
        for ( i3 = 0; i3 < 30; i3++ )
        {
            if (
                (JX < EN[i3].DT_X2)
                && (EN[i3].DT_X1 < JX+X[JACT] )
                && (JY < EN[i3].DT_Y2 )
                && (EN[i3].DT_Y1 < JY+Y[JACT])
                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE != 2 && EN[i3].DAMAGE_TYPE != 3
               )
            {
                EN[i3].DAMAGE_TYPE = 1; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW; else EN[i3].ENERGY--;
                EN[i3].MV = 1;
                if ( EN[i3].JUMP == ON || JCOUNT > 19 ) EN[i3].DAMAGE_TYPE = 2;
                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                EN[i3].damage_create(); if ( VC_TIME++ > 2 ) VC_TIME = 0, voc_play( 7 );
                if ( EN[i3].SHIELD == OFF ) { switch( EN[i3].Dir ) { case 1: EN[i3].PX -= 3; break; case 2: EN[i3].PX += 3; break; } }
                if ( JTIME == 0 && EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
            }
        }
        for ( i3 = 0; i3 < 10; i3++ )
        {
            if (
                (JX < IT[i3].PX + ETX[IT[i3].ACT])
                && (IT[i3].PX < JX+X[JACT] )
                && ( (BADAK_Y - 10 < IT[i3].PY + ETY[IT[i3].ACT])
                && (IT[i3].PY + ETY[IT[i3].ACT] - 10 < BADAK_Y) )
                && IT[i3].LIFE == 1
               )
            {
                IT[i3].LIFE = 2; IT2[i3].item2_create( IT[i3].PX + ETX[IT[i3].ACT]/2, IT[i3].PY + ETY[IT[i3].ACT] - 10, IT[i3].TYPE2 );
                IT[i3].PX += 20;
                switch( IT[i3].TYPE )
                {
                    case 1: case 2: case 5: voc_play( 22 ); break;
                    case 3: case 4: voc_play( 24 ); break;
                    case 6: voc_play( 23 ); break;
                }
                ting( random( ETX[IT[i3].ACT] ) + IT[i3].PX, random( (ETY[IT[i3].ACT]/2) ) + IT[i3].PY, 1 );
            }
        }
    }
}

void PLAYER :: player( void )
{
    put_sprite( PX + sx[act], PY + sy[act], X[ACT[act]], Y[ACT[act]], P[ACT[act]], Dir );
}

void PLAYER :: key_churi( void )
{
    if ( asci[_RSHIFT] && ATTACK == OFF && SPECIAL == OFF && DAMAGE == OFF && DASH == OFF && JUMP == OFF && NA.ENERGY > 20 )
    {
        asci[_RSHIFT] = 0; NA.ENERGY -= 10;
        switch( TYPE )
        {
            case 1: SPECIAL_TYPE = 5, special_create(); HIT_TYPE = 2; break;
            case 2: SPECIAL_TYPE = 3, special_create(); HIT_TYPE = 2; break;
            case 3: SPECIAL_TYPE = 3, special_create(); HIT_TYPE = 2; break;
        }
        for ( i = 0; i < 10; i++ ) stream[i] = 0;
    }
    switch( Dir )
    {
        case 1: AT_X1 = PX + (X[ACT[act]] + sx[act])/2, AT_X2 = PX + X[ACT[act]] + sx[act], AT_Y1 = PY + sy[act], AT_Y2 = PY + Y[ACT[act]] + sy[act];
            DT_X1 = PX + sx[act], DT_X2 = PX + X[ACT[act]] + sx[act], DT_Y1 = PY + sy[act], DT_Y2 = PY + Y[ACT[act]] + sy[act];
        break;
        case 2: AT_X1 = PX + sx[act], AT_X2 = PX + (X[ACT[act]] + sx[act])/2, AT_Y1 = PY + sy[act], AT_Y2 = PY + Y[ACT[act]] + sy[act];
            DT_X1 = PX + sx[act], DT_X2 = PX + X[ACT[act]] + sx[act], DT_Y1 = PY + sy[act], DT_Y2 = PY + Y[ACT[act]] + sy[act];
        break;
    }
    switch( HIT_TYPE )
    {
        case 1: BADAK_Y = PY + Y[ACT[act]] + sy[act]; break;
        case 2: BADAK_Y = PY2 + SY; break;
    }
    if ( JUMP == OFF ) BAN = 0;
    if ( scan[_UPKEY] == OFF && scan[_DNKEY] == OFF && scan[_LTKEY] == OFF && scan[_RTKEY] == OFF ) WALK = OFF;
    if ( PX < -2 ) PX = -2;
    if ( PX > 292 ) PX = 292;
    if ( (PY + SY < 191) && JUMP == OFF && SPECIAL == OFF && DAMAGE == OFF && DASH == OFF ) PY = 191 - SY;
    if ( PY + SY > 254 ) PY = 254 - SY;
    skill();
    if ( asci[_CTRL] && ATTACK == OFF && SPECIAL == OFF && DAMAGE == OFF )
    {
        HIT_TYPE = 1, MOVE_WAIT = -2;
        if ( check() == 1 ) { SPECIAL_TYPE = 1, special_create(), HIT_TYPE = 2; goto naga; }
        if ( check() == 2 ) { SPECIAL_TYPE = 2, special_create(), HIT_TYPE = 2; goto naga; }
        if ( check() == 3 && TYPE == 1 ) { SPECIAL_TYPE = 3, special_create(), HIT_TYPE = 2; goto naga; }
        if ( check() == 4 && TYPE == 1 ) { SPECIAL_TYPE = 4, special_create(), HIT_TYPE = 2; goto naga; }
        voc_play( 0 );
        switch( HIT )
        {
            case 0: case 1: default: punch1_create(); break;
            case 2: punch2_create(); break;
            case 3: case 4: punch3_create(); break;
        }
        naga:;
        for ( i = 0; i < 10; i++ ) stream[i] = 0;
    }
    if ( HIT != 0 && ATTACK == OFF ) { if ( HIT_TIME++ > 12 ) HIT_TIME = 0, HIT = 0; }
    if ( scan[_UPKEY] && MOVE == OFF )
    {
        if ( MOVE_WAIT++ > 0 ) PY -= 2, WALK = ON, walk_create();
        UKEY = ON, DKEY = OFF, LKEY = OFF, RKEY = OFF, BAN = 8;
    }
    if ( scan[_DNKEY] && MOVE == OFF )
    {
        if ( MOVE_WAIT++ > 0 ) PY += 2, WALK = ON, walk_create();
        UKEY = OFF, DKEY = ON, LKEY = OFF, RKEY = OFF, BAN = 2;
    }
    if ( scan[_LTKEY] && MOVE == OFF )
    {
        PX -= 4, WALK = ON, walk_create(), Dir = 2; BAN = 4;
        UKEY = OFF, DKEY = OFF, LKEY = ON, RKEY = OFF;
        switch( TYPE )
        {
            case 1: if ( check() == 5 && da_time++ > 3 ) dash_create(), da_time = 0; break;
            case 2: if ( check() == 3 && da_time++ > 3 ) dash_create(), da_time = 0; break;
            case 3: if ( check() == 3 && da_time++ > 3 ) dash_create(), da_time = 0; break;
        }
    }
    if ( scan[_RTKEY] && MOVE == OFF )
    {
        PX += 4, WALK = ON, walk_create(), Dir = 1; BAN = 6;
        UKEY = OFF, DKEY = OFF, LKEY = OFF, RKEY = ON;
        switch( TYPE )
        {
            case 1: if ( check() == 5 && da_time++ > 3 ) dash_create(), da_time = 0; break;
            case 2: if ( check() == 3 && da_time++ > 3 ) dash_create(), da_time = 0; break;
            case 3: if ( check() == 3 && da_time++ > 3 ) dash_create(), da_time = 0; break;
        }
    }
    if ( asci[_ALT] && JUMP == OFF && SPECIAL == OFF && DAMAGE == OFF )
    {
        asci[_ALT] = 0;
        switch( TYPE )
        {
            case 3:
                if ( ATTACK == OFF )
                {
                    jump_create(), HIT = 0, HIT_TYPE = 2;
                    for ( i = 0; i < 10; i++ ) stream[i] = 0;
                }
            break;
            case 1: case 2:
                if ( DASH == OFF )
                {
                    HIT = 0, jump_create(), HIT_TYPE = 2;
                    for ( i = 0; i < 10; i++ ) stream[i] = 0;
                }
            break;
        }
    }
    if ( WALK == OFF && FLAG != 1 && ATTACK == OFF && JUMP == OFF && SPECIAL == OFF && DAMAGE == OFF && DASH == OFF ) s_player();
}

void PLAYER :: player_churi( void )
{
    switch( FLAG )
    {
        case 1: //ˆa eÓ¡ ¬á·¶‹¡ 
            act_churi( 1 );
        break;
        case 2: //ˆè‹¡
            if ( TIME++ > TI[act] ) TIME = 0, act++;
            if ( act > last_act ) act = 0;
        break;
        case 3: //º â Òá–ž‹¡
            if ( TIME++ > TI[act] ) TIME = 0, act++;
            if ( act > last_act ) act = last_act, at_off();
        break;
        case 4: //¸ñÏa
            if ( act > 0 && ATTACK == OFF )
            {
                PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--;
                switch( BAN ) { case 4: PX -= 4; break; case 6: PX += 4; break; }
                if ( TYPE == 3 && DASH == 2 ) { switch( BAN ) { case 4: PX -= 2; break; case 6: PX += 2; break; } }
            }
            if ( ATTACK == ON )
            {
                PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--;
                switch( BAN ) { case 4: PX -= 4; break; case 6: PX += 4; break; }
                if ( TYPE == 3 && DASH == 2 ) { switch( BAN ) { case 4: PX -= 2; break; case 6: PX += 2; break; } }
            }
            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
            act_churi( 2 );
        break;
        case 5: //¯aÍA­i
            switch( TYPE )
            {
                case 1: //ÅE
                    switch( SPECIAL_TYPE )
                    {
                        case 1: //µ¡ŸA‰E
                            if ( act > 1 ) { PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; }
                            if ( act == 2 ) { switch( Dir ) { case 2: PX -= 4; break; case 1: PX += 4; break; } }
                            act_churi( 2 );
                            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                        break;
                        case 2: //´aÌaÈaÌaš‰E
                            if ( act == 0 || act == 7 || act == 8 || act ==9 || act == 10 ) { PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; }
                            switch( Dir ) { case 2: PX -= 3; break; case 1: PX += 3; break; }
                            if ( (act == 4 || act == 6) && TIME == 0 ) voc_play( 0 );
                            act_churi( 2 );
                            if ( act > 6 ) if ( next++ < 3 ) act = 3;
                            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                        break;
                        case 3: //´a¹¡‰E
                            if ( act == 3 && TIME == 0 ) jang_create();
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 4: //¤i—i´á Ÿ¡ ¿¢‹¡
                            if ( act == 1 ) { switch( Dir ) { case 2: PX -= 4; break; case 1: PX += 4; break; } }
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 5: //ÅE· Ï©¬i‹¡
                            PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--;
                            if ( (act == 4 || act == 6) && TIME == 0 ) voc_play( 0 );
                            act_churi( 2 );
                            if ( act > 6 ) if ( next++ < 3 ) act = 3;
                            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                        break;
                    }
                break;
                case 2: //ˆa·©
                    switch( SPECIAL_TYPE )
                    {
                        case 1: //¤e”iÇ¢
                            if ( act > 1 ) { PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; }
                            if ( act < 6 ) { switch( Dir ) { case 2: PX -= 3; break; case 1: PX += 3; break; } }
                            act_churi( 2 );
                            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                         break;
                         case 2: //­¡“¢¦‘
                            if ( act == 2 && TIME == 0 ) jang_create();
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                         break;
                         case 3: //Ï©¬i‹¡
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                         break;
                    }
                break;
                case 3: //·¡µ¡Ÿ¡
                    switch( SPECIAL_TYPE )
                    {
                        case 1: //·¡µ¡Ÿ¡· µ¡ŸA‰E
                            if ( act > 2 ) { PY -= GY; if ( GY2++ >= 1 ) GY2 = 0, GY--; }
                            if ( act == 3 ) { switch( Dir ) { case 2: PX -= 3; break; case 1: PX += 3; break; } }
                            act_churi( 2 );
                            if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                        break;
                        case 2: //·¡µ¡Ÿ¡· ¸wÎ—
                            if ( act == 2 && TIME == 0 ) jang_create();
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 3: //Ï©¬i‹¡
                            if ( act <= 3 ) { switch( Dir ) { case 1: PX += 4; break; case 2: PX -= 4; break; } }
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                        break;
                    }
                break;
            }
        break;
        case 6: //”®á
            switch( TYPE )
            {
                case 1: case 2:  //ÅE, ˆa·©
                    if ( act > 0 ) { PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--; }
                    if ( act > 0 ) { switch( Dir ) { case 2: PX -= 8; break; case 1: PX += 8; break; } }
                    act_churi( 2 );
                    if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                break;
                case 3:
                    if ( ATTACK == ON )
                    {
                        switch( Dir ) { case 1: PX += 6; break; case 2: PX -= 6; break; }
                        PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--;
                        act_churi( 2 );
                        if ( PY > PY2 ) voc_play( 9 ), PY = PY2, at_off();
                    }
                    if ( ATTACK == OFF )
                    {
                        switch( Dir ) { case 1: PX += 8; break; case 2: PX -= 8; break; }
                        if ( TIME++ > TI[act] ) TIME = 0, act++;
                        if ( act > last_act ) act = last_act, at_off();
                    }
                break;
            }
        break;
        case 7: // x‹¡
            switch( TYPE )
            {
                case 1: case 2: case 3: //ÅE, ˆa·©, ·¡µ¡Ÿ¡
                    switch( DAMAGE_TYPE )
                    {
                        case 1:
                            if ( ENERGY <= 0 ) DAMAGE_TYPE = 2, damage_create();
                            if ( TIME++ > TI[act] ) TIME = 0, act++;
                            if ( act > last_act ) act = last_act, at_off();
                        break;
                        case 2:
                            act_churi( 2 );
                            PY -= GY; if ( GY2++ > 1 ) GY2 = 0, GY--;
                            if ( next == 1 ) ting( random( X[ACT[act]] ) + PX + sx[act], random( 15 ) + PY + sy[act], 2 );
                            if ( PY > PY2 )
                            {
                                switch( next )
                                {
                                    case 0: voc_play( 11 ), next = 1; GY = 2; GY2 = 0; break;
                                    case 1:
                                        if ( ENERGY <= 0 )
                                        {
                                            switch( TYPE )
                                            {
                                                case 1: case 2: voc_play( 33 ); break;
                                                case 3: voc_play( 34 ); break;
                                            }
                                            DATSU--;
                                            if ( DATSU > 0 )
                                            {
                                                for ( i2 = 0; i2 < 30; i2++ ) if ( EN[i2].LIFE == 1 && EN[i2].MV == 1 ) EN[i2].DAMAGE_TYPE = 2, EN[i2].damage_create(), EN[i2].ENERGY -= 10;
                                                ENERGY = 288, stand_create();
                                            }
                                            if ( DATSU <= 0 ) LIFE = 0, START = -1, CONTI = 9, asci[_ENTER] = 0;
                                        }
                                        else stand_create();
                                    break;
                                }
                                PY = PY2;
                            }
                            switch( Dir ) { case 1: PX -= 3; break; case 2: PX += 3; break; }
                        break;
                    }
                break;
            }
        break;
        case 8: //·©´á¬á‹¡
            switch( TYPE )
            {
                case 1: case 2: case 3://ÅE, ˆa·©, ·¡µ¡Ÿ¡
                    if ( TIME++ > TI[act] ) TIME = 0, act++;
                    if ( act > last_act ) act = last_act, at_off();
                break;
            }
        break;
        case 9: case 10: //¸s´a ”å»¡‹¡, º“‹¡ ¡¡­e
            switch( TYPE )
            {
                case 1: case 2: case 3: //ÅE, ˆa·©. ·¡µ¡Ÿ¡
                    if ( TIME++ > TI[act] ) TIME = 0, act++;
                    if ( act > last_act ) act = last_act, at_off();
                break;
            }
        break;
    }
}


