#ifndef MIDI_H
#define MIDI_H

/* MIDI FILE FORMAT HEADER FILE */

#define MAX_TRACK 16 /* �A�� ���� �a�� ���� */

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
   unsigned char *ptr ; /* �a�� �e�� ͡���� */
   unsigned char message ; /* �e�� �A�A�� */
   unsigned char status  ; /* �a�� �wȁ */
   int size ;             /* �a�� ���� */
   int timeStamp ;        /* �a�� �e�� �a�� */
} _MIDITRACK_ ; /* ���� 1 �a�� �a�a���a */

typedef struct
{
   unsigned char *ptr ;
   int  tickPerQNote  ; /* 1/4�b�a�w �a���� ˢ�� */
   int  uSecPerQNote           ; /* 1/4�b�a�w �韡�e ���e micro Second */
   int  currentTime            ; /* �e�� ���e */
   int  willPlayTime           ; /* �a�q�A �e���i ���e */
   int  willPlayTrack          ; /* �a�q�A �e���i �a�� ��ѡ */
   int  timer0Divisor         ; /* 8254 �a���� ���� 0 �����t */
   int  numOfTrack    ; /* �a�w�E �a�� ���� */
   unsigned char allTrackEnd   ; /* ���e �a���� �e�����a�� 1 */
} _MIDIPLAY_ ; /* ���� �e�� �a�a���a */

int playMidiData( const char *fn, unsigned int size );
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
extern int playMidiLoopCounter ; /* �e�� �e�� �U�� */
extern int flagMidiPlay ;        /* �q�b �e���� �wȁ �a���a */
extern int speedMidiPlay ;       /* �q�b �e�� ���� */
extern int midiMainVolume ;      /* �q�b ���� ���Q */
#endif

/*
   MPU 401 Midi Interface Program Header File
*/

#ifndef _MPU401_IO_
#define _MPU401_IO_

int sendMPU401Command(unsigned char cmd) ; /* MPU 401 ���ɾ� ���� */
int sendMPU401Data(unsigned char data) ; /* MPU 401 ����Ÿ ���� */
int initMPU401(int BaseIO) ; /* MPU 401 �ʱ�ȭ */
int autoDetectMPU401(void) ; /* MPU 401 �ڵ� üũ */
int sendMidiData(int cmd1,int data1,int data2) ; /* �̵� �޼��� ���� */

#endif

#ifndef _MPU401_IO_MAIN_
extern int MPU401BaseIO ; /* MPU 401 ���̽� I/O ���� */
#endif

#endif // MIDI_H
