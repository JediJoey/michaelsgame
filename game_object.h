#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string>
#include <ctime>



//              game_object Class
//            What it is used for:
//
//  (1) Initialize the 5 in game objects (GameObjects)
//      - User, Roadster, Yugo, Pinto, Elon
//  (2) Assign each game_object's variables
//      - name, symbol in the game, x/y coordinates in game)
//  (3) Create the playable 15x15 grid with an array (static char GameSpace[15][15])
//      - GameSpace[15][15]: initialized with spaces
//      - GameSpace[15][15]: called on by Setup() to randomly place GameObjects
//      - GameSpace[15][15]: placed inside grid[31][61]
//  (4) Print the grid with the gameobjects
//      - This shows all the objects on the board for easier reference/ debugging
//      - The real game will have most objects hidden until within 3 spaces of 'U'



class game_object
{
private:
    char symbol;


public:

    /* - public variables - */
    int x; // game_object object's x coordinate on the game grid.
    int y; // game_object object's y coordinate on the game grid.
    //the values for a game_object's coordinates must be public so that the functions from game_controls can access and modify them


    /* - Constructors - */
    game_object();
    game_object(char objectSymbol); // Do not need to initialize a game_object's coordinates since they will be random upon startup
    ~game_object(); //Deconstructor (not used)


    /* - Main Functions - */
    static char GameSpace[][15]; // static array for the 15x15 "GameSpace"
    void clear_game_space();     //clears the gameSpace in between games
                                 // The 225 empty spaces of the "grid" which corispond to the playable areas of the game
                                 // assigned as "static" so that all game_object's share a single 15x15 array
    void setRandGameSpace(); // sets the x and y coordinates of a game object to a random, empty space on the 15x15 GameSpace
    void setNewGameSpace(); // Used after a game_object's x and/or y values have changed
                            // replaces the game_object's character with a ' ' character at its OLD location on the GameSpace
                            // prints the game_object's character at its NEW location on the GameSpace
    void GameSpace_to_Grid(char grid[31][61]); // Takes the current game_object's in the 15x15 GameSpace and places them into the correct locations on the grid
    void displayGameBoard(char grid[31][61]); // Displays the entire Game Grid (will move to the display class later)
    char check_for_object_collision(bool& object_collision, bool& caught_by_elon); // called with a game_object, AFTER its new position has been set, but BEFORE it is sent to the Game Space
                                                        // returns true and displays condition if the object's new position contains another object, else returns false and void
                                                        // i.e. User.check_for_object_collision(char grid[31][61]) returns true and displays win condiiton if the object 'R'
    void run_object_collision_condition(char object_collision, bool& GameOver, char display_box[][61]);
    void hide_show_object_in_UserRadius(game_object User);

    /* - Get Functions - */
    int get_x(); // returns a game_object's x value
    int get_y(); // returns a game_object's y value
    char getSymbol(); // returns a game_object's character


    /* - Set Functions - */
    void setSymbol(char symbol); // sets a game_object's character
    void set_x(int x); // sets a game_object's x value
    void set_y(int y); // sets a game_object's y value

};


#endif // GAME_OBJECT_H
