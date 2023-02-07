
#ifndef ATTACK_SCRIPT
#define ATTACK_SCRIPT

// for not removing
#define DONTREMOVE static bool attack_init = true;

// for creating an image
#define makeimg_ unique_ptr<IMAGE> 
#define _makeimg (new IMAGE());

// for creating an attack type 
#define makeattack_ unique_ptr<ATTACK> 
#define _makeattack (new ATTACK());

// the attacks fn simplified (for lucas)
#define attack_script void attacks(SDL_Renderer * renderer, int heart_x, int heart_y)

// for init
#define init if (attack_init) {
#define endinit }

// for adding to attack types
#define RIGHT ->x +=
#define LEFT ->x -=

#define DOWN ->y +=
#define UP ->y -=

// for simple moving twords the heart


#define GET ->

// render texture
#define DRAW ->renderScaledTexture ( renderer,
#define END_DRAW );

// simpler syntax
#define NOT !

// simpler setting texture syntax
#define setSprite -> setTexture(renderer, ASSETPATH
#define endSetSprite );



#endif // ATTACK_SCRIPT