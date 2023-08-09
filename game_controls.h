#ifndef GAME_CONTROLS_H
#define GAME_CONTROLS_H
#include <conio.h> // header for keypress recognition functions
#include <string> // header for using strings
#include "game_object.h"



//              game_controls Class
//            What it is used for:
//
//  (1) Initialize the game controls (game_controls)
//      - Up, Down, Right, Left, Quit, Restart, Help, Play
//  (2) Assign each game_controls's variables
//      - function, type, key, yShift, xShift
//  (3) Set the scope of which controls can be used at any given time (title screen, in-game, post-game)
//  (4) Take an input as a key press and match it to a control
//  (5) Execute the control which was called



class game_controls
{
private:
    std::string function; // name of the control (i.e. "Quit")
    std::string type; // type of control (move/menu). Used to clarify when a control should increment the turn/move an object vs. open/close a menu
    char key; // key which executes the control when pressed
    int yShift; // how the control changes the game object's y value (menu options = 0)
    int xShift; // how the control changes the game object's x value (menu options = 0)



public:
    game_controls();



    /* - Constructor - */
    game_controls(std::string function, std::string type, char key, int yShift, int xShift); // Used to define a control



    /* - Main Functions - */
    void set_TitleControls();   // Defines game controls that are valid BEFORE game (title screen) (i.e. "Play", "Help", "Scores", "Quit")

    void set_GameControls();    // Defines game controls that are valid DURING game (i.e. "Up", "Down", "Left", "Right", "Quit", "Restart", "Help")

    void set_EndGameControls(); // Defines game controls that are valid AFTER game has ended (either by win or lose) (i.e. "Quit", "Play Again", "Help")

    game_controls matchInputtoControl(char keyPress); // Recognizes key press, if the key matches a valid control, it returns the matching game_controls object

    void move(game_object& Object, bool& successful_move); // Uses a game_object object pointer and modifies the object's xVal and/or yVal according to the game_controls object which calls it (i.e. Up.move(User), Down.move(Elon)

    void rand_Move_Elon(game_object& Object);

    void executeGameControl(char keyPress, /*game_object &Object,*/ char grid[31][61], char display_box[][61], bool &TurnPassed,  bool &GameOver, bool& restart); // Main function called when keypress is recognized.
                                                                                    // Takes keypress, gameobject, and the game grid, executes specific control accordingly.
                                                                                    // Inner Functions: matchInputtoControl, move
    void executeTitleControl(char keyPress, bool& startGame);



    /* - Get Functions - */
    std::string getFunction(); // returns a game_controls object's "function" string

    std::string getType(); // returns a game_controls object's "type" string

    char getKey(); // returns a game_controls object's "key" character



    /* - Set Functions - */
    void setGameControl(std::string function, std::string type, char key, int yShift, int xShift); // Sets an already defined game_controls object's private variables

};


#endif // GAME_CONTROLS_H
