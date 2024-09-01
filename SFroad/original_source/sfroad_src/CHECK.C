//"CHECK.C"

void PLAYER :: enemy_check( void )
{
    switch( FLAG )
    {
        case 3:  //º â·i Òá–Ÿi˜
            if ( at[act] != 0 )
            {
                HIT_FLAG = OFF;
                for ( i3 = 0; i3 < 30; i3++ )
                {
                    if (
                        (AT_X1 < EN[i3].DT_X2)
                        && (EN[i3].DT_X1 < AT_X2 )
                        && (AT_Y1 < EN[i3].DT_Y2 )
                        && (EN[i3].DT_Y1 < AT_Y2)
                        && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                        && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                        && EN[i3].DAMAGE == OFF && EN[i3].LIFE == 1 && EN[i3].SPECIAL == OFF
                       )
                    {
                        EN[i3].DAMAGE_TYPE = at[act]; EN[i3].MV = 1;
                        if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                        if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2;
                        if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                        if ( EN[i3].JUMP == OFF )
                        {
                            if ( TYPE == 1 && HIT >= 2 && (scan[_UPKEY] || scan[_DNKEY]) ) { japki_create(), EN[i3].DAMAGE_TYPE = 4; EN[i3].damage_create(); HIT = 0; break; }
                            if ( TYPE == 2 && HIT >= 2 && (scan[_UPKEY] || scan[_DNKEY]) ) { japki_create(), EN[i3].DAMAGE_TYPE = 6; EN[i3].damage_create(); HIT = 0; break; }
                            if ( TYPE == 3 && HIT >= 2 && (scan[_UPKEY] || scan[_DNKEY]) ) { japki_create(), EN[i3].DAMAGE_TYPE = 7; EN[i3].damage_create(); HIT = 0; break; }
                        }
                        EN[i3].damage_create();
                        HIT_FLAG = ON; if ( TIME == 0 && EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                        if ( HIT >= 3 ) EN[i3].TI[EN[i3].act] += 4;
                    }
                }
                if ( HIT_FLAG == ON )
                {
                    switch( HIT )
                    {
                        case 0: case 1: voc_play( 5 ); break;
                        case 2: voc_play( 6 ); break;
                        case 3: voc_play( 7 ); break;
                        case 4: voc_play( 7 ); HIT = 0; break;
                    }
                    if ( HIT > 4 ) TI[act] += 4, HIT = 0; at[act] = 0;
                    HIT++; HIT_TIME = 0;
                }

                //if ( HIT_FLAG == OFF && HIT_TIME++ > 5 ) HIT = 0, HIT_TIME = 0;
            }
            for ( i3 = 0; i3 < 10; i3++ )
            {
                if (
                    (AT_X1 < IT2[i3].PX + ETX[IT2[i3].ACT])
                    && (IT2[i3].PX < AT_X2 - 20)
                    && (BADAK_Y - 10 < IT2[i3].PY + ETY[IT2[i3].ACT])
                    && (IT2[i3].PY + ETY[IT2[i3].ACT] - 10 < BADAK_Y)
                    && IT2[i3].LIFE == 1 && HIT_FLAG == OFF
                   )
                {
                    at[act] = 0, IT2[i3].LIFE = 0; NA.joopki_create();
                    ENERGY += IT2[i3].E; if ( ENERGY > 288 ) ENERGY = 288;
                    switch( IT2[i3].TYPE )
                    {
                        case 1: case 2: case 3: case 4: case 6: case 9: case 10: case 11:
                            voc_play( 20 ); break;
                        default: voc_play( 21 ); break;
                    }
                    break;
                }
            }
        break;
        case 4:
            HIT_FLAG = OFF;
            if ( at[act] != 0 )
            {
                for ( i3 = 0; i3 < 30; i3++ )
                {
                    if (
                        (AT_X1 < EN[i3].DT_X2)
                        && (EN[i3].DT_X1 < AT_X2 )
                        && (AT_Y1 < EN[i3].DT_Y2 )
                        && (EN[i3].DT_Y1 < AT_Y2)
                        && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                        && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                        && EN[i3].DAMAGE == OFF && EN[i3].LIFE == 1 && EN[i3].SPECIAL == OFF
                       )
                    {
                        EN[i3].DAMAGE_TYPE = 2; EN[i3].MV = 1;
                        if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                        if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                        EN[i3].damage_create();
                        HIT_FLAG = ON; if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                    }
                }
                if ( HIT_FLAG == ON )
                {
                    at[act] = 0; voc_play( 7 );
                    HIT_FLAG = OFF;
                }
            }
        break;
        case 5:
            HIT_FLAG = OFF;
            switch( TYPE )
            {
                case 1: //ÅE
                    if ( at[act] != 0 )
                    {
                        for ( i3 = 0; i3 < 30; i3++ )
                        {
                            if (
                                (AT_X1 < EN[i3].DT_X2)
                                && (EN[i3].DT_X1 < AT_X2 )
                                && (AT_Y1 < EN[i3].DT_Y2 )
                                && (EN[i3].DT_Y1 < AT_Y2)
                                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE != 2 && EN[i3].DAMAGE_TYPE != 3 && EN[i3].SPECIAL == OFF
                               )
                            {
                                EN[i3].DAMAGE_TYPE = at[act]; EN[i3].MV = 1;
                                if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                                if ( SPECIAL_TYPE == 2 && next >= 2 ) EN[i3].DAMAGE_TYPE = 3;
                                if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2;
                                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                                EN[i3].damage_create();
                                HIT_FLAG = ON;
                                switch( SPECIAL_TYPE )
                                {
                                    default: if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 ); break;
                                    case 4: if ( TIME == 0 && EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 ); break;
                                }
                            }
                        }
                    }
                    if ( HIT_FLAG == ON )
                    {
                        if ( VC_TIME++ > 2 && SPECIAL_TYPE == 4 ) VC_TIME = 0, voc_play( 7 );
                        if ( SPECIAL_TYPE != 4 ) voc_play( 7 );
                        if ( SPECIAL_TYPE != 3 ) FRAME( 15 );
                        HIT_FLAG = OFF;
                    }
                break;
                case 2: //ˆa·©
                    if ( at[act] != 0 && SPECIAL_TYPE != 3 )
                    {
                        for ( i3 = 0; i3 < 30; i3++ )
                        {
                            if (
                                (AT_X1 < EN[i3].DT_X2)
                                && (EN[i3].DT_X1 < AT_X2 )
                                && (AT_Y1 < EN[i3].DT_Y2 )
                                && (EN[i3].DT_Y1 < AT_Y2)
                                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE != 5 && EN[i3].SPECIAL == OFF
                               )
                            {
                                EN[i3].DAMAGE_TYPE = at[act]; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                                if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2; EN[i3].MV = 1;
                                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                                EN[i3].damage_create();
                                HIT_FLAG = ON;
                                if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                            }
                        }
                    }
                    if ( at[act] != 0 && SPECIAL_TYPE == 3 )
                    {
                        for ( i3 = 0; i3 < 30; i3++ )
                        {
                            if (
                                (DT_X1 < EN[i3].DT_X2)
                                && (EN[i3].DT_X1 < DT_X2 )
                                && (DT_Y1 < EN[i3].DT_Y2 )
                                && (EN[i3].DT_Y1 < DT_Y2)
                                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE == OFF && EN[i3].SPECIAL == OFF
                               )
                            {
                                EN[i3].DAMAGE_TYPE = at[act]; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                                if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2;
                                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                                EN[i3].damage_create(); EN[i3].MV = 1;
                                HIT_FLAG = ON;
                                if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                            }
                        }
                    }
                    if ( HIT_FLAG == ON )
                    {
                        if ( SPECIAL_TYPE == 1 ) FRAME( 15 );
                        voc_play( 7 );
                        HIT_FLAG = OFF;
                    }
                break;
                case 3: //·¡µ¡Ÿ¡
                    if ( at[act] != 0 )
                    {
                        for ( i3 = 0; i3 < 30; i3++ )
                        {
                            if (
                                (AT_X1 < EN[i3].DT_X2)
                                && (EN[i3].DT_X1 < AT_X2 )
                                && (AT_Y1 < EN[i3].DT_Y2 )
                                && (EN[i3].DT_Y1 < AT_Y2)
                                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE != 2 && EN[i3].DAMAGE_TYPE != 3 && EN[i3].SPECIAL == OFF
                               )
                            {
                                EN[i3].DAMAGE_TYPE = at[act]; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                                if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2;
                                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                                EN[i3].damage_create(); EN[i3].MV = 1;
                                HIT_FLAG = ON;
                                if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                            }
                        }
                    }
                    if ( HIT_FLAG == ON )
                    {
                        voc_play( 7 ), FRAME( 15 ); HIT_FLAG = OFF;
                    }
                break;
            }
        break;
        case 6:
            switch( TYPE )
            {
                case 1: case 2: case 3: //ÄË, °¡ÀÏ
                    if ( at[act] != 0 )
                    {
                        for ( i3 = 0; i3 < 30; i3++ )
                        {
                            if (
                                (AT_X1 < EN[i3].DT_X2)
                                && (EN[i3].DT_X1 < AT_X2 )
                                && (AT_Y1 < EN[i3].DT_Y2 )
                                && (EN[i3].DT_Y1 < AT_Y2)
                                && ( (BADAK_Y < EN[i3].BADAK_Y + 10)
                                && (BADAK_Y > EN[i3].BADAK_Y - 10) )
                                && EN[i3].LIFE == 1 && EN[i3].DAMAGE_TYPE != 2 && EN[i3].DAMAGE_TYPE != 3 && EN[i3].SPECIAL == OFF
                               )
                            {
                                EN[i3].DAMAGE_TYPE = at[act]; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                                if ( act == 1 && TIME >= 6 && TYPE == 1 ) EN[i3].DAMAGE_TYPE = 2;
                                if ( act == 2 && TIME >= 2 && TYPE == 2 ) EN[i3].DAMAGE_TYPE = 2;
                                if ( act == 2 && TYPE == 3 ) EN[i3].DAMAGE_TYPE = 2;
                                if ( EN[i3].JUMP == ON ) EN[i3].DAMAGE_TYPE = 2;
                                if ( EN[i3].SHIELD == ON ) EN[i3].DAMAGE_TYPE = 9;
                                EN[i3].damage_create(); voc_play( 7 ); EN[i3].MV = 1;
                                if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 ); break;
                            }
                        }
                    }
                break;
            }
        break;
    }
    for ( ii = 0; ii < 30; ii++ )
    {
        if ( EN[ii].THROW == ON )
        {
            HIT_FLAG = OFF;
            for ( i3 = 0; i3 < 30; i3++ )
            {
                if (
                    (EN[ii].PX + EX[EN[ii].ACT[EN[ii].act]] + EN[ii].sx[EN[ii].act] < EN[i3].PX + EX[EN[i3].ACT[EN[i3].act]] + EN[i3].sx[EN[i3].act] )
                    && (EN[i3].PX + EN[i3].sx[EN[i3].act] < EN[ii].PX + EX[EN[ii].ACT[EN[ii].act]] + EN[ii].sx[EN[ii].act] )
                  //&& (EN[ii].DT_Y1 < EN[i3].DT_Y2 )
                  //&& (EN[i3].DT_Y1 < EN[ii].DT_Y2)
                    && ( (EN[ii].PY2 + EN[ii].SY < EN[i3].PY + EY[EN[i3].ACT[EN[i3].act]] + EN[i3].sy[EN[i3].act] + 9 )
                    && (EN[ii].PY2 + EN[ii].SY > EN[i3].PY + EY[EN[i3].ACT[EN[i3].act]] + EN[i3].sy[EN[i3].act] - 6) )
                    && EN[i3].LIFE == 1 && EN[i3].DAMAGE == OFF && EN[i3].THROW == OFF
                   )
                {
                    EN[i3].DAMAGE_TYPE = 2; if ( EN[i3].SHIELD == OFF ) EN[i3].ENERGY -= POW;
                    EN[i3].damage_create();
                    HIT_FLAG = ON, EN[i3].MV = 1;
                    if ( EN[i3].SHIELD == OFF ) ting( random( EX[EN[i3].ACT[EN[i3].act]] ) + EN[i3].PX, random( (EY[EN[i3].ACT[EN[i3].act]]/2) ) + EN[i3].PY, 1 );
                }
            }
            for ( i3 = 0; i3 < 10; i3++ )
            {
                if (
                    (EN[ii].PX + EX[EN[ii].ACT[EN[ii].act]] + EN[ii].sx[EN[ii].act] < IT[i3].PX + ETX[IT[i3].ACT])
                    && (IT[i3].PX < EN[ii].PX + EX[EN[ii].ACT[EN[ii].act]] + EN[ii].sx[EN[ii].act] )
                    && ( (EN[ii].PY2 + EN[ii].SY < IT[i3].PY + ETY[IT[i3].ACT] + 8)
                    && (EN[ii].PY2 + EN[ii].SY > IT[i3].PY + ETY[IT[i3].ACT] - 6) )
                    && IT[i3].LIFE == 1
                   )
                {
                    at[act] = 0; IT[i3].LIFE = 2; IT2[i3].item2_create( IT[i3].PX + ETX[IT[i3].ACT]/2, IT[i3].PY + ETY[IT[i3].ACT] - 10, IT[i3].TYPE2 );
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
            if ( HIT_FLAG == ON )
            {
                voc_play( 10 ); FRAME( 25 );
                HIT_FLAG = OFF;
            }
        }
    }
    if ( at[act] != 0 ) //´a·¡ÉQ ÁAÇa
    {
        for ( i3 = 0; i3 < 10; i3++ )
        {
            if (
                (AT_X1 < IT[i3].PX + ETX[IT[i3].ACT])
                && (IT[i3].PX < AT_X2 )
                && (BADAK_Y - 10 < IT[i3].PY + ETY[IT[i3].ACT])
                && (IT[i3].PY + ETY[IT[i3].ACT] - 10 < BADAK_Y)
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

void ENEMY :: player_check( void )
{
    if ( at[act] != 0 )
    {
        if (
            (AT_X1 < NA.DT_X2)
            && (NA.DT_X1 < AT_X2 )
            && (AT_Y1 < NA.DT_Y2 )
            && (NA.DT_Y1 < AT_Y2)
            && ( (BADAK_Y < NA.BADAK_Y + 9)
            && (BADAK_Y > NA.BADAK_Y - 4) )
            && NA.DAMAGE == OFF && NA.SPECIAL == OFF && LIFE == 1 && NA.DAM_C-- < 0
           )
        {
            NA.DAMAGE_TYPE = at[act], NA.ENERGY -= POW;
            at[act] = 0; if ( NA.JUMP == ON || NA.DASH == ON ) NA.DAMAGE_TYPE = 2;
            NA.damage_create(); NA.DAM_C = 1; voc_play( 7 );
            ting( random( X[NA.ACT[NA.act]] ) + NA.PX, random( (Y[NA.ACT[NA.act]]/2) ) + NA.PY, 1 );
        }
    }
    //draw_box( AT_X1, AT_Y1, AT_X2, AT_Y2, 255, 1 );
    //draw_box( EN.AT_X1, EN.AT_Y1, EN.AT_X2, EN.AT_Y2, 255, 1 );
    //draw_box( DT_X1, DT_Y1, DT_X2, DT_Y2, 254, 1 );
    //draw_box( EN.DT_X1, EN.DT_Y1, EN.DT_X2, EN.DT_Y2, 254, 1 );
}



