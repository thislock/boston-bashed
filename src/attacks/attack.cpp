// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE
#include "../../include.h"
#include "attack.h"
#include <memory>
#include <iostream>
#include <chrono>
using namespace std::chrono;
unique_ptr<ATTACK>test1(new ATTACK());
static int test1width =WIN_WIDTH /15;
static int test1height =WIN_HEIGHT / 15;
unique_ptr<ATTACK>test2(new ATTACK());
static int test2width =WIN_WIDTH /15;
static int test2height =WIN_HEIGHT / 15;
unique_ptr<ATTACK>test3(new ATTACK());
static int test3width =WIN_WIDTH /15;
static int test3height =WIN_HEIGHT / 15;
unique_ptr<ATTACK>test4(new ATTACK());
static int test4width =WIN_WIDTH /15;
static int test4height =WIN_HEIGHT / 15;
unique_ptr<ATTACK>test5(new ATTACK());
static int test5width =WIN_WIDTH /15;
static int test5height =WIN_HEIGHT / 15;
static int delay=time(NULL);
static int64_t delay_millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();static bool attack_init=true;
void attacks(SDL_Renderer *renderer,int heart_x, int heart_y, int turn_cycle, bool & scout_turn,int & HEART_HP) {
if (attack_init) {
test1->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
test2->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
test3->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
test4->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
test5->setTexture(renderer, ASSETPATH"attacks/cleaver.bmp");
 test1->x =  100;
 test1->y =  (WIN_HEIGHT / 2) + WIN_HEIGHT / 13;
 test2->x =  100;
 test2->y =  (WIN_HEIGHT / 2) + WIN_HEIGHT / 8;
 test3->x =  100;
 test3->y =  (WIN_HEIGHT / 2) + WIN_HEIGHT / 6;
 test4->x =  100;
 test4->y =  (WIN_HEIGHT / 2) + WIN_HEIGHT / 5;
 test5->x =  100;
 test5->y =  (WIN_HEIGHT / 2) + WIN_HEIGHT / 4;
attack_init = false;}
switch (turn_cycle) {
case 1:
if (scout_turn) {
 test1->renderScaledTexture(renderer,  test1->x, test1->y, test1width, test1height);
 test2->renderScaledTexture(renderer,  test2->x, test2->y, test2width, test2height);
 test3->renderScaledTexture(renderer,  test3->x, test3->y, test3width, test3height);
 test4->renderScaledTexture(renderer,  test4->x, test4->y, test4width, test4height);
 test1->x +=WIN_WIDTH/ 20;
if (time(NULL) - delay >= 2&& time(NULL) - delay<=2){
}if (time(NULL) - delay >= 3&& time(NULL) - delay<=3){
 test4->x +=WIN_WIDTH/ 20;
}if (time(NULL) - delay >= 4&& time(NULL) - delay<=4){
 test2->x +=WIN_WIDTH/ 20;
}if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - delay_millis >= 0&& std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - delay_millis<=0){
scout_turn = false;
}if (time(NULL) - delay >= 5&& time(NULL) - delay<=5){
 test5->x +=WIN_WIDTH/ 20;
}if (time(NULL) - delay >= 6&& time(NULL) - delay<=6){
 test3->x +=WIN_WIDTH/ 20;
}if (time(NULL) - delay >= 7&& time(NULL) - delay<=7){
scout_turn = false;
} test5->renderScaledTexture(renderer,  test5->x, test5->y, test5width, test5height);
if (touching_heart(heart_x, heart_y, test1->x, test1->y, test1width, test1height)) {
HEART_HP -= 2;
}if (touching_heart(heart_x, heart_y, test2->x, test2->y, test2width, test2height)) {
HEART_HP -= 2;
}if (touching_heart(heart_x, heart_y, test3->x, test3->y, test3width, test3height)) {
HEART_HP -= 2;
}if (touching_heart(heart_x, heart_y, test4->x, test4->y, test4width, test4height)) {
HEART_HP -= 2;
}if (touching_heart(heart_x, heart_y, test5->x, test5->y, test5width, test5height)) {
HEART_HP -= 2;
}}
break;
default:
delay=time(NULL); delay_millis=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); 
break;
}}