#include "game_object.h"
#include "game_controls.h"
#include "game_data.h"
#include "display.h"

#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>


using namespace std;
void GameSpace_to_Grid(char grid[31][61]);

void displayGameBoard(char grid[31][61]);

void setGridLines(char grid[][61])
{
//    char grid[numRows][numCols];
    //initialize grid full of spaces
    const int numRows = 31;
    const int numCols = 61;
    for (int i = 0; i < numRows; i++)
    {
         for (int j = 0; j < numCols; j++)
         {
            grid[i][j] = ' ';
         }
    }
    // corners
    grid[0][0] = (char)218;   // top left
    grid[0][numCols - 1] = (char)191;   // top right
    grid[numRows - 1][0] = (char)192;  // bottom left
    grid[numRows - 1][numCols - 1] = (char)217; // bottom right

    // top row: ┬
    for (int j = 4; j < numCols - 1; j = j + 4)
    {
        grid[0][j] = (char)194;
    }

    // bottom row: ┴
    for (int j = 4; j < numCols - 1; j = j + 4)
    {
        grid[numRows - 1][j] = (char)193;
    }

    // right side: ┤
    for (int i = 2; i < numRows - 1; i = i + 2)
    {
        grid[i][numCols - 1] = (char)180;
    }

    // left side: ┤
    for (int i = 2; i < numRows - 1; i = i + 2)
    {
        grid[i][0] = (char)195;
    }

    // verticals: │
    for(int j = 0; j < numCols; j = j + 4)
    {
        for (int i = 1; i < numRows - 1; i = i + 2)
        {
            grid[i][j] = (char)179;
        }
    }

    // Horizontals: ─
    for (int i = 0; i < numRows; i = i + 2)
    {
        for (int j = 1; j < numCols; j++)
        {
            if (j % 4 != 0)
            {
                grid[i][j] = (char)196;
            }
        }
    }

    // Crosses: ┼
    for (int i = 2; i < numRows - 1; i = i + 2)
    {
         for (int j = 4; j < numCols - 1; j = j + 4)
         {
            grid[i][j] = (char)197;
         }
    }

    return;
}

void setDisplayBox(char grid[][61]);

void display_GBwithGS(char grid[31][61])
{
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 15; x++)
        {
            grid[(y*2)+1][(x*4)+2] = game_object::GameSpace[y][x];
        }
    }
    const int numRows = 31;
    const int numCols = 61;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void display_titleScreen();

void display_Info(char display_box[][61]);

void display_Controls(char display_box[][61]);

void display_after_turn(char display_box[][61], game_object& User, game_object& Roadster);

void display_Elon_awake(char display_box[][61]);

void display_endScreen();

void display_stats(char display_box[][61]);

bool check_Elon_caught_once();

void clear_game_space();

void reset_Turns();

void reset_caught_by_Elon();

int get_Turn();

void rand_Move_Elon(game_object& Object);

game_controls matchInputtoControl(char keyPress);




game_object Roadster('R'); // Create Roadster, shown as "R" in game
game_object Pinto('P'); // Create Pinto, shown as "P" in game
game_object Yugo('Y'); // Create Yugo, shown as "Y" in game
game_object User('U'); // Create User, shown as "U" in game
game_object Elon('E'); // Create Elon, shown as "E" in game

void hide_show_ALL_objects_in_UserRadius(game_object User, char grid[][61])
{
    Roadster.hide_show_object_in_UserRadius(User);
    Pinto.hide_show_object_in_UserRadius(User);
    Yugo.hide_show_object_in_UserRadius(User);
    Elon.hide_show_object_in_UserRadius(User);
    GameSpace_to_Grid(grid); // Place objects in GameSpace[15][15] into correct spaces on Grid[31][61]
}

void executeGameControl(char keyPress, game_object& User, game_object& Car, char grid[31][61],  char display_box[][61], bool& TurnPassed, bool& GameOver,
void hide_show_ALL_objects_in_UserRadius(game_object User, char grid[][61]), bool& restart);




