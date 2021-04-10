#pragma once

#include <windows.h> //to handle cursors position on console
#include <conio.h>   //to capture keystrokes
#include <ctime>     //to seed the random function

#include "Snake.h"
#include "Food.h"

using namespace std;

#define WIDTH 50
#define HEIGHT 25

Snake snake({WIDTH / 2, HEIGHT / 2}, 1);
Food food;

class Game
{
private:
    vector<COORD> snake_body = snake.get_body();
    int score;
    int speed;

public:
    void game();
    void game_board();
    void running();
    bool game_over();
    void clearScreen();
};

void Game::game()
{
    do
    {

        system("cls");

        srand(time(NULL));
        food.gen_food();
        score = 0;
        speed = 10;
        cout << "SCORE: " << score << "\n\n";
        running();
    } while (game_over());
}

void Game::game_board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    vector<COORD> snake_body = snake.get_body();

    cout << "\n\n";
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t#";
        for (int j = 0; j < WIDTH - 2; j++) //as every row starts and ends with one wall
        {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if (i == snake_pos.Y && j + 1 == snake_pos.X)
                cout << "0";
            else if (i == food_pos.Y && j + 1 == food_pos.X)
                cout << "*";
            else
            {
                bool isBodyPart = false;
                for (int k = 0; k < snake_body.size() - 1; k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << "o";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart)
                {
                    cout << " ";
                }
            }
        }
        cout << "#\n";
    }
}

void Game::running()
{
    system("cls");
    bool game_over = false;
    while (!game_over)
    {
        clearScreen();
        cout << "SCORE: " << score << "\n\n";
        game_board();
        if (kbhit()) //stands for keyboard hit.returns true when you hit a key on keyboard
        {
            char temp = getch();
            if (temp == 'w' || temp == 72)
            {
                snake.change_dir('u');
            }
            else if (temp == 'a' || temp == 75)
            {
                snake.change_dir('l');
            }
            else if (temp == 's' || temp == 80)
            {
                snake.change_dir('d');
            }
            else if (temp == 'd' || temp == 77)
            {
                snake.change_dir('r');
            }
        }

        if (snake.collided())
            game_over = true;

        if (snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
            score = score + 10;
        }

        snake.move_snake();

        // system("cls");  //but this causes flickering of board
        // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0}); //This can also be done
    }
}

bool Game::game_over()
{
    cout << "======GAME OVER======" << endl;
    // cout << "replay ?? (y/n) " << endl;
    cout << "YOUR SCORE :  "<< score <<endl;
    return false;
}

void Game::clearScreen()
{
    // Function which cleans the screen without flickering
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}