#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

    ofstream compile("../../src/attacks/attack.cpp");

    // tells people their dumbasses for reading this file
    compile << "// THIS IS NOT TO BE READ, IT IS A COMPILED FILE MADE BY CUSTOM ATTACK SCRIPT LAUNGUAGE\n";
    
    // places all of the includes al the start of the file (and yes you can just dogpile them all)
    compile << "#include \"../../include.h\"\n";
    compile << "#include \"attack.h\"\n";
    compile << "#include <memory>\n";
    compile << "#include <iostream>\n";
    
    int o;
    string hand;

    // compiling the attack declarations
    ifstream script_images("../script/images");
    string line;
    while(getline(script_images, line)) {
        
        // for declaring new attacks
        if (!line.find("new_attack")) {
            hand = "";
            compile << "unique_ptr<ATTACK>";
            for (int i = 0; line[i + 11] != ','; i++) {
                o = i + 11;
                hand.push_back(line[i + 11]);
            }
            compile << hand;
            compile << "(new ATTACK());";
            compile << '\n';
            for (int i = o; line[i] != '('; i++)
                o++;
            o++;
            compile << "static int " << hand << "width =";
            compile << "WIN_WIDTH /";
            for (int i = o; line[i] != ','; i++) {
                compile << line[i];
                o++;
            }
            compile << ";\nstatic int " << hand << "height =";
            compile << "WIN_HEIGHT /";
            o++;
            for (int i = o; line[i] != ')'; i++)
                compile << line[i];
            compile << ";\n";
        }
    }

    script_images.close();
    
    // adds boilerplate
    compile << "static int delay=time(NULL);\n";
    compile << "static bool attack_init=true;\n";
    compile << "void attacks(SDL_Renderer *renderer,int heart_x, int heart_y, int turn_cycle, bool scout_turn) {\n";

    compile << "if (attack_init) {\n";

    // compiles the image attacks
    ifstream script_init("../script/init");
    
    while (getline(script_init, line)) {

        // for the image path the images made in images will do the images
        if (!line.find("declare_attack")) {
            for (int i = 0; line[i + 15] != ','; i++) {
                compile << line[i + 15];
                o = i;
            }
            o += 17;
            compile << "->setTexture(renderer, ASSETPATH\"";
            
            for (int i = 1; line[i + o]; i++)
                compile << line[i + o];

            compile << "\");\n";
            line = "";
        }

        if (!line.find("init_x")) {
            hand = "";
            o = 6;
            for (int i = 0; line[i + 6] != ','; i++) {
                hand.push_back(line[i + 6]);
                o++;
            }
            o++;
            compile << hand << "->x = ";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }   

        if (!line.find("init_y")) {
            hand = "";
            o = 6;
            for (int i = 0; line[i + 6] != ','; i++) {
                hand.push_back(line[i + 6]);
                o++;
            }
            o++;
            compile << hand << "->y = ";
            hand = "";
            for (int i = o; line[i]; i++) {
                hand.push_back(line[i]);
            }
            compile << hand << ";\n";
            line = "";
        }
    }

    script_init.close();


    compile << "attack_init = false;}\n";
    compile << "switch (turn_cycle) {\n";

    ifstream script_attack("../script/attacks");

    while (getline(script_attack, line)) {

        if (!line.find("attack")) {
            compile << "case ";
            for (int i = 6; line[i]; i++)
                compile << line[i];
            compile << ":\n";
            compile << "if (scout_turn) {\n";
            line = "";
        }
        if (!line.find("end_attack")) {
            compile << "}\nbreak;\n";
            line = "";
        }
        if (!line.find("draw")) {
            hand = "";
            for (int i = 4; line[i] != ','; i++) {
                hand.push_back(line[i]);    
            }
            compile << hand;
            compile << "->renderScaledTexture(renderer, " << 
                hand << "->x," << hand << "->y," << 
                hand << "width," << hand << "height);\n";
            line = "";
        }
        if (!line.find("wait")) {
            compile << "delay = time(NULL);";
            for (int i = 0; line[i + 4]; i++){
                compile << line[i + 4];
            }
        }
        if (!line.find("for_second")) {
            compile << "if (time(NULL) - delay >";
            o = 10;
            for (int i = 10; line[i] != ','; i++) {
                compile << line[i];
                o++;
            }
            o++;
            compile << "&& time(NULL) - delay<";

            for (int i = o; line[i]; i++)
                compile << line[i];
            
            compile << "){\n";

            line = "";
        }

        if (!line.find("move_right")) {
            o = 11;
            for (int i = 10; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->x +=WIN_WIDTH/";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }
        
        if (!line.find("move_left")) {
            o = 10;
            for (int i = 9; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->x -=WIN_WIDTH/";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }

        if (!line.find("move_up")) {
            o = 8;
            for (int i = 7; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->y -= WIN_HEIGHT/";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
            line = "";
        }
        if (!line.find("move_down")) {
            o = 10;
            for (int i = 9; line[i] != ','; i++) {
                o++;
                compile << line[i];
            }
            compile << "->y += WIN_HEIGHT/";
            for (int i = o; line[i]; i++)
                compile << line[i];
            compile << ";\n";
        }

        if (!line.find("end")) {
            compile << "}";
            line = "";
        }
    }
    

    script_attack.close();
    compile << "default:\ndelay=time(NULL);\nbreak;\n}";

    // finishes
    compile << "}";
    compile.close();

}