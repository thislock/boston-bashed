// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE
#include "../../include.h"
#include "attack.h"
#include <memory>
#include <iostream>
unique_ptr<ATTACK>test1(new ATTACK());
static bool attack_init = true;
void attacks(SDL_Renderer *renderer,int heart_x, int heart_y, int turn_cycle, bool scout_turn) {
if (attack_init) {
test1->setTexture(renderer, ASSETPATH " attacks/cleaver.bmp");
attack_init = false;}
switch (turn_cycle && scout_turn) {
case 1:
  break;
default:
  break;
}}