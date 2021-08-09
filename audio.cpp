#include "audio.h"
#include "Arduino.h"
#include "task.h"

struct Task SpeakerON;
struct Task SpeakerOFF;

Audio audio;

void Audio::init()
{
    Audio::activation = false;
    pinMode(SPEAKER_PIN, OUTPUT);
    InitTask(10000, &SpeakerONFunction, &millis, &SpeakerON);
    InitTask(10000, &SpeakerOFFFunction, &millis, &SpeakerOFF);
}

void Audio::buzz(short int frequency, short int delay)
{
    Audio::period = (short int)((1/(float)(frequency*2)) * 1000000);
}

void SpeakerONFunction()
{
    if(audio.activation) digitalWrite(SPEAKER_PIN, HIGH);
    else;
    // Serial.println("on");
}

void SpeakerOFFFunction()
{
    if(audio.activation) digitalWrite(SPEAKER_PIN, LOW);
    else;
    // Serial.println("off");
}