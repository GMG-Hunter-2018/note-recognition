#include "noter-sound/sound.hpp"
#include <iostream>

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

	data.left_phase = 0.0; // init data
	data.right_phase = 0.0;
}

bool AudioStream::openStream() {
	error = Pa_OpenDefaultStream(&stream,
	                             0, // Input Channels
	                             2, // Output Channels
	                             paFloat32, audio_sample_rate,
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

	u_int32_t i;

	for (i = 0; i < framesPerBuffer; i++) {
		// Taken from paex_saw.c to test out audio functionality

		*output++ = data->left_phase;  /* left */
		*output++ = data->right_phase; /* right */
		/* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
		data->left_phase += 0.01f;
		/* When signal reaches top, drop back down. */
		if (data->left_phase >= 1.0f)
			data->left_phase -= 2.0f;
		/* higher pitch so we can distinguish left and right. */
		data->right_phase += 0.03f;
		if (data->right_phase >= 1.0f)
			data->right_phase -= 2.0f;
	}

	return 0;
}
