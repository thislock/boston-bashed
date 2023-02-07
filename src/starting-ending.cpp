
#include "superfile.h"

MASTER::MASTER() {
  cout << "master class created successfuly.\n";
}

MASTER::~MASTER() {
  cout << "master class destroyed successfuly.\n";
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}