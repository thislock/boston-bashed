
#include "font.h"
#include "../macros.h"

void FONT::letter(
  SDL_Renderer * renderer,
  int x, int y,
  int let
) {

  if (let == 1)
    clips[0] = 0;
  else
   clips[0] = 4 * let;
  
  clips[1] = 0;
  clips[2] = 4;
  clips[3] = 5;

  renderCutTexture(
    renderer,
    WIN_WIDTH / 2, WIN_HEIGHT / 2,
    100, 100,
    clips
  );

}