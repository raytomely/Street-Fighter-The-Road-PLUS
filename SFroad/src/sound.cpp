#include "sound.h"
#include "midi.h"
#include "sfroad_sdl.h"


int  _cdecl MODDetectCard(word *Port, byte *IRQ, byte *DRQ){return 0;}
int  _cdecl MODPlayModule(Module *Modulefile,word Chans,word Rate,word Port,byte IRQ,byte DRQ,byte Mode){return 1;}
void _cdecl MODStopModule(void){}

void _cdecl MODPlaySample(byte Voice,Sample *Instr)
{
    play_sound(Instr->chunk);
}

void _cdecl MODStopSample(byte Voice){}
void _cdecl MODSetPeriod(byte Voice,word Period){}
void _cdecl MODSetVolume(byte Voice,byte Volume){}
void _cdecl MODSetMusicVolume(byte Volume){}
void _cdecl MODSetSampleVolume(byte Volume){}
void _cdecl MODPoll(void){}

Module *MODLoadModule(char *Path){Module *m=0; return m;}
void MODFreeModule(Module *Song){}

Sample *MODLoadSample(const char *Path)
{
    Sample *s = (Sample*)malloc(sizeof(Sample));
    s->chunk = Mix_LoadWAV((char*)Path);
    return s;
}

void MODFreeSample(Sample *Instr)
{
    Mix_FreeChunk(Instr->chunk);
    free(Instr);
    Instr = NULL;
}


int playMidiData( const char *fn, unsigned int size )
{
    play_music((char *)fn);
    return 1;
}

void midiTickEvent(void) {}
void endMidiPlay(void) {}
int setUpMidiTrack(unsigned char *midiPtr,_MIDITRACK_ MT[],_MIDIPLAY_ *MP) {return 1;}
int is4CharCmp(unsigned char *name1,unsigned char *name2) {return 1;}
int get4Byte(unsigned char *ptr) {return 1;}
int get2Byte(unsigned char *ptr) {return 1;}
int getMidiLength(unsigned char **ptr) {return 1;}
void playTrack(_MIDITRACK_ MT[],_MIDIPLAY_ *MP) {}
void calcWillPlayTrack(_MIDITRACK_ MT[],_MIDIPLAY_ *MP) {}
void sendMessage(unsigned char message,_MIDITRACK_ *MT) {}
void setMidiTempo(int uSecPerQNote) {}
void setRelativeMusicTempo(int divisor) {}
void setMidiPlaySpeed(int speed) {}
void setTimer0(int divisor) {}
void setMidiMainVolume(int volume) {}

int playMidiLoopCounter ;
int flagMidiPlay ;
int speedMidiPlay ;
int midiMainVolume ;

int sendMPU401Command(unsigned char cmd) {return 1;}
int sendMPU401Data(unsigned char data) {return 1;}
int initMPU401(int BaseIO) {return 0;}
int autoDetectMPU401(void) {return 1;}
int sendMidiData(int cmd1,int data1,int data2) {return 1;}

int MPU401BaseIO ;
