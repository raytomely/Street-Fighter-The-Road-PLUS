#ifndef MODEX_H
#define MODEX_H

//"MODEX.H" µ’≈±≥°∂w °°óa X úa∑°ßaú·ü°

typedef unsigned char BYTE;
typedef signed   char SBYTE;
typedef unsigned char FLAG;
typedef unsigned short COORD;
typedef unsigned short DIST;

#define PLANE_0         0x0102
#define PLANE_1         0x0202
#define PLANE_2         0x0402
#define PLANE_3         0x0802
#define ALL_PLANES      0x0F02
#define READ_PLANE_0    0x0004
#define READ_PLANE_1    0x0104
#define READ_PLANE_2    0x0204
#define READ_PLANE_3    0x0304

// External Variables needed by graphics routines
extern unsigned short width, height, widthBytes, num_pages;
extern unsigned short activeStart, visibleStart, pageSize;
extern unsigned char write_plane, read_plane;
extern unsigned char *RowsX[600];
extern unsigned char line_head[4];
extern unsigned char line_tail[4];
extern unsigned short plane_mask[4];
extern unsigned short read_mask[4];
extern unsigned short text_mask[16];
extern unsigned short page_offset[5];
extern unsigned short page_mask_high[5];
extern unsigned short page_mask_low[5];

// Set various ModeX resolutions
/*void set256x224x256_X(void);
void set256x240x256_X(void);
void set256x256x256_X(void);
void set256x480x256_X(void);
void set320x200x256_X(void);
void set320x240x256_X(void);
void set320x400x256_X(void);
void set320x480x256_X(void);
void set360x200x256_X(void);
void set360x240x256_X(void);

void set360x270x256_X(void);
void set360x360x256_X(void);
void set360x400x256_X(void);
void set360x480x256_X(void);
void set376x282x256_X(void);
void set376x564x256_X(void);
void set400x300x256_X(void);
void set400x600x256_X(void);

COORD get_xres(void);
COORD get_yres(void);

void set_write_plane(unsigned short int plane_mask);
void set_read_plane(unsigned short int plane_mask);*/

#define ATTRCON_ADDR    0x3C0
#define MISC_ADDR       0x3C2
#define VGAENABLE_ADDR  0x3C3
#define SEQU_ADDR       0x3C4
#define GRACON_ADDR     0x3CE
#define CRTC_ADDR       0x3D4
#define STATUS_ADDR     0x3DA

extern unsigned short ModeX_256x224regs[75];
extern unsigned short ModeX_256x240regs[75];
extern unsigned short ModeX_256x256regs[75];
extern unsigned short ModeX_256x480regs[75];
extern unsigned short ModeX_320x200regs[75];
extern unsigned short ModeX_320x240regs[75];
extern unsigned short ModeX_320x400regs[75];
extern unsigned short ModeX_320x480regs[75];
extern unsigned short ModeX_360x200regs[75];
extern unsigned short ModeX_360x240regs[75];
extern unsigned short ModeX_360x270regs[75];
extern unsigned short ModeX_360x360regs[75];
extern unsigned short ModeX_360x400regs[75];
extern unsigned short ModeX_360x480regs[75];
extern unsigned short ModeX_376x282regs[75];
extern unsigned short ModeX_376x564regs[75];
extern unsigned short ModeX_400x300regs[78];
extern unsigned short ModeX_400x600regs[78];


void calc_rows(void);
void setBaseXMode(void);
void outReg(unsigned short *r);
void outRegArray(unsigned short *r, int n);

void set80x25(void);
void set256x224x256_X(void);
void set256x240x256_X(void);
void set256x256x256_X(void);
void set256x480x256_X(void);
void set320x200x256_X(void);
void set320x240x256_X(void);
void set320x400x256_X(void);
void set320x480x256_X(void);
void set360x200x256_X(void);
void set360x240x256_X(void);
void set360x270x256_X(void);
void set360x360x256_X(void);
void set360x400x256_X(void);
void set360x480x256_X(void);
void set376x282x256_X(void);
void set376x564x256_X(void);
void set400x300x256_X(void);
void set400x600x256_X(void);

COORD get_xres(void);
COORD get_yres(void);

void set_write_plane(unsigned short int plane_mask);
void set_read_plane(unsigned short int plane_mask);
void copy_page_x( int pg );

#endif // MODEX_H
