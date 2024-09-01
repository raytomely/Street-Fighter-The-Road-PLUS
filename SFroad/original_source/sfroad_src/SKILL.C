//"SKILL.C" 주인공들의 기술 패턴

int stream[10], c=0;

//켄이 오른쪽을 향할때
int ken1[6][3]={ {6,2,6},   // 오류겐
                  {8,2},	//아파타파뚜겐
                  {6,2,4},    //아조겐
                  {2,2},    //발들어 내리 찍기
				  {8,8},
				  {6,6}		//대쉬
};
//켄이 왼쪽을 향할때
int ken2[6][3]={ {4,2,4},   //오류겐
                  {8,2},	//아파타뚜겐
                  {4,2,6},	//아조겐
                  {2,2},	//발들어 내리 찍기
				  {8,8},
				  {4,4}		//대쉬
};

//가일이 오른쪽을 바라보고 있을때
int guile1[3][3]={ {8,2},   // 반달킥
				   {6,2,4},	//소닉붐
				   {6,6}	//대쉬
};

//가일이 왼쪽을 바라보고 있을때
int guile2[3][3]={ {8,2},   // 반달킥
				   {4,2,6},	//소닉붐
				   {4,4}	//대쉬
};

//이오리가 오른쪽을 향할때
int iori1[6][3]={ {6,2,6},   // 이오리의 오류겐
                  {6,2,4},    //이오리의 아조겐
				  {6,6}		//대쉬
};
//이오리가 왼쪽을 향할때
int iori2[6][3]={ {4,2,4},   //이오리의 오류겐
                  {4,2,6},	//이오리의 아조겐
				  {4,4}		//대쉬
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
    int s=stream[c-1], s1=stream[c-2], s2=stream[c-3], s3=stream[c-4];

    if ( c < 2 ) return 0;

    switch( NA.TYPE )
    {
        case 1:  //켄
            switch( NA.Dir )
            {
                case 1:
                    if( s == ken1[0][0] && s1 == ken1[0][1] && s2 == ken1[0][2] ) return 1; //오류겐
                    if( s == ken1[1][0] && s1 == ken1[1][1] ) return 2; //아파타파뚜겐
                    if( s == ken1[2][0] && s1 == ken1[2][1] && s2 == ken1[2][2]) return 3; //아조겐
                    if( s == ken1[3][0] && s1 == ken1[3][1] ) return 4; //발들어 내리 쌔리기
					if( s == ken1[4][0] && s1 == ken1[4][1] ) return 4; 
					if( s == ken1[5][0] && s1 == ken1[5][1] ) return 5; //대쉬
				break;
                case 2:
                    if( s == ken2[0][0] && s1 == ken2[0][1] && s2 == ken2[0][2] ) return 1;
                    if( s == ken2[1][0] && s1 == ken2[1][1] ) return 2;
                    if( s == ken2[2][0] && s1 == ken2[2][1] && s2 == ken2[2][2] ) return 3;
                    if( s == ken2[3][0] && s1 == ken2[3][1] ) return 4;
					if( s == ken2[4][0] && s1 == ken2[4][1] ) return 4; 
					if( s == ken2[5][0] && s1 == ken2[5][1] ) return 5; //대쉬
                break;
            }
        break;
		case 2:  //가일
            switch( NA.Dir )
            {
                case 1:
                    if( s == guile1[0][0] && s1 == guile1[0][1] ) return 1; //반달킥
                    if( s == guile1[1][0] && s1 == guile1[1][1] && s2 == guile1[1][2] ) return 2; //소니붐
                    if( s == guile1[2][0] && s1 == guile1[2][1] ) return 3; //대쉬
				break;
     		    case 2:
                    if( s == guile2[0][0] && s1 == guile2[0][1] ) return 1; //반달킥
                    if( s == guile2[1][0] && s1 == guile2[1][1] && s2 == guile2[1][2] ) return 2; //소니붐
                    if( s == guile2[2][0] && s1 == guile2[2][1] ) return 3; //대쉬
				break;
            }
        break;
		case 3:  //이오리
            switch( NA.Dir )
            {
                case 1:
                    if( s == iori1[0][0] && s1 == iori1[0][1] && s2 == iori1[0][2] ) return 1; //이오리의 오류겐
                    if( s == iori1[1][0] && s1 == iori1[1][1] && s2 == iori1[1][2] ) return 2; //이오리의 아조겐
                    if( s == iori1[2][0] && s1 == iori1[2][1] ) return 3; //대쉬
				break;
                case 2:
                    if( s == iori2[0][0] && s1 == iori2[0][1] && s2 == iori2[0][2] ) return 1; //이오리의 오류겐
                    if( s == iori2[1][0] && s1 == iori2[1][1] && s2 == iori2[1][2] ) return 2; //이오리의 아조겐
                    if( s == iori2[2][0] && s1 == iori2[2][1] ) return 3; //대쉬
				break;
            }
        break;
    }
    return 0;
}

