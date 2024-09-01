/* MIDI FILE FORMAT HEADER FILE */

#define MAX_TRACK 16 /* ÂA” £¡—¡ Ëaœ‚ ˆ•® */

#define MIDI_NOTE_OFF      0x80
#define MIDI_NOTE_ON       0x90
#define MIDI_KEY_VELO      0xA0
#define MIDI_CONTROL_CHG   0xB0
#define MIDI_PROGRAM_CHG   0xC0
#define MIDI_CHANNEL_VELO  0xD0
#define MIDI_VENDOR_UNIQ   0xE0
#define MIDI_EXCLUSIVE     0xF0
#define META_MESSAGE       0xFF
#define META_END_OF_TRACK  0x2F
#define META_CHANGE_TEMPO  0x51

typedef struct
{
   unsigned char *ptr ; /* Ëaœ‚ µeº Í¡·¥Èá */
   unsigned char message ; /* Ñe¸ ¡A­A»¡ */
   unsigned char status  ; /* Ëaœ‚ ¬wÈ */
   int size ;             /* Ëaœ‚ ‹©·¡ */
   int timeStamp ;        /* Ëaœ‚ µeº Èa·± */
} _MIDITRACK_ ; /* £¡—¡ 1 Ëaœ‚ ¯aËaœâÁa */

typedef struct
{
   unsigned char *ptr ;
   int  tickPerQNote  ; /* 1/4¤b¸a”w Èa·¡ á Ë¢® */
   int  uSecPerQNote           ; /* 1/4¤b¸a”w ˆéŸ¡“e ¯¡ˆe micro Second */
   int  currentTime            ; /* Ñe¸ ¯¡ˆe */
   int  willPlayTime           ; /* ”a·qµA µeºÐi ¯¡ˆe */
   int  willPlayTrack          ; /* ”a·qµA µeºÐi Ëaœ‚ ¤åÑ¡ */
   int  timer0Divisor         ; /* 8254 Èa·¡ á Àé 0 ¦…ºˆt */
   int  numOfTrack    ; /* ¬a¶w–E Ëaœ‚ ˆ•® */
   unsigned char allTrackEnd   ; /* ¡¡—e Ëaœ‚· µeº¹·ža¯¡ 1 */
} _MIDIPLAY_ ; /* £¡—¡ µeº ¯aËaœâÁa */

int playMidiData( char *fn, unsigned int size );
void midiTickEvent(void) ;
void endMidiPlay(void) ;
int setUpMidiTrack(unsigned char *midiPtr,_MIDITRACK_ MT[],_MIDIPLAY_ *MP) ;
int is4CharCmp(unsigned char *name1,unsigned char *name2) ;
int get4Byte(unsigned char *ptr) ;
int get2Byte(unsigned char *ptr) ;
int getMidiLength(unsigned char **ptr) ;
void playTrack(_MIDITRACK_ MT[],_MIDIPLAY_ *MP) ;
void calcWillPlayTrack(_MIDITRACK_ MT[],_MIDIPLAY_ *MP) ;
void sendMessage(unsigned char message,_MIDITRACK_ *MT) ;
void setMidiTempo(int uSecPerQNote) ;
void setRelativeMusicTempo(int divisor) ;
void setMidiPlaySpeed(int speed) ;
void setTimer0(int divisor) ;
void setMidiMainVolume(int volume) ;


#ifndef _MIDI_MAIN_SOURCE_
extern int playMidiLoopCounter ; /* ¤e¥¢ µeº ÒU® */
extern int flagMidiPlay ;        /* ·q´b µeºº— ¬wÈ Ïaœ‹a */
extern int speedMidiPlay ;       /* ·q´b µeº ­¢•¡ */
extern int midiMainVolume ;      /* ·q´b ­¡Ÿ¡ ¥©ŸQ */
#endif

/*
   MPU 401 Midi Interface Program Header File
*/

#ifndef _MPU401_IO_
#define _MPU401_IO_

int sendMPU401Command(unsigned char cmd) ; /* MPU 401 ¸í·É¾î Àü¼Û */
int sendMPU401Data(unsigned char data) ; /* MPU 401 µ¥ÀÌÅ¸ Àü¼Û */
int initMPU401(int BaseIO) ; /* MPU 401 ÃÊ±âÈ­ */
int autoDetectMPU401(void) ; /* MPU 401 ÀÚµ¿ Ã¼Å© */
int sendMidiData(int cmd1,int data1,int data2) ; /* ¹Ìµð ¸Þ¼¼Áö Àü¼Û */

#endif

#ifndef _MPU401_IO_MAIN_
extern int MPU401BaseIO ; /* MPU 401 º£ÀÌ½º I/O ¹øÁö */
#endif
