
#ifndef SOUNDS_H
#define SOUNDS_H

#include <SDL.h>
#include <string>
#include <iostream>
#include <time.h>

#define SOUNDPATH "../sounds/"

using namespace std;

class SOUND {

  SDL_AudioSpec wavSpec;
  Uint32 wavLength;
  Uint8 *wavBuffer;

  string filepath;

  int success;
  SDL_AudioDeviceID deviceId;

public:

  SOUND(string file_path) {
    filepath = file_path;
    SDL_LoadWAV(file_path.c_str(), &wavSpec, &wavBuffer, &wavLength);
    success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    cout << filepath << " created successfuly\n";
  }

  void playsound() {
    cout << wavLength << endl << clock() << endl <<  clock() - wavLength << endl;
    SDL_PauseAudioDevice(deviceId, 0);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
  }

  ~SOUND() {
    cout << filepath << " closed successfuly\n";
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
  }

};

#endif // SOUNDS_H