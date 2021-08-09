#ifndef __AUDIO__DRIVER__H
#define __AUDIO__DRIVER__H

#define SPEAKER_PIN 3

#define DO0 33
#define DO1 65
#define DO2 131
#define DO3 262
#define DO4 523
#define DO5 1047
#define DO6 2093
#define DO7 4186
#define DO8 8372
#define DO9 16744

//D = #

#define DOD0 35
#define DOD1 69
#define DOD2 139
#define DOD3 277
#define DOD4 554
#define DOD5 1109
#define DOD6 2217
#define DOD7 4435
#define DOD8 8870
#define DOD9 17740

#define RE0 37
#define RE1 73
#define RE2 147
#define RE3 294
#define RE4 587
#define RE5 1175
#define RE6 2349
#define RE7 4699
#define RE8 9397
#define RE9 18795

class Audio
{
public:
    void init();
    void buzz(short int frequency, short int delay);
    short int period;
    bool activation;
private:
    short int frequency;
};

extern Audio audio;
void SpeakerONFunction();
void SpeakerOFFFunction();

#endif