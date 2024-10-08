//"ETC02.C" �����a �� �s�a�q�� �១ 2
#include "value.h"
#include "extern.h"

void init_wav( void )
{
    const char *name[50] = { ".\\ARW\\BARAM.ARW", ".\\ARW\\KEN1.ARW",
                       ".\\ARW\\KEN2.ARW", ".\\ARW\\KEN3.ARW",
                       ".\\ARW\\KEN4.ARW", ".\\ARW\\DAM1.ARW",
                       ".\\ARW\\DAM2.ARW", ".\\ARW\\DAM3.ARW",
                       ".\\ARW\\JAPKI.ARW", ".\\ARW\\JIMYUN.ARW",
                       ".\\ARW\\THROW.ARW", ".\\ARW\\KOONG.ARW",
                       ".\\ARW\\GUILE.ARW", ".\\ARW\\U~AK.ARW",
                       ".\\ARW\\U~AK2.ARW", ".\\ARW\\U~AK3.ARW",
                       ".\\ARW\\U~AK4.ARW", ".\\ARW\\DAM4.ARW",
                       ".\\ARW\\EATTACK.ARW", ".\\ARW\\WOMANAK.ARW",
                       ".\\ARW\\ITEMEAT.ARW", ".\\ARW\\ITEMEAT2.ARW",
                       ".\\ARW\\PAPAHA.ARW", ".\\ARW\\DRUM.ARW",
                       ".\\ARW\\BOX.ARW", ".\\ARW\\IORI.ARW",
                       ".\\ARW\\VEGA.ARW", ".\\ARW\\DHALSIM1.ARW",
                       ".\\ARW\\DHALSIM2.ARW", ".\\ARW\\DAM5.ARW",
                       ".\\ARW\\BOSS41.ARW", ".\\ARW\\BOSS42.ARW",
                       ".\\ARW\\CURSOR.ARW", ".\\ARW\\DEAD.ARW",
                       ".\\ARW\\DEAD2.ARW"
	};

    for ( i = 0; i <= 34; i++ )
    {
        Eff[i] = MODLoadSample( name[i] );
    }
}

void voc_play( int VC )
{
    //BARAM.ARW             ���� �ᖁ�a�e ����              0
    //KEN1.ARW              ���A�E                          1
    //KEN2.ARW              �a�a�a�a���E                    2
    //KEN3.ARW              �a���E                          3
    //KEN4.ARW              �E���i�i�� ��������             4
    //DAM1.ARW              �x�� 1                          5
    //DAM2.ARW              �x�� 2                          6
    //DAM3.ARW              �x�� 3                          7
    //JAPKI.ARW             �s�v�i��                        8
    //JIMYUN.ARW            ���e�l�e ����                   9
    //THORW.ARW             ��v�i��                        10
    //KOONG.ARW             �w�A ��ỡ�e ����              11
    //GUILE.ARW             ������                          12
    //U~AK.ARW              �⺂�e ���� 1                   13
    //U~AK2.ARW             �⺂�e ���� 2                   14
    //U~AK3.ARW             �⺂�e ���� 3                   15
    //U~AK4.ARW             �⺂�e ���� 4                   16
    //DAM4.ARW              �i�A �x�e ����                  17
    //EATTACK.ARW           ʗʗ���� �ᷥ�� �i�a�a�e ����   18
    //WOMANAK.ARW           �a�a ���w����                   19
    //ITEMEAT.ARW           �a���Q ��e ���� 1              20
    //ITEMEAT2.ARW          �a���Q ��e ���� 2              21
    //PAPAHA.ARW            �a���Q ���ỡ�e ����            22
    //DRUM.ARW              �a��ɷ ���ỡ�e ����            23
    //BOX.ARW               �b�a ���ỡ�e ����              24
    //IORI.ARW              �������� ϩ�i�� ����            25
    //VEGA.ARW              �A�a�� ����                     26
    //DHALSIM1.ARW          �i���� �a�a                     27
    //DHALSIM2.ARW          �i���� �a�a ������              28
    //DAM5.ARW              �i���� ���A �x�e ����           29
    //BOSS41.ARW            �a�a���᷁ �wΗ                 30
    //BOSS42.ARW            �a�a���᷁ �׸wΗ               31
    //CURSOR.ARW            ��� ����                       32
    //DEAD.ARW              �E,�a�� ���e ����               33
    //DEAD2.ARW             ������ ���e ����                34

    if ( SOUND )
    {
        MODPlaySample( WAV, Eff[VC] ); WAV++; if ( WAV > 6 ) WAV = 1;
    }
}

void voc_play2( int VC )
{
    if ( SOUND )
    {
        MODPlaySample( 7, Eff[VC] );
    }
}

void PAK :: ting_create( int x, int y, int tp )
{
    PX = x, PY = y, TIME = 0, TYPE = tp;
    switch( tp )
    {
        case 1: ACT = 0; break;
        case 2: ACT = random( 4 ) + 7; break;
        case 3: ACT = 11; break;
    }
}

