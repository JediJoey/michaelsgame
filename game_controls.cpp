#include "game_controls.h"
#include "game_object.h"
#include "game_data.h"
#include <iostream>

using namespace std;

/* - Functions from game_object.h - */
void GameSpace_to_Grid(char grid[31][61]);
void displayGameBoard(char grid[31][61]);
void run_object_collision_condition(char object_collision, bool& GameOver, char display_box[][61]);

/* - Functions from game_data.h - */
void increment_Turn();
void display_Turn();
void display_caught_by_Elon_times();



/* - Functions from display.h - */
void display_after_turn(char display_box[][61], game_object& User, game_object& Roadster);
void display_Elon_awake(char display_box[][61]);
void display_Controls(char display_box[][61]);
void display_Info(char display_box[][61]);


/* - Constructors - */
game_controls::game_controls()
{

}

game_controls::game_controls(string controlFunction, string controlType, char controlKey, int controlYShift, int controlXShift)
{
    this-> function = controlFunction;
    this-> type = controlType;
    this-> key = controlKey;
    this-> yShift = controlYShift;
    this-> xShift = controlXShift;
}



/* - Game Controls (definitions) - */
game_controls Play("Play", "Menu", 'p', 0, 0);
game_controls Quit("Quit","Menu", 'q', 0, 0);
game_controls Restart("Restart","Menu", 'r', 0, 0);
game_controls Help("Info","Menu", 'i', 0, 0); // press 'i' to open Info
game_controls Options("Controls","Menu", 'c', 0, 0); // press 'c' to open controls
game_controls Up("Up", "Move", (char)72, -1, 0);
game_controls Right("Right", "Move", (char)77, 0, 1);
game_controls Left("Left", "Move", (char)75, 0, -1);
game_controls Down("Down", "Move", (char)80, 1, 0);



/* - Main Functions - */
void set_TitleControls()  // Defines game controls that are valid BEFORE game (title screen)
{
//    game_controls Play("Play", "Menu", 'p', 0, 0);
}

void set_GameControls();    // Defines game controls that are valid DURING game

void set_EndGameControls(); // Defines game controls that are valid AFTER game has ended (either by win or lose)

game_controls matchInputtoControl(char keyPress)
{
   game_controls inputControl;
   if (keyPress == 'p')
   {
       inputControl = Play;
   }
   if (keyPress == 'q')
   {
       inputControl = Quit;
   }
   else if(keyPress == (char)72)
   {
       inputControl = Up;
   }
   else if(keyPress == (char)77)
   {
       inputControl = Right;
   }
   else if(keyPress == (char)75)
   {
       inputControl = Left;
   }
   else if(keyPress == (char)80)
   {
       inputControl = Down;
   }
   else if(keyPress == 'i')
   {
       inputControl = Help;
   }
   else if(keyPress == 'c')
   {
       inputControl = Options;
   }
   else if(keyPress == 'r')
   {
       inputControl = Restart;
   }
   return inputControl;
}

