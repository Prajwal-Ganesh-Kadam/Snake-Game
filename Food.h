#pragma once

#include <windows.h>
#include <cstdlib>  //to pass shell/console commands. Also includes rand() .

#define WIDTH 50  
#define HEIGHT 25

class Food
{
private:
    COORD pos;

public:
    void gen_food();
    COORD get_pos();
};


void Food ::gen_food()
{
    //Formula to generate random no. in range U to L --> rand() % (U -L +1) + L
    //if we keep 0 as lower limit then there is a chance of getting generated on the wall (L is included while U is not)
    //so this formula is modified a little as per our requiremnets
    pos.X = rand() % (WIDTH -3 ) + 1; //(WIDTH-1+1)
    pos.Y = rand() % (HEIGHT - 3 )+ 1;                       
}

COORD Food ::get_pos()
{
    return pos;
}