void Game() // The main game method
{

    /* Title Screen */
    char keyPress; // define a char variable to store user key press

    const int numRows_DisplayBox = 20;
    const int numCols_DisplayBox = 61;
    char display_box[numRows_DisplayBox][numCols_DisplayBox];
    setDisplayBox(display_box);
    display_titleScreen(); // show title/ authors in place of game board
    while(true)
    {
        if(kbhit()) // Loop iterates after user presses a key
        {
            keyPress = getch(); //Gets user key press
            if(keyPress == 'p')
            {
                goto Setup;
            }

            else if(keyPress == 'i')
            {
                system("CLS");
                display_titleScreen();

                display_Info(display_box);
            }

            else if(keyPress == 'c')
            {
                system("CLS");
                display_titleScreen();

                display_Controls(display_box);
            }
            else
            {
                continue;
            }

        }
    }
Setup:
    {
        clear_game_space();
    }
    /* Game Setup */
    reset_Turns();
    reset_caught_by_Elon();
    system("CLS");
    const int numRows_Grid = 31;
    const int numCols_Grid = 61;
    bool ElonAwake = false;
    bool restart = false;
    bool TurnPassed;
    char grid[numRows_Grid][numCols_Grid]; // create correctly-sized array for Grid lines
    setGridLines(grid); // Place ASCII characters into grid[31][61] to form grid lines

    Roadster.setRandGameSpace(); // Place "R" at random space in GameSpace[15][15]
    Pinto.setRandGameSpace(); // Place "P" at random space in GameSpace[15][15]
    Yugo.setRandGameSpace(); // Place "Y" at random space in GameSpace[15][15]
    User.setRandGameSpace(); // Place "U" at random space in GameSpace[15][15]
    Elon.setRandGameSpace(); // Place "E" at random space in GameSpace[15][15]
    hide_show_ALL_objects_in_UserRadius(User, grid);
    GameSpace_to_Grid(grid); // Place objects in GameSpace[15][15] into correct spaces on Grid[31][61]
    displayGameBoard(grid); // Display the GameBoard in console

    display_after_turn(display_box, User, Roadster);

    /* Game Loop */

    while(true)
    {

        if(kbhit()) // Loop iterates after user presses a key
        {

            TurnPassed = false;
            bool GameOver = false;
            ElonAwake = false;
            int Turn = get_Turn();

            keyPress = getch(); //Gets user key press
            executeGameControl(keyPress, User, Roadster, grid, display_box, TurnPassed, GameOver, hide_show_ALL_objects_in_UserRadius, restart); // executes control if keypress is valid
            if(restart == true)
            {
                goto Setup;
            }
            if(ElonAwake == true and TurnPassed == true)
            {
                rand_Move_Elon(Elon);
                GameSpace_to_Grid(grid);
            }
            bool Elon_caught_once = check_Elon_caught_once();

            if(Elon_caught_once == true)
            {
                Elon.setRandGameSpace();
                Elon.setNewGameSpace();
                GameSpace_to_Grid(grid);
                Elon.hide_show_object_in_UserRadius(User);
                GameSpace_to_Grid(grid);
                if(ElonAwake == false)
                {
                    ElonAwake = true;
                }
            }

            if(GameOver == true)
            {
                goto EndGame;
            }

            if(Turn == 4 and GameOver == false)
            {
                system("CLS");
                ElonAwake = true;
                displayGameBoard(grid);
                display_Elon_awake(display_box);
            }

        }
    }
    EndGame:
    {
        while(true)
        {
            if(kbhit()) // Loop iterates after user presses a key
            {
               keyPress = getch();
               if(keyPress == 'p')
               {
                   goto Setup;
               }
               else if(keyPress == 's')
               {
                   system("CLS");
                   display_endScreen();
                   display_stats(display_box);
               }
            }

        }

    }

}
