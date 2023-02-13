
#include "sounds.h"

SOUND::SOUND(string file_path) {
  filepath = file_path;
  SDL_LoadWAV(file_path.c_str(), &wavSpec, &wavBuffer, &wavLength);
  SDL_QueueAudio(deviceId, wavBuffer, wavLength);
  deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
  cout << filepath << " created successfuly\n";
}

void SOUND::playsound() {
  SDL_PauseAudioDevice(deviceId, 0);
  SDL_QueueAudio(deviceId, wavBuffer, wavLength);
}

SOUND::~SOUND() {
  cout << filepath << " closed successfuly\n";
  SDL_CloseAudioDevice(deviceId);
  SDL_FreeWAV(wavBuffer);
}