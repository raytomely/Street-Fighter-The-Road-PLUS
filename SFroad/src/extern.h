#ifndef EXTERN_H
#define EXTERN_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

// stubbed specifiers
#define __far
#define __interrupt

union REGS;

// stubbed functions
#ifdef __cplusplus
extern "C" {
#endif
    int stub1(int a, int b);
    int stub2(int a, union REGS *b, union REGS *c);
    int stub3(int a, void (*b)());
#ifdef __cplusplus
}
#endif

#define outp(a,b) stub1(a,b)
#define outpw(a,b) stub1(a,b)
#define int386(a,b,c) stub2(a,b,c)
#define inp(x) stub1(x,0)
#define _dos_getvect(x) old_int09
#define _dos_setvect(a, b) stub3(a,b)
#define _disable()
#define _enable()

union REGS   // placeholder REGS union
{
    struct
    {
        int eax;
    }x;
    struct
    {
        unsigned char al;
        unsigned char ah;
    }h;
};

// from lyhwat.cpp

// º¶aÇ¡
#define _ESC       0x01
#define _UPKEY     0x48
#define _DNKEY     0x50
#define _LTKEY     0x4b
#define _RTKEY     0x4d
#define _TAB       0x0f
#define __SPACE     0x39
#define _BACKSPACE 0x0e
#define _ALT       0x38
#define _CTRL      0x1d
#define _ENTER     0x1c
#define _INS       0x52
#define _DEL       0x53
#define _HOME      0x47
#define _END       0x4f
#define _PGUP      0x49
#define _PGDN      0x51
#define _LSHIFT    0x2a
#define _RSHIFT    0x36

// Ðq® Ç¡
#define _F1        0x3b
#define _F2        0x3c
#define _F3        0x3d
#define _F4        0x3e
#define _F5        0x3f
#define _F6        0x40
#define _F7        0x41
#define _F8        0x42
#define _F9        0x43
#define _F10       0x44
#define _F11       0x85
#define _F12       0x86

// ®•¸aÇ¡
#define _N1        0x02
#define _N2        0x03
#define _N3        0x04
#define _N4        0x05
#define _N5        0x06
#define _N6        0x07
#define _N7        0x08
#define _N8        0x09
#define _N9        0x0a
#define _N0        0x0b

// Shift + Ðq®Ç¡
#define _SF1       0x54
#define _SF2       0x55
#define _SF3       0x56
#define _SF4       0x57
#define _SF5       0x58
#define _SF6       0x59
#define _SF7       0x5a
#define _SF8       0x5b
#define _SF9       0x5c
#define _SF10      0x5d
#define _SF11      0x89
#define _SF12      0x8a

// Alt + Ðq®Ç¡
#define _AF1       0x68
#define _AF2       0x69
#define _AF3       0x6a
#define _AF4       0x6b
#define _AF5       0x6c
#define _AF6       0x6d
#define _AF7       0x6e
#define _AF8       0x6f
#define _AF9       0x70
#define _AF10      0x71
#define _AF11      0x8b
#define _AF12      0x8c

// Ctrl + Ðq®Ç¡
#define _CF1       0x5e
#define _CF2       0x5f
#define _CF3       0x60
#define _CF4       0x61
#define _CF5       0x62
#define _CF6       0x63
#define _CF7       0x64
#define _CF8       0x65
#define _CF9       0x66
#define _CF10      0x67
#define _CF11      0x87
#define _CF12      0x88

// ´iÌa¥U Ç¡
#define _A         0x1e
#define _B         0x30
#define _C         0x2e
#define _D         0x20
#define _E         0x12
#define _F         0x21
#define _G         0x22
#define _H         0x23
#define _I         0x17
#define _J         0x24
#define _K         0x25
#define _L         0x26
#define _M         0x32
#define _N         0x31
#define _O         0x18
#define _P         0x19
#define _Q         0x10
#define _R         0x13
#define _S         0x1f
#define _T         0x14
#define _U         0x16
#define _V         0x2f
#define _W         0x11
#define _X         0x2d
#define _Y         0x15
#define _Z         0x2c

#define SWAP(a,b)  {a^=b;b^=a;a^=b;}
#define randomize() srand(time(NULL))
#define random(i) (rand()%i)
#define COPY(A,B) for(loop=0;loop<32;loop++) *(B+loop)=*(A+loop);
#define OR(A,B) for(loop=0;loop<32;loop++) *(B+loop)|=*(A+loop);

extern unsigned char press_key;
extern char *page[10];
extern unsigned char scan[128], asci[128];

void put_sprite( int x1, int y1, int x2, int y2, char *p, int d );
void read_font( void );
void page_on( void );
void page_off( void );
void TEXTmode( void );
void clear_page( int p );
void fade_run( int p );
void gul( int x, int y, const char *s, int color, int page );
void read_pcx( const char *name, int num );
void copy_image( char *src, int x1, int y1, int x2, int y2, char *des, int x3, int y3 );
void copy_page( char *souscrn, char *tarscrn );
void box_fill( int s_x, int s_y, int e_x, int e_y, char color, int pa );
void draw_box( int x1, int y1, int x2, int y2, char col, int p );
void lyh_gul( int x, int y, int jaju, int p );

void init_key(void);
void del_key(void);
void __interrupt __far new_int09();
#define processKeyboardInput() new_int09()

//from etc01.cpp

void start( void );
void sprite_load( const char *name );
void gl_start( void );
void end( void );

//from etc02.cpp

void ting( int xx, int yy, int t );
void voc_play( int VC );
void voc_play2( int VC );
void FRAME( int mSec );
void init_wav( void );

//from skill.cpp

extern int stream[10];

void skill( void );
int check( void );

//from enemy2.cpp

void enemy_init( void );

#endif // EXTERN_H
