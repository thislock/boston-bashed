// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE
#include "../../include.h"
#include "attack.h"
#include <memory>
#include <iostream>
unique_ptr<ATTACK>test1(new ATTACK());
static int test1width =WIN_WIDTH /20;
static int test1height =WIN_HEIGHT / 20;
static int delay=time(NULL);
static bool attack_init=true;
void attacks(SDL_Renderer *renderer,int heart_x, int heart_y, int turn_cycle, bool scout_turn) {
if (attack_init) {
test1->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
 test1->x =  100;
 test1->y =  100;
attack_init = false;}
switch (turn_cycle) {
case 1:
if (scout_turn) {
 test1->renderScaledTexture(renderer,  test1->x, test1->y, test1width, test1height);
if (time(NULL) - delay > 2&& time(NULL) - delay< 5){
 test1->x +=WIN_WIDTH/ 150;
 test1->y += WIN_HEIGHT/ 150;
}}
break;
default:
delay=time(NULL);
break;
}}