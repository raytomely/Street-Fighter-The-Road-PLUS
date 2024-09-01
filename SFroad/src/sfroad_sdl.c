#include <SDL/SDL.h>
#include <SDL_mixer.h>

#include "extern.h"

void convert_surface(SDL_Surface **surface)
{
    SDL_Surface *temp_surf = &(**surface);
    *surface = SDL_DisplayFormat (temp_surf);
    SDL_FreeSurface(temp_surf);
}

void convert_surface_alpha(SDL_Surface **surface)
{
    SDL_Surface *temp_surf = &(**surface);
    *surface = SDL_DisplayFormatAlpha(temp_surf);
    SDL_FreeSurface(temp_surf);
}

SDL_Surface *create_surface(int width, int height)
{
    SDL_Surface *surface;
    Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif
    surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, rmask, gmask, bmask, amask);
    convert_surface(&surface);
    return surface;
}

SDL_Surface *copy_surface(SDL_Surface *surface)
{
    return SDL_ConvertSurface(surface, surface->format, SDL_SWSURFACE);
}

int get_file_size(FILE* file)
{
    fseek (file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek (file, 0, SEEK_SET);
    return file_size;
}

int main_loop = 1;
SDL_Event event;
SDL_Surface *screen = NULL;
SDL_Color SFroadPalette[256];
SDL_Color SFroadFadePalette[256];
Uint8 alpha_color = 0;
Mix_Music *game_music;
int one_punch_man = 0;

extern unsigned char palette[768];

void setSFroadPalette(void)
{
   int i, j;
   for (i=0, j=0 ; i < 256 ; i++, j+=3)
   {
       SFroadPalette[i].r = palette[j];
       SFroadPalette[i].g = palette[j+1];
       SFroadPalette[i].b = palette[j+2];
   }
   SDL_SetPalette(screen, SDL_LOGPAL|SDL_PHYSPAL, SFroadPalette, 0, 256);
}

void setBrightness(int factor)
{
   int i ;
   for ( i=0 ; i<256 ; i++ )
   {
     SFroadFadePalette[i].r = (SFroadPalette[i].r * factor) / 100 ;
     SFroadFadePalette[i].g = (SFroadPalette[i].g * factor) / 100 ;
     SFroadFadePalette[i].b = (SFroadPalette[i].b * factor) / 100 ;
   }
}

void blit_raw(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys)
{
    int x, y;
    // compute starting address in dst surface
    Uint8  *dst_buffer = dst->pixels + y_pos * dst->pitch + x_pos;
    Uint8  *src_bitmap = p;

    for(y = 0; y < ys; y++)
    {
        for(x = 0; x < xs; x++)
        {
            if(src_bitmap[x] != alpha_color)
                dst_buffer[x] = src_bitmap[x];
        }
        dst_buffer += dst->w;
        src_bitmap += xcs;
    }
}

#define X_FLIP 1
#define Y_FLIP 2

void blit_raw_flipped(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys, int flip)
{
    int x, y, x2;
    int xstart = 0, xinc = 1;
    // compute starting address in dst surface
    Uint8  *dst_buffer = dst->pixels + y_pos * dst->pitch + x_pos;
    Uint8  *src_bitmap = p;
    if(flip & X_FLIP)
    {
        xstart  = xs-1; xinc = -1;
    }
    if(flip & Y_FLIP)
    {
        src_bitmap = p+xcs*(ys-1);
        xcs = -xcs;
    }

    for(y = 0; y < ys; y++)
    {
        //src_bitmap = p+xcs*(ys-y-1);
        for(x = 0, x2 = xstart; x < xs; x++, x2+=xinc)
        {
                if(src_bitmap[x2] != alpha_color)
                    dst_buffer[x]=src_bitmap[x2];
        }
        dst_buffer += dst->w;
        src_bitmap += xcs;
    }
}

void blit_scaled_X2(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys)
{
    int x, y, x2;
    unsigned char pixel;
    // compute starting address in dst surface
    Uint8  *dst_buffer = dst->pixels + y_pos * dst->pitch + x_pos;
    Uint8  *src_bitmap = (Uint8*) p;

    for(y = 0; y < ys; y++)
    {
        for(x = 0, x2= 0; x < xs; x++, x2 += 2)
        {
            pixel = src_bitmap[x];
            dst_buffer[x2] = pixel; dst_buffer[x2+1] = pixel;
            (dst_buffer + dst->w)[x2] = pixel; (dst_buffer + dst->w)[x2+1] = pixel;
        }
        dst_buffer += dst->w << 1;
        src_bitmap += xcs;
    }
}

extern int attack_key, jump_key, special_key;
extern int strength, damage;

void load_config(void)
{
    char c, s[10];
    FILE *fp ;
    fp=fopen("sfroadconfig.cfg","rb") ;
    if(fp==NULL)
    {
        fprintf(stderr, "Couldn't open sfroadconfig.cfg file \n");
        //exit(1);
    }
    fscanf(fp,"%s %c %d", s, &c, &attack_key);
    fscanf(fp,"%s %c %d", s, &c, &jump_key);
    fscanf(fp,"%s %c %d", s, &c, &special_key);
    fscanf(fp,"%s %c %d", s, &c, &one_punch_man);
    //printf("ak=%d jk=%d sk=%d opm=%d \n", attack_key, jump_key, special_key, one_punch_man);
    if(one_punch_man) {strength = 4; damage = 0;}
    fclose(fp) ;
}

int sfroad_keys[SDLK_LAST];

void intit_sfroad_keys(void)
{
    memset(sfroad_keys, 0, sizeof(sfroad_keys));

    sfroad_keys[SDLK_ESCAPE] = _ESC ;
    sfroad_keys[SDLK_UP] = _UPKEY ;
    sfroad_keys[SDLK_DOWN] = _DNKEY ;
    sfroad_keys[SDLK_LEFT] = _LTKEY ;
    sfroad_keys[SDLK_RIGHT] = _RTKEY ;
    sfroad_keys[SDLK_TAB] = _TAB ;
    sfroad_keys[SDLK_SPACE] = __SPACE ;
    sfroad_keys[SDLK_BACKSPACE] = _BACKSPACE ;
    sfroad_keys[SDLK_LALT] = _ALT ;
    sfroad_keys[SDLK_RALT] = _ALT ;
    sfroad_keys[SDLK_LCTRL] = _CTRL ;
    sfroad_keys[SDLK_RCTRL] = _CTRL ;
    sfroad_keys[SDLK_RETURN] = _ENTER ;
    sfroad_keys[SDLK_INSERT] = _INS  ;
    sfroad_keys[SDLK_DELETE] = _DEL  ;
    sfroad_keys[SDLK_HOME] = _HOME ;
    sfroad_keys[SDLK_END] = _END  ;
    sfroad_keys[SDLK_PAGEUP] = _PGUP ;
    sfroad_keys[SDLK_PAGEDOWN] = _PGDN ;
    sfroad_keys[SDLK_LSHIFT] = _LSHIFT ;
    sfroad_keys[SDLK_RSHIFT] = _RSHIFT ;

    sfroad_keys[SDLK_F1] = _F1  ;
    sfroad_keys[SDLK_F2] = _F2  ;
    sfroad_keys[SDLK_F3] = _F3  ;
    sfroad_keys[SDLK_F4] = _F4  ;
    sfroad_keys[SDLK_F5] = _F5  ;
    sfroad_keys[SDLK_F6] = _F6  ;
    sfroad_keys[SDLK_F7] = _F7  ;
    sfroad_keys[SDLK_F8] = _F8  ;
    sfroad_keys[SDLK_F9] = _F9  ;
    sfroad_keys[SDLK_F10] = _F10 ;
    sfroad_keys[SDLK_F11] = _F11  ;
    sfroad_keys[SDLK_F12] = _F12 ;

    sfroad_keys[SDLK_1] = _N1 ;
    sfroad_keys[SDLK_2] = _N2 ;
    sfroad_keys[SDLK_3] = _N3 ;
    sfroad_keys[SDLK_4] = _N4 ;
    sfroad_keys[SDLK_5] = _N5 ;
    sfroad_keys[SDLK_6] = _N6 ;
    sfroad_keys[SDLK_7] = _N7 ;
    sfroad_keys[SDLK_8] = _N8 ;
    sfroad_keys[SDLK_9] = _N9 ;
    sfroad_keys[SDLK_0] = _N0 ;

    sfroad_keys[SDLK_a] = _A ;
    sfroad_keys[SDLK_b] = _B ;
    sfroad_keys[SDLK_c] = _C ;
    sfroad_keys[SDLK_d] = _D ;
    sfroad_keys[SDLK_e] = _E ;
    sfroad_keys[SDLK_f] = _F ;
    sfroad_keys[SDLK_g] = _G ;
    sfroad_keys[SDLK_h] = _H ;
    sfroad_keys[SDLK_i] = _I ;
    sfroad_keys[SDLK_j] = _J ;
    sfroad_keys[SDLK_k] = _K ;
    sfroad_keys[SDLK_l] = _L ;
    sfroad_keys[SDLK_m] = _M ;
    sfroad_keys[SDLK_n] = _N ;
    sfroad_keys[SDLK_o] = _O ;
    sfroad_keys[SDLK_p] = _P ;
    sfroad_keys[SDLK_q] = _Q ;
    sfroad_keys[SDLK_r] = _R ;
    sfroad_keys[SDLK_s] = _S ;
    sfroad_keys[SDLK_t] = _T ;
    sfroad_keys[SDLK_u] = _U ;
    sfroad_keys[SDLK_v] = _V ;
    sfroad_keys[SDLK_w] = _W ;
    sfroad_keys[SDLK_x] = _X ;
    sfroad_keys[SDLK_y] = _Y ;
    sfroad_keys[SDLK_z] = _Z ;
}

int read_keyboard(void)
{
    if(SDL_PollEvent(&event) == 1)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                asci[_ESC] = 1;
                scan[_ESC] = 1;
                scan[_ENTER] = 1;
                break;
            case SDL_KEYDOWN:
                return sfroad_keys[event.key.keysym.sym];
            case SDL_KEYUP:
                return sfroad_keys[event.key.keysym.sym]+128;
        }
    }
    return 0;
}

