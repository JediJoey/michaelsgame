#include "game_object.h"
#include <iostream>

using namespace std;

/* - Functions needed from game_data.h - */
bool check_Elon_caught_twice();
void increment_caught_by_Elon();
void increment_DP(string function);
void increment_found_car(char symbol);
void increment_found_Roadster();



/* - Functions needed from display.h - */
void display_titleScreen();
void display_after_turn(char display_box[][61], game_object& User, game_object& Roadster);
void display_DisplayBox(char display_box[][61]);
void display_Controls(char display_box[][61]);
void display_Info(char display_box[][61]);
void display_FoundYugo(char display_box[][61]);
void display_FoundPinto(char display_box[][61]);
void display_FoundRoadster(char display_box[][61]);
void display_caught_by_Elon_1(char display_box[][61]);
void display_caught_by_Elon_2(char display_box[][61]);
void display_endScreen();



/* - Constructor - */
game_object::game_object()
{

}
game_object::game_object(char objectSymbol)
{
    this-> symbol = objectSymbol;
}
game_object::~game_object()
{

}



/* - Main Functions - */
char game_object::GameSpace[15][15] = // Initiate a 15x15 grid for the playable game spaces, filled with ' ' chars
        {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};

void clear_game_space()
{
    int numRows = 15;
    int numCols = 15;
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            game_object::GameSpace[i][j] = ' ';
        }
    }
}

void game_object::setRandGameSpace()
{
    do{
    this -> x = ((rand() % 15) + 1);
    this -> y = ((rand() % 15) + 1);
    }
    while(game_object::GameSpace[this -> y][this -> x]!= ' ');

    game_object::GameSpace[this -> y][this -> x] = this -> symbol;
}

void game_object::setNewGameSpace()
{
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 15; x++)
        {
            if(game_object::GameSpace[y][x] == this -> symbol)
            {
                game_object::GameSpace[y][x] = ' ';
            }
        }
    }

    game_object::GameSpace[this -> y][this -> x] = this -> symbol;
}

void GameSpace_to_Grid(char grid[31][61])
{
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 15; x++)
        {
            grid[(y*2)+1][(x*4)+2] = game_object::GameSpace[y][x];
        }
    }

}

void game_object::hide_show_object_in_UserRadius(game_object User)
{
    bool in_range = false;
    for(int i = -1; i < 2; i++)
    {



        for(int j = -1; j < 2; j++)
        {

            if(((this->y) == (User.y + i)) and ((this->x) == (User.x + j)))
            {
                in_range = true;
                goto show_symbol;
            }
            else
            {
                game_object::GameSpace[this->y][this->x] = ' ';
            }
        }
    }
    show_symbol:
    if(in_range == true)
    {
        game_object::GameSpace[this->y][this->x] = this -> symbol;

        increment_found_car(this->symbol);
    }
}

char game_object::check_for_object_collision(bool& object_collision, bool& caught_by_elon)
{
    char target_gamespace = game_object::GameSpace[this->y][this->x];

    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            char space_around_target = game_object::GameSpace[this->y + i][this->x + j];

            if(i == 0 and j == 0)
            {
                continue;
            }
            else if(space_around_target == 'E')
            {
                caught_by_elon = true;
                return('E');
            }
        }
    }
    if (target_gamespace != ' ')
    {
        object_collision = true;
        return target_gamespace;
    }

}

void run_object_collision_condition(char object_collision, bool& GameOver, char display_box[][61])
{
    if(object_collision == 'R')
    {
        system("CLS");
        display_endScreen();
        display_FoundRoadster(display_box);
        increment_found_car('R');
        increment_found_Roadster();
        GameOver = true;
                //run the function which shows the end game options
    }
    else if(object_collision == 'Y')
    {
        system("CLS");
        display_endScreen();
        display_FoundYugo(display_box);
        GameOver = true;
                // run the function for starman animation
                //run the function which shows the end game options
    }
    else if(object_collision == 'P')
    {
        system("CLS");
        display_endScreen();
        display_FoundPinto(display_box);
        GameOver = true;
                // run the function for starman animation
                //run the function which shows the end game options
    }
    else if(object_collision == 'E')
    {
        system("CLS");
//        display_endScreen();
        increment_caught_by_Elon();
        GameOver = check_Elon_caught_twice();
        if(GameOver == true)
        {
            display_endScreen();
            display_caught_by_Elon_2(display_box);
        }

        else
        {
            display_caught_by_Elon_1(display_box);
        }
                // if the game_data for elon shows this is the 2nd time he's caught you
                        // run the function for starman animation
                        //run the function which shows the end game options
                // else, display warning for 1st time caught and continue
    }
}



/* - Get Functions - */
int game_object::get_x()
{
    char x = this->x;
    return x;
}

int game_object::get_y()
{
    char y = this->y;
    return y;
}

char game_object::getSymbol()
{
    return symbol;
}



/* - Set Functions - */
void game_object::setSymbol(char objectSymbol)
{
    this-> symbol = objectSymbol;
}

void game_object::set_x(int objectX)
{
    this-> x = objectX;
}

void game_object::set_y(int objectY)
{
    this-> y = objectY;
}

//void game_object::testUp()
//{
//    int currY = this->y;
//    int newY = currY - 1;
//    this->y = newY;

//    char symbol = this -> symbol;

//    game_object::GameSpace[this->y][this->x] = symbol;

//}
