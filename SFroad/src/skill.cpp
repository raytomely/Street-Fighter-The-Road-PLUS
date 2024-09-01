//"SKILL.C" ���ΰ����� ��� ����

#include "value.h"
#include "extern.h"

int stream[10], c=0;

//���� �������� ���Ҷ�
int ken1[6][3]={ {6,2,6},   // ������
                  {6,4},	//����Ÿ�ĶѰ�
                  {6,2},    //������
                  {2,2},    //�ߵ�� ���� ���
				  {8,8},
				  {6,6}		//�뽬
};
//���� ������ ���Ҷ�
int ken2[6][3]={ {4,2,4},   //������
                  {4,6},	//����Ÿ�Ѱ�
                  {4,2},	//������
                  {2,2},	//�ߵ�� ���� ���
				  {8,8},
				  {4,4}		//�뽬
};

//������ �������� �ٶ󺸰� ������
int guile1[3][3]={ {8,2},   // �ݴ�ű
				   {6,4},	//�Ҵк�
				   {6,6}	//�뽬
};

//������ ������ �ٶ󺸰� ������
int guile2[3][3]={ {8,2},   // �ݴ�ű
				   {4,6},	//�Ҵк�
				   {4,4}	//�뽬
};

//�̿����� �������� ���Ҷ�
int iori1[6][3]={ {6,2,6},   // �̿����� ������
                  {6,2},    //�̿����� ������
				  {6,6}		//�뽬
};
//�̿����� ������ ���Ҷ�
int iori2[6][3]={ {4,2,4},   //�̿����� ������
                  {4,2},	//�̿����� ������
				  {4,4}		//�뽬
};

int check();

void skill( void )
{
     Time++;

     if ( c >= 9 ) c = 0;

     if ( asci[_RTKEY] && NA.RKEY == ON ) { asci[_RTKEY] = 0, stream[c] = 6; c++; }
     if ( asci[_LTKEY] && NA.LKEY == ON ) { asci[_LTKEY] = 0, stream[c] = 4; c++; }
     if ( asci[_DNKEY] && NA.DKEY == ON ) { asci[_DNKEY] = 0, stream[c] = 2; c++; }
     if ( asci[_UPKEY] && NA.UKEY == ON ) { asci[_UPKEY] = 0, stream[c] = 8; c++; }
     if ( press_key != 0 ) { Time2 = Time; press_key = 0; }

     if ( (Time - Time2) > 10 && Time2 != 0 ) { for ( i = 0; i < 10; i++ ) stream[i] = 0; Time = 0; Time2 = 0; c = 0; }
}

int check( void )
{
    int s=stream[c-1], s1=stream[c-2], s2=stream[c-3];//, s3=stream[c-4];

    if ( c < 2 ) return 0;

    switch( NA.TYPE )
    {
        case 1:  //��
            switch( NA.Dir )
            {
                case 1:
                    if( s == ken1[0][0] && s1 == ken1[0][1] && s2 == ken1[0][2] ) return 1; //������
                    if( s == ken1[1][0] && s1 == ken1[1][1] ) return 2; //����Ÿ�ĶѰ�
                    if( s == ken1[2][0] && s1 == ken1[2][1] ) return 3; //������
                    if( s == ken1[3][0] && s1 == ken1[3][1] ) return 4; //�ߵ�� ���� �ظ���
					if( s == ken1[4][0] && s1 == ken1[4][1] ) return 4;
					if( s == ken1[5][0] && s1 == ken1[5][1] ) return 5; //�뽬
				break;
                case 2:
                    if( s == ken2[0][0] && s1 == ken2[0][1] && s2 == ken2[0][2] ) return 1;
                    if( s == ken2[1][0] && s1 == ken2[1][1] ) return 2;
                    if( s == ken2[2][0] && s1 == ken2[2][1] ) return 3;
                    if( s == ken2[3][0] && s1 == ken2[3][1] ) return 4;
					if( s == ken2[4][0] && s1 == ken2[4][1] ) return 4;
					if( s == ken2[5][0] && s1 == ken2[5][1] ) return 5; //�뽬
                break;
            }
        break;
		case 2:  //����
            switch( NA.Dir )
            {
                case 1:
                    if( s == guile1[0][0] && s1 == guile1[0][1] ) return 1; //�ݴ�ű
                    if( s == guile1[1][0] && s1 == guile1[1][1] ) return 2; //�ҴϺ�
                    if( s == guile1[2][0] && s1 == guile1[2][1] ) return 3; //�뽬
				break;
     		    case 2:
                    if( s == guile2[0][0] && s1 == guile2[0][1] ) return 1; //�ݴ�ű
                    if( s == guile2[1][0] && s1 == guile2[1][1] ) return 2; //�ҴϺ�
                    if( s == guile2[2][0] && s1 == guile2[2][1] ) return 3; //�뽬
				break;
            }
        break;
		case 3:  //�̿���
            switch( NA.Dir )
            {
                case 1:
                    if( s == iori1[0][0] && s1 == iori1[0][1] && s2 == iori1[0][2] ) return 1; //�̿����� ������
                    if( s == iori1[1][0] && s1 == iori1[1][1] ) return 2; //�̿����� ������
                    if( s == iori1[2][0] && s1 == iori1[2][1] ) return 3; //�뽬
				break;
                case 2:
                    if( s == iori2[0][0] && s1 == iori2[0][1] && s2 == iori2[0][2] ) return 1; //�̿����� ������
                    if( s == iori2[1][0] && s1 == iori2[1][1] ) return 2; //�̿����� ������
                    if( s == iori2[2][0] && s1 == iori2[2][1] ) return 3; //�뽬
				break;
            }
        break;
    }
    return 0;
}
