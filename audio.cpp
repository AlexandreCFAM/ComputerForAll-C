#include "audio.h"
#include "Arduino.h"
#include "timer.h"

Audio audio;

void Audio::init()
{
    Serial.println(F("Starting audio driver..."));
    pinMode(SPEAKER_PIN, OUTPUT);
    Audio::SpeakerState = false;
}

void Audio::buzz(short int frequency, short int delay)
{
    /*if(timer.IsUsed) timer.stop();
    else
    {
        timer.update((int)((1.00 / (frequency * 2.00)) * 1000000), &SpeakerFunction);
    }*/
}

void SpeakerFunction()
{
    /*digitalWrite(SPEAKER_PIN, audio.SpeakerState);
    audio.SpeakerState = !audio.SpeakerState;*/
}