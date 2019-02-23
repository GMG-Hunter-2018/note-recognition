#include "noter-sound/sound.hpp"
#include <cmath>
#include <iostream>

constexpr float tau = 2 * M_PIf32;

AudioInitialize::AudioInitialize() {
	initPA();
}

AudioInitialize::~AudioInitialize() {
	terminatePA();
}

bool AudioInitialize::initPA() {
	error = Pa_Initialize();

	if (error != paNoError) {
		std::cerr << Pa_GetErrorText(error) << '\n';
		return false;
	}

	return true;
}

bool AudioInitialize::terminatePA() {
	if (error != paNoError) {
		return true; // A pre-termination error means there is nothing to terminate
	}

	if (error == paNoError) {
		error = Pa_Terminate();
	}

	return error == paNoError;
}

AudioStream::AudioStream() {
	if (!openStream()) {
		std::cerr << "AudioStream open failed \n";
	}
}

bool AudioStream::openStream() {
	error = Pa_OpenDefaultStream(&stream,
	                             0, // Input Channels
	                             2, // Output Channels
	                             //The Following type is "PaFloat32"
	                             //It is represented as such to avoid old-style cast.
	                             static_cast<PaSampleFormat>(0x00000001), data.sampleRate,
	                             256, // Frames per buffer
	                             audioTestCallBack, &data);

	if (error != paNoError) {
		std::cerr << Pa_GetErrorText(error) << '\n';
		return false;
	}

	return true;
}

bool AudioStream::startStream() {
	error = Pa_StartStream(stream);

	if (error != paNoError) {
		std::cerr << Pa_GetErrorText(error) << '\n';
		return false;
	}

	return true;
}

bool AudioStream::stopStream() {
	error = Pa_StopStream(stream);

	if (error != paNoError) {
		std::cerr << Pa_GetErrorText(error) << '\n';
		return false;
	}

	return true;
}

int audioTestCallBack(void const* /*inputBuffer*/,
                      void* outputBuffer,
                      unsigned long framesPerBuffer,
                      const PaStreamCallbackTimeInfo* /*timeInfo*/,
                      PaStreamCallbackFlags /*statusFlags*/,
                      void* inputData) {
	auto data = static_cast<paTestData*>(inputData);
	auto output = static_cast<float*>(outputBuffer);

	float internalFreq = data->intendedFreq / data->sampleRate;

	for (uint32_t i = 0; i < framesPerBuffer; i++) {
		// Left and Right phase correspond to channel
		// The fact that output is a float vs double is built in

		*output++ = std::sin(data->left_phase * tau);
		*output++ = std::sin(data->right_phase * tau);
		data->left_phase += internalFreq;
		data->right_phase += internalFreq;
	}

	return paContinue;
}
