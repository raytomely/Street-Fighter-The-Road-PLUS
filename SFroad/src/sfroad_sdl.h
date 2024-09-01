#ifndef SFROAD_SDL_H
#define SFROAD_SDL_H

#include <SDL/SDL.h>
#include <SDL_mixer.h>

#define delay(x) SDL_Delay(x)
#define play_sound(chunk) Mix_PlayChannel(-1, chunk, 0);

extern SDL_Surface *screen;
extern SDL_Color SFroadPalette[256];
extern SDL_Color SFroadFadePalette[256];

#define RESTORE_PALETTE() SDL_SetPalette(screen, SDL_LOGPAL|SDL_PHYSPAL, SFroadPalette, 0, 256);

#ifdef __cplusplus
extern "C" {
#endif
void setSFroadPalette(void);
void setBrightness(int factor);
SDL_Surface *create_surface(int width, int height);
void blit_raw(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys);
void blit_raw_flipped(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys, int flip);
void blit_scaled_X2(SDL_Surface *dst, int x_pos, int y_pos, unsigned char *p, int xcs, int xs, int ys);
void intit_sfroad_keys(void);
int read_keyboard(void);
void play_music(char *filename);
void load_config(void);
void SFroad_SDL_init(void);
void SFroad_SDL_quit(void);
void processInput(void);
void sleep(void);
void main_event_loop(void);
#ifdef __cplusplus
}
#endif

#endif // SFROAD_SDL_H