void play_music(const char *filename)
{
    if (game_music != NULL)
    {
        Mix_HaltMusic();
        Mix_FreeMusic(game_music);
    }
    game_music = Mix_LoadMUS(filename);
    Mix_PlayMusic(game_music, -1);
}

void SFroad_SDL_init(void)
{
   SDL_Init(SDL_INIT_VIDEO);
   SDL_WM_SetCaption("SFroad",NULL);
   screen = SDL_SetVideoMode(360*2, 270*2, 8, SDL_HWPALETTE|SDL_HWSURFACE|SDL_DOUBLEBUF);
   setSFroadPalette();
   intit_sfroad_keys();
   Mix_Init(0);
   Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
   load_config();
}

void SFroad_SDL_quit(void)
{
   Mix_HaltChannel(-1);
   Mix_HaltMusic();
   Mix_FreeMusic(game_music);
   Mix_CloseAudio();
   Mix_Quit();
   SDL_Quit();
}

void processInput(void)
{
    if(SDL_PollEvent(&event) == 1)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                main_loop = 0;
                break;
            /*case SDL_KEYDOWN:
                 switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        printf("1\n");
                        break;
                }*/
        }
    }
}

void sleep(void)
{
    static int old_time = 0,  actual_time = 0;
    actual_time = SDL_GetTicks();
    if (actual_time - old_time < 16) // if less than 16 ms has passed
    {
        SDL_Delay(16 - (actual_time - old_time));
        old_time = SDL_GetTicks();
    }
    else
    {
        old_time = actual_time;
    }
}

union REGS;
int stub1(int a, int b){return 1;}
int stub2(int a, union REGS *b, union REGS *c){return 1;}
int stub3(int a, void (*b)()){return 1;}

void main_event_loop(void)
{
    main_loop = 1;
    while(main_loop)
    {
        processInput();
        sleep();
    }
}

