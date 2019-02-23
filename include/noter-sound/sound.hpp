#pragma once

#include <portaudio.h>
#include <memory>
#include <optional>

/*The purpose of the next few classes is to wrap some of
the PortAudio functions in slightly more modern c++ 
*/

class AudioInitialize {

public:
    AudioInitialize();
    ~AudioInitialize();

    //Will return true if PA is initialized, false otherwise
    bool initPA();

    //Will return true if PA is not active
    //Note, will return true if initialization was never successful in the first place
    bool terminatePA();


private:
    PaError error;
};


struct paTestData {
    float left_phase = 0;
    float right_phase = 0;

    float intendedFreq = 261.6f; //Default to Mid-C

    const uint32_t sampleRate = 44100;
};


class AudioStream {

public:
    AudioStream(); //constructor opens the stream

    bool openStream();
    bool startStream();
    bool stopStream();

    paTestData data;


private:
    PaError error;
    PaStream* stream;

};

void fft(int x); //Placeholder for fft

int audioTestCallBack ( void const* inputBuffer,
                               void* outputBuffer,
                               unsigned long framesPerBuffer,
                               const PaStreamCallbackTimeInfo* timeInfo,
                               PaStreamCallbackFlags statusFlags,
                               void* inputData );
//As of now, we've achieved pure frequencies of choice.