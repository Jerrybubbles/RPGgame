#include "game.h"
#include <fstream>
#include <vector>
#include <sstream>

Game::Game(string path): path{path}
{

}

void Game::Start()
{
    bool loop = true;
    while(loop){
        unsigned char choice;
        string fileNaam = getPath();
        cout << "Enter a om te starten" << endl;
        cout << "Enter b om monsters bij te creeren" << endl;
        cout << "Enter c om monsters te bekijken" << endl;
        cout << "Enter d om het spel te verlaten" << endl << endl;
        cout << "Keuze:";

        cin >> choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout << "Wrong input!" << endl;
            cin >> choice;
        }

        switch (choice)
        {
        default:
            cout << "Byebye!" << endl;
            loop = false;
            break;
        case 'b':
            maakMonster(fileNaam);
            break;
        case 'c':
            printMonsters(fileNaam);
            break;
        case 'a':
            cout << endl << "LETS GO!" << endl << endl;;
            Battle battle{getPath()};
            battle.Battletime();
            break;
         }
    }

}

void Game::maakMonster(string fileNaam)
{
    string naam;
    int hitpoints, minDamage, maxDamage;
    fstream fileOut;
    fileOut.open(fileNaam, std::ios_base::app);

    cout << "Geef de volgende gegevens in:\nNaam:";
    cin >> naam;
    cout << "Hp:";
    cin >> hitpoints;
    cout << "minDamage:";
    cin >> minDamage;
    cout << "maxDamage:";
    cin >> maxDamage;

    cout << "Het monster met naam " << naam << " en HP van " << hitpoints << " met aanval: " << minDamage << "-" << maxDamage << " is gemaakt." << endl;
    fileOut << naam << "," << hitpoints << "," << minDamage << "," << maxDamage << "\n";
    fileOut.close();
}

void Game::printMonsters(string fileNaam)
{
    string gelezenRij = " ",kolom,temp;
    fstream fileIn;
    vector<string> rij;
    fileIn.open(fileNaam, ios::in);
    cout << "Lijst van alle monsters en hun data:" << endl << endl;

    while(gelezenRij != ""){
        rij.clear();

        getline(fileIn, gelezenRij);

        if( fileIn.eof() ){
            break;
        }

        stringstream strstrm(gelezenRij);
        while (getline(strstrm, kolom, ','))
        {
            rij.push_back(kolom);
        }

        cout << "Naam:" << rij[0] << "\nHp:" << rij[1] << "\nDamage: " << rij[2] << "-" << rij[3] << endl << endl;

    }

}
