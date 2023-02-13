
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

  SOUND(string file_path);

  void playsound();

  ~SOUND();

};

#endif // SOUNDS_H