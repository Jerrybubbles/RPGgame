#include "game.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


int main(int argc,char* argv[])
{
    if (argc == 1){
        cout << "No command line arguments passed! Please passs the absolute path to the monsters.csv!" << endl;
    }
    else if (argc == 2){
        cout << "This is the path: " << argv[1] << endl;
        cout << "Welkom op dit kleine rpg avontuur!" << endl << endl;
        Game game{argv[1]};
        game.Start();
    }
    else{
        cout << "Passed too many arguments!! pass only the absolute path please!" << endl;

    }
    return 0;
}
