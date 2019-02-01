#include "noter-sound/sound.hpp"
#include <iostream>


AudioInitialize::AudioInitialize(){
    initPA();
}

AudioInitialize::~AudioInitialize(){
    terminatePA();
}

bool AudioInitialize::initPA(){
    error = Pa_Initialize();

    if(error != paNoError){
        std::cerr << Pa_GetErrorText(error) << '\n';
        return false;
    }

    return true;
}

bool AudioInitialize::terminatePA(){

    if (error != paNoError){
        return true; //A pre-termination error means there is nothing to terminate
    }

    if (error == paNoError){
        error = Pa_Terminate();
    }

    return error == paNoError;
}


AudioStream::AudioStream(){
    if(!openStream()){
        std::cerr << "AudioStream open failed \n";
    }

    data.phase = 0.0; //init data
}

bool AudioStream::openStream(){

    error = Pa_OpenDefaultStream( &stream,
                                  0, //Input Channels
                                  2, //Output Channels
                                  paFloat32,
                                  audio_sample_rate,
                                  256, //Frames per buffer
                                  audioTestCallBack,
                                  &data);

    if (error != paNoError){
        std::cerr << Pa_GetErrorText(error) << '\n';
        return false;
    }

    return true;

}

bool AudioStream::startStream(){

    error = Pa_StartStream(stream);

    if (error != paNoError){
        std::cerr << Pa_GetErrorText(error) << '\n';
        return false;
    }

    return true;
}

bool AudioStream::stopStream(){

    error = Pa_StopStream(stream);

    if (error != paNoError){
        std::cerr << Pa_GetErrorText(error) << '\n';
        return false;
    }

    return true;
}

static int audioTestCallBack ( void const* inputBuffer,
                               void* outputBuffer,
                               unsigned long framesPerBuffer,
                               const PaStreamCallbackTimeInfo* timeInfo,
                               PaStreamCallbackFlags statusFlags,
                               void* inputData ){

    auto data = static_cast<paTestData*>(inputData);
    auto output = static_cast<float*>(outputBuffer);

    for(unsigned long i = 0; i < framesPerBuffer; i++){
        *output++ = data->phase;
    }
    
    return 0;
}
