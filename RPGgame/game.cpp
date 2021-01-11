#include "game.h"

Game::Game()
{

}

void Game::Start()
{
    cout << "Enter 1 om te starten" << endl;
    cout << "Enter 0 om het spel te verlaten" << endl << endl;
    cout << "Keuze:";

    cin >> choice;

    switch (choice)
    {
    default:
        cout << "Byebye!" << endl;
        break;
    case 1:
        cout << endl << "LETS GO!" << endl << endl;;
        Battle battle;
        battle.Battletime();
        break;
    }
}
