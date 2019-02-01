#pragma once

#include <portaudio.h>
#include <memory>

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


typedef struct {
    float phase;
} paTestData;


class AudioStream {

public:
    AudioStream(); //constructor opens the stream

    bool openStream();
    bool startStream();
    bool stopStream();

private:
    PaError error;
    PaStream* stream;
    paTestData data;

    const int audio_sample_rate = 44100;
};

void fft(int x); //Placeholder for fft

static int audioTestCallBack ( void const* inputBuffer,
                               void* outputBuffer,
                               unsigned long framesPerBuffer,
                               const PaStreamCallbackTimeInfo* timeInfo,
                               PaStreamCallbackFlags statusFlags,
                               void* inputData );
//As of right now, this should just spit out a saw wave, a la paex_saw.c example