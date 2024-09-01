#ifndef VALUE_H
#define VALUE_H

#include "sound.h"

#define ON		1
#define OFF		0

extern int MAX_NUMBER, X[300], Y[300], i, i2, i3, ei, ii, EX[600], EY[600], ETX[90], ETY[90];
extern char *P[300], *E[600], *ETC[90];
extern int scroll_x, Time, Time2, SOUND, SOUND2, ret;
extern int PYOSI_Y, WAV;

extern int PAGE, ROUND, ROUND2, stage_flag[15], s_flag;
extern int SCROLL, SCROLL_TIME, CLEAR, CLEAR_TIME;
extern int EN_TYPE, EN_PYOSI_TIME, PYOSI, PYOSI_T, PYOSI2, EN_COUNT;
extern int EN1_MAX, EN2_MAX, NEXT_ENEMY, NEXT_ENEMY2;

extern int START, END, START_Y, START_Y2, END_Y, END_Y2;
extern int DATSU, CREDITS, PL_TYPE, CUR_X, CUR_X2;
extern int CONT_TIME, CONTI;

extern word Port;
extern byte IRQ, DRQ;

extern Module *Mus;
extern Sample *Eff[50];

class PLAYER
{
    public:
    int PX, PY, PY2, GY, GY2, GX, GX2, sx[30], sy[30], ACT[30], at[30], act, last_act, TYPE;
    int TI[30], TIME, SX, SY, Dir, Dir2, BAN, SPECIAL_TYPE, DAMAGE_TYPE, DAM_C;
    int WALK, SPECIAL, ATTACK, JUMP, FLAG, MOVE, DAMAGE, next, HIT, DASH, HIT_TIME;
    int UKEY, DKEY, LKEY, RKEY, LIFE, ENERGY, ENERGY2, HIT_FLAG, THROW;
    int JX, JY, JLIFE, JFLAG, JDIR, JTIME, JCOUNT, HIT_TYPE, JACT, MOVE_WAIT;
    int AT_X1, AT_X2, AT_Y1, AT_Y2;
    int DT_X1, DT_X2, DT_Y1, DT_Y2, BADAK_Y, POW;
    int VC_TIME, da_time;

    public:
    void set_SXSY( int t );
    void act_churi( int t );
    void init_player( int PX, int PY, int TYPE );
    void jump_create();
    void punch1_create();
    void punch2_create();
    void punch3_create();
    void s_player();   //���ִ� ���
    void walk_create();
    void special_create();
    void japki_create();
    void joopki_create();
    void dash_create();
    void damage_create();
    void stand_create();
    void jang_create();
    void jang_move();
    void key_churi();
    void player();
    void player_churi();
    void at_off();
    void enemy_check();
    void Ti( int t );
}; extern PLAYER NA;

class ENEMY   //���� Ŭ���� ���
{
    public:
    int PX, PY, PY2, GY, GY2, GX, GX2, sx[30], sy[30], ACT[30], at[30], act, last_act, TYPE;
    int TI[30], TIME, SX, SY, Dir, Dir2, BAN, SPECIAL_TYPE, DAMAGE_TYPE;
    int WALK, SPECIAL, ATTACK, JUMP, FLAG, MOVE, DAMAGE, next, SUN, RANDOM, ATTACK_WAIT;
    int UKEY, DKEY, LKEY, RKEY, LIFE, ENERGY, ENERGY2, COUNT, DAMAGE_TIME;
    int JX, JY, JLIFE, JFLAG, JDIR, JTIME, JCOUNT, ATTACK_TYPE, HIT_TYPE;
    int distance, THROW, DEAD_FLAG, DEAD_TIME, DEAD_F, DEAD_C, MV;
    int AT_X1, AT_X2, AT_Y1, AT_Y2, SHIELD;
    int DT_X1, DT_X2, DT_Y1, DT_Y2, BADAK_Y, POW;
    int pyosi, BOSS;
    int EN_MAX, en_count;

    public:
    void set_SXSY( int t );
    void act_churi( int t );
    void Ti( int t );
    void init_enemy( int PX, int PY, int TYPE, int ENERGY, int MOVE, int MOVETYPE, int DIR );
    void s_enemy();
    void walk_create();
    void jump_create();
    void punch_create();
    void damage_create();
    void stand_create();
    void jang_create();
    void jang_move();
    void enemy();
    void enemy_move();
    void enemy_churi();
    void at_off();
    void player_check();
    void enemy_dead( int t );
    void enemy_dead2();
}; extern ENEMY EN[30];

class PAK
{
    public:
    int PX, PY, LIFE, TIME, ACT, TYPE, TIME2;
    public:
    void ting_create( int x, int y, int type );
    void ting_move();
}; extern PAK TN[30];

class ITEM            //�������e �墉 �a���Q
{
    public:
    int PX, PY, LIFE, TYPE, TYPE2, ACT, TIME, FLAG, COUNT;
    public:
    void item_create( int x, int y, int type, int type2 );
    void item();
}; extern ITEM IT[10];

class ITEM2            //��e �a���Q
{
    public:
    int PX, PY, LIFE, TYPE, ACT, E, TIME;
    public:
    void item2_create( int x, int y, int type );
    void item2();
}; extern ITEM2 IT2[10];



#endif // VALUE_H