void executeGameControl(char keyPress, game_object& Object, game_object& Car, char grid[31][61],  char display_box[][61], bool& TurnPassed,
bool& GameOver, void hide_show_ALL_objects_in_UserRadius(game_object User, char grid[][61]), bool& restart) // Function which will execute a specific when called with a specific key (i.e. ExecuteGameControl('q') will quit)
{
//    string type = checkControlType(keyPress);
//    string direction;
    game_controls inputControl = matchInputtoControl(keyPress);
    bool successfulMove = false;
    if(inputControl.getType() == "Move")
    {
        TurnPassed = true;
        bool object_collision = false;
        bool caught_by_elon = false;
        if(inputControl.getFunction() == "Up")
        {
            Up.move(Object, successfulMove);
        }
        else if(inputControl.getFunction() == "Left")
        {
            Left.move(Object, successfulMove);
        }
        else if(inputControl.getFunction() == "Right")
        {
            Right.move(Object, successfulMove);
        }
        else if(inputControl.getFunction() == "Down")
        {
            Down.move(Object, successfulMove);
        }
        if(successfulMove == false)
        {
            return;
        }
        else
        {
            increment_Turn();

            hide_show_ALL_objects_in_UserRadius(Object, grid);

            char target_gamespace = Object.check_for_object_collision(object_collision, caught_by_elon);
            if (object_collision == true)
            {
                system("CLS");
                displayGameBoard(grid);
                run_object_collision_condition(target_gamespace, GameOver, display_box);
            }
            else if (caught_by_elon == true)
            {
                system("CLS");
                Object.setNewGameSpace();
                GameSpace_to_Grid(grid);
                displayGameBoard(grid);
                run_object_collision_condition(target_gamespace, GameOver, display_box);
            }
            else
            {
                Object.setNewGameSpace();
                system("CLS");
                GameSpace_to_Grid(grid); // Place objects in GameSpace[15][15] into correct spaces on Grid[31][61]
                displayGameBoard(grid); // Display the GameBoard in console
                display_after_turn(display_box, Object, Car);
            }
//            cout << "User: (" << Object.get_y() << ", " << Object.get_x() << ")" << endl;
//            cout << "Roadster: (" << Car.get_y() << ", " << Car.get_x() << ")" << endl;
        }
    }
    else if(inputControl.getType() == "Menu")
    {
        if(inputControl.getFunction() == "Quit")
        {
            exit(0);
        }
        else if(inputControl.getFunction() == "Restart")
        {
            restart = true;
        }
        else if(inputControl.getFunction() == "Info")
        {
            system("CLS");
            displayGameBoard(grid);
            display_Info(display_box);
        }
        else if(inputControl.getFunction() == "Controls")
        {
            system("CLS");
            displayGameBoard(grid);
            display_Controls(display_box);
        }
        else if(inputControl.getFunction() == "Play")
        {
            system("CLS");
            displayGameBoard(grid);
            display_after_turn(display_box, Object, Car);
        }
    }
}



/* - Move Functions - */
void game_controls::move(game_object& Object, bool& successful_move)
{

    int yChange = this->yShift;
    int xChange = this->xShift;

    if (Object.get_y() + this->yShift == 15 and (Object.get_y() != 14 or Object.get_y() != 15))
    {
        successful_move = false;
    }
    else if (Object.get_y() + this->yShift == -1 and (Object.get_y() != 0 or Object.get_y() != -1))
    {
        successful_move = false;
    }
    else if (Object.get_x() + this->xShift == 15 and (Object.get_x() != 14 or Object.get_x() != 15))
    {
        successful_move = false;
    }
    else if (Object.get_x() + this->xShift == -1 and (Object.get_x() != 0 or Object.get_x() != -1))
    {
        successful_move = false;
    }
    else
    {
        successful_move = true;
        Object.y = Object.y + yChange;
        Object.x = Object.x + xChange;
    }
}

void rand_Move_Elon(game_object& Object)
{
    int rand_move;
    bool successful_move = false;

    while(successful_move == false)
    {
        rand_move = (rand() % 4) + 1;
        if(rand_move == 1)
        {
            Up.move(Object, successful_move);
        }
        if(rand_move == 2)
        {
            Left.move(Object, successful_move);
        }
        if(rand_move == 3)
        {
            Down.move(Object, successful_move);
        }
        if(rand_move == 4)
        {
            Right.move(Object, successful_move);
        }
    }
}



/* - Get Functions - */
string game_controls::getFunction()
{
    return function;
}

string game_controls::getType()
{
    return type;
}

char game_controls::getKey()
{
    return key;
}



/* - Set Functions - */
void game_controls::setGameControl(string controlFunction, string controlType, char controlKey, int yShift, int xShift)
{
    this-> function = controlFunction;
    this-> type = controlType;
    this-> key = controlKey;
}


/* - Prototype/ Unused Functions - */

//string checkControlType(char keyPress)
//{
//    string type;
//    if (keyPress == (char)72 || keyPress == (char)77 || keyPress == (char)75 || keyPress == (char)80)
//    {
//        type = "Move";
//    }
//    else
//    {
//        type = "Menu";
//    }
//    return type;
//}
