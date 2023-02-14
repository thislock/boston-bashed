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
    
    // compiling the attack declarations
    ifstream script_images("../script/images");
    string line;
    while(getline(script_images, line)) {
        // for declaring new attacks
        if (!line.find("new_attack")) {
            compile << "unique_ptr<ATTACK>";
            for (int i = 0; line[i + 11]; i++)
                compile << line[i + 11];
            compile << "(new ATTACK());";
            compile << '\n';
        }
    }

    script_images.close();
    
    // adds boilerplate
    compile << "static bool attack_init = true;\n";
    compile << "void attacks(SDL_Renderer *renderer,int heart_x, int heart_y, int turn_cycle, bool scout_turn) {\n";

    compile << "if (attack_init) {\n";

    // compiles the image attacks
    ifstream script_init("../script/init");
    
    while (getline(script_init, line)) {
        // for the image path the images made in images will do the images
        if (!line.find("declare_attack")) {
            int o;
            for (int i = 0; line[i + 15] != ','; i++) {
                compile << line[i + 15];
                o = i;
            }
            o += 17;
            compile << "->setTexture(renderer, ASSETPATH \"";
            
            for (int i = 0; line[i + o]; i++)
                compile << line[i + o];

            compile << "\");\n";

        }
    }

    script_init.close();


    compile << "attack_init = false;}\n";
    compile << "switch (turn_cycle && scout_turn) {\n";

    ifstream script_attack("../script/attacks");

    while (getline(script_attack, line)) {
        if (!line.find("attack")) {
            compile << "case ";
            for (int i = 6; line[i]; i++)
                compile << line[i];
            compile << ":\n";
        }
        if (!line.find("end_attack")) {
            compile << "  break;\n";
        }
    }
    

    script_attack.close();
    compile << "default:\n  break;\n}";

    // finishes
    compile << "}";
    compile.close();

}