void PAK :: ting_move( void )
{
    if ( LIFE == 1 )
    {
        put_sprite( PX, PY, ETX[ACT], ETY[ACT], ETC[ACT], 1 );
        if ( TIME++ > 1 ) TIME = 0, ACT++;
        switch( TYPE )
        {
            case 1: if ( ACT > 3 ) LIFE = 0; break;
            case 2: if ( ACT > 10 ) LIFE = 0; break;
            case 3: if ( ACT > 15 ) LIFE = 0; break;
        }
    }
}

void ting( int xx, int yy, int t )
{
    switch( t )
    {
        case 1:
            for ( ii = 0; ii < 30; ii++ )
            {
                if ( TN[ii].LIFE == 0 )
                {
                    TN[ii].ting_create( xx, yy, t );
                    TN[ii].LIFE = 1; break;
                }
            }
        break;
        case 2:
            if ( TN[0].TIME2++ > 0 )
            {
                for ( ii = 0; ii < 30; ii++ )
                {
                    if ( TN[ii].LIFE == 0 )
                    {
                        TN[ii].ting_create( xx, yy, t ), TN[0].TIME2 = 0;
                        TN[ii].LIFE = 1; break;
                    }
                }
            }
        break;
        case 3:
            for ( ii = 0; ii < 30; ii++ )
            {
                if ( TN[ii].LIFE == 0 )
                {
                    TN[ii].ting_create( xx, yy, t );
                    TN[ii].LIFE = 1; break;
                }
            }
        break;
    }
}

void ITEM :: item_create( int x, int y, int type, int type2 ) //�������e �a���Q
{
    PX = x, PY = y, TYPE = type, COUNT = 0, FLAG = 0;
    LIFE = 1, TIME = 0, TYPE2 = type2;
    switch( TYPE )
    {
        case 1: ACT = 16; break; //�����b�a
        case 2: ACT = 18; break; //�A��ɷ
        case 3: ACT = 20; break; //�a���b�a
        case 4: ACT = 22; break; //ɷ�a��ɷ
        case 5: ACT = 24; break; //�e�e
        case 6: ACT = 26; break; //�a��ɷ
    }
}

void ITEM :: item( void )
{
    if ( SCROLL == ON && (NA.DASH == ON || NA.DASH == 2) ) PX -= 4;
    if ( SCROLL == ON && NA.DASH == OFF ) PX -= 3;
    if ( LIFE == 1 )
    {
        put_sprite( PX, PY, ETX[ACT], ETY[ACT], ETC[ACT], 1 );
        //draw_box( PX, PY + ETY[ACT] - 10, PX + ETX[ACT], PY + ETY[ACT], 255, 1 );
        if (
            (NA.PX < PX + ETX[ACT])
            && (PX < NA.PX + NA.SX )
            && (NA.BADAK_Y - 10 < PY + ETY[ACT] )
            && (PY + ETY[ACT] - 10 < NA.BADAK_Y)
           )
        {
            if ( NA.BAN == 2 && NA.JUMP == OFF ) NA.PY -= 2; else NA.PY += 2;
        }
        //draw_box( NA.PX, NA.BADAK_Y - 10, NA.PX + NA.SX, NA.BADAK_Y, 255, 1 );
    }
    if ( LIFE == 2 )
    {
        switch( FLAG )
        {
            case 0: put_sprite( PX, PY, ETX[ACT+1], ETY[ACT+1], ETC[ACT+1], 1 ); if ( TIME++ > 1 ) TIME = 0, FLAG = 1; break;
            case 1: if ( TIME++ > 1 ) TIME = 0, FLAG = 0, COUNT++; break;
        }
        if ( COUNT > 5 ) LIFE = 0;
    }
}

void ITEM2 :: item2_create( int x, int y, int type ) //��e �a���Q
{
    PX = x, PY = y, TYPE = type;
    LIFE = 2, E = 0, TIME = 0;
    ACT = TYPE + 27;
    switch( TYPE )
    {
        case 1: //1 : �a��
            E = 50;
        break;
        case 2: //2 : ��
            E = 45;
        break;
        case 3: //3 : ϡ�a
            E = 100;
        break;
        case 4: //4 : ���a
            E = 55;
        break;
        //5 : �e��
        case 6: //6 : ũ�a
            E = 60;
        break;
        //7 : 10��
        //8 : �wá
        case 9: //9 : Б��a
            E = 200;
        break;
        case 10: //10 : �I
            E = 80;
        break;
        case 11: //11 : �j����
            E = 270;
        break;
    }
    //12 : ������
    //13 : ���a
    //14 : ����
    //15 : ���鷡
}

void ITEM2 :: item2( void )
{
    if ( LIFE == 2 && TIME++ > 20 ) LIFE = 1;
    if ( SCROLL == ON && NA.DASH == ON ) PX -= 4;
    if ( SCROLL == ON && NA.DASH == OFF ) PX -= 3;
    if ( LIFE == 1 ) put_sprite( PX, PY, ETX[ACT], ETY[ACT], ETC[ACT], 1 );
}




