#include <iostream>

#include "Game.h"

using namespace std;


Game new_game;




int main()
{
    cout << "\t\t\t\t------------------------------------------------------\n";
    cout << "\t\t\t\t------------------------------------------------------\n";
    cout << "\t\t\t\t|                   WELCOME                           |\n";
    cout << "\t\t\t\t-------------------------------------------------------\n";
    cout << "\t\t\t\t\t LOADING "; 
    char x = 219;
    for (int i = 0; i < 30; i++)
    {
        cout << x;
        if (i < 10)
        {
            Sleep(300);
        }
        Sleep(100);
    }
    system("cls");   

    new_game.game();
    
    return 0;
}