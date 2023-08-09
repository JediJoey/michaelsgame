#include "display.h"

using namespace std;

/* - Functions from game_data.h - */
void increment_Turn();
void display_Turn();
void display_caught_by_Elon_times();
string return_Turn();
string return_caught_by_Elon_times();
string return_total_caught_by_Elon_times();
string return_Pinto();
string return_Yugo();
string return_Roadster();


/* - Constructors - */
Display::Display(string message)
{
    this->message = message;
}



/* - Display (definitions) - */
Display Info               ("                  WElCOME TO TESLA!                        "
                            "The goal of this game is to find Elon Musk's               "
                            "'Roadster', without getting caught by Elon, or getting in  "
                            "the wrong car. Once the Game starts, you ('U'), Elon ('E'),"
                            "the Yugo ('Y'), the Pinto ('P'), and the Roadster ('R')    "
                            "will be randomly placed on the game board. You will not be "
                            "able to see Elon or the cars until they are right next to  "
                            "you. After 5 turns, or if you run into him yourself, Elon  "
                            "will wake up and begin searching for you at random. The    "
                            "first time you run iunto Elon, he will let you escape and  "
                            "teleport himself to a random location, but after that, he  "
                            "will send you to mars to be the Star Man! If you get into  "
                            "the Pinto or Yugo, Elon will also catch you. The game will "
                            "give you a hint about the Roadster's location after every  "
                            "turn. Good Luck!");

Display Controls            (" FUNCTION |      KEY                                       "
                             "-----------------------------------------------------------"
                             "    Up    |  'Up Arrow'                                    "
                             "-----------------------------------------------------------"
                             "   Down   |  'Down Arrow'                                  "
                             "-----------------------------------------------------------"
                             "   Left   |  'Left Arrow'                                  "
                             "-----------------------------------------------------------"
                             "   Right  |  'Right Arrow'                                 "
                             "-----------------------------------------------------------"
                             "   Info   |       'i'                                      "
                             "-----------------------------------------------------------"
                             "  Restart |       'r'                                      "
                             "-----------------------------------------------------------"
                             "   Quit   |       'q'                                      "
                             "-----------------------------------------------------------"
                             "Play/Back |       'p'                                      "
                             " to Game  |");
Display FoundYugo           ("OH NO! YOU ENTERED THE YUGO!                               * Elon makes you the Star Man *");
Display FoundPinto          ("OH NO! YOU ENTERED THE YUGO!                               * Elon makes you the Star Man *");
Display FoundRoadster       ("CONGRATULATIONS! YOU FOUND THE ROADSTER!                   * you successfuly escape in the Roadster *");
Display caught_by_Elon_1    ("OH NO! ELON HAS CAUGHT YOU!                                * you successfuly escape from him.... this time.... *");
Display caught_by_Elon_2    ("OH NO! ELON HAS CAUGHT YOU AGAIN!                          * Elon makes you the Star Man *");
Display Elon_awake          ("UH OH! ELON HEARD YOU!                                     * Elon wakes up and begins searching for you *");

// Hints
Display Roadster_far        ("...the Roadster is far");
Display Roadster_notsoFar        ("...the Roadster is not so far");
Display Roadster_close        ("...the Roadster is close!");
Display Roadster_veryClose        ("...you are so close to the Roadster!");


/* - Main Functions - */
void Display::message_to_display_box(char display_box[][61])
{
    const int numRows_DisplayBox = 20;
    const int numCols_DisplayBox = 61;
    int r = 0;
    for(int i = 0; i < numRows_DisplayBox - 1; i++ )
    {
        for(int j = 0; j < numCols_DisplayBox - 1; j++ )
        {
            if(display_box[i+1][j+1] == (char)179)
            {
                r = r - 2;
                goto endLine;
            }

                if((j) + ((i) * (numCols_DisplayBox)) <= message.size() - r)
                {
                     display_box[i+1][j+1] = this->message[r + (j) + ((i) * (numCols_DisplayBox))];
                }

                else
                {
                    break;
                }

        }
        endLine:
        {

        }
    }

}

void displayDisplayBox(char display_box[][61])
{
    const int numRows = 20;
    const int numCols = 61;
    for (int i = 0; i < numRows; i++)
    {
        cout << '\t'<< '\t'<< '\t';
        for (int j = 0; j < numCols; j++)
        {
            cout << display_box[i][j];
        }
        cout << endl;
    }
}

void setDisplayBox(char display_box[][61])
{
    //initialize grid full of spaces
    const int numRows = 20;
    const int numCols = 61;
    for (int i = 0; i < numRows; i++)
    {
         for (int j = 0; j < numCols; j++)
         {
            display_box[i][j] = ' ';
         }
    }

    // corners
    display_box[0][0] = (char)218;   // top left
    display_box[0][numCols - 1] = (char)191;   // top right
    display_box[numRows - 1][0] = (char)192;  // bottom left
    display_box[numRows - 1][numCols - 1] = (char)217; // bottom right
    // Left verticals: │
    for (int i = 1; i < numRows - 1; i++)
    {
        display_box[i][0] = (char)179;
    }

    // Right verticals: │
    for (int i = 1; i < numRows - 1; i++)
    {
        display_box[i][numCols - 1] = (char)179;
    }

    // Top Horizontals: ─
    for (int j = 1; j < numCols - 1; j++)
    {

            display_box[0][j] = (char)196;
    }
    // Bottom Horizontals: ─
    for (int j = 1; j < numCols - 1; j++)
    {

            display_box[numRows - 1][j] = (char)196;
    }
}

void displayGameBoard(char grid[31][61])
{
    const int numRows = 31;
    const int numCols = 61;
    cout << '\n' << '\n' << '\n';
    for (int i = 0; i < numRows; i++)
    {
        cout << '\t'<< '\t'<< '\t';
        for (int j = 0; j < numCols; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

string spaces_to_end_of_line(string message)
{
    const int numCols_DisplayBox = 59;
    const int end_of_line = numCols_DisplayBox - message.size();
    string spaces;
    for(int i = 0; i < end_of_line; i++)
    {
        spaces.push_back(' ');
    }
    return spaces;
}


/* - Display (functions) - */
void display_titleScreen()
{
    // TESLA logo
    cout << '\n' << '\n' << '\n';
    cout << "                        " << "   _______    ______     _____    _                  " << endl;
    cout << "                        " << "  |__   __|  |  ____|   / ____|  | |           /\\     " << endl;
    cout << "                        " << "     | |     | |__     | (___    | |          /  \\    " << endl;
    cout << "                        " << "     | |     |  __|     \\___ \\   | |         / /\\ \\   " << endl;
    cout << "                        " << "     | |     | |____    ____) |  | |____    / ____ \\  " << endl;
    cout << "                        " << "     |_|     |______|  |_____/   |______|  /_/    \\_\\ " << endl;
    cout << "                        " << "          By: Max Scholtes & Michael Wauligman" << endl;
    cout << "                        " << "                  Press 'p' to play" << endl;
    cout << "                        " << "                Press 'i' for game info" << endl;
    cout << "                        " << "              Press 'c' for game controls" << endl;
    cout << endl;
    cout << "                        " << "       *** MAKE SURE CAPSLOCK IS OFF TO PLAY ***" << endl;

}

void display_after_turn(char display_box[][61], game_object& User, game_object& Roadster)
{
    string Hint;
//    if ((fabs(Roadster.get_x() - User.get_x()) > 8) and (fabs(Roadster.get_y() - User.get_y()) > 8))
//    {
//        Hint = Roadster_far.get_message();
//    }
//    else if (((fabs(Roadster.get_x() - User.get_x()) <= 8) and (fabs(Roadster.get_x() - User.get_x()) > 5)) and ((fabs(Roadster.get_y() - User.get_y()) <= 8) and (fabs(Roadster.get_y() - User.get_y()) > 5)))
//    {
//        Hint = Roadster_notsoFar.get_message();
//    }
//    else if (((fabs(Roadster.get_x() - User.get_x()) <= 5) and (fabs(Roadster.get_x() - User.get_x()) > 3)) and ((fabs(Roadster.get_y() - User.get_y()) <= 5) and (fabs(Roadster.get_y() - User.get_y()) > 3)))
//    {
//        Hint = Roadster_close.get_message();
//    }
//    else if ((fabs(Roadster.get_x() - User.get_x()) < 3) and (fabs(Roadster.get_y() - User.get_y()) < 3))
//    {
//        Hint = Roadster_veryClose.get_message();
//    }
    double distance = sqrt(pow((static_cast<double>(Roadster.get_x()) - static_cast<double>(User.get_x())),2) + pow((static_cast<double>(Roadster.get_y()) - static_cast<double>(User.get_y())),2));
    if (distance > 8)
    {
        Hint = Roadster_far.get_message();
    }
    else if ((distance <= 8) and (distance > 5))
    {
        Hint = Roadster_notsoFar.get_message();
    }
    else if ((distance <= 5) and (distance > 3))
    {
        Hint = Roadster_close.get_message();
    }
    else if (distance <= 3)
    {
        Hint = Roadster_veryClose.get_message();
    }
    Display after_turn(return_Turn() + spaces_to_end_of_line(return_Turn())
                       + return_caught_by_Elon_times() + spaces_to_end_of_line(return_caught_by_Elon_times())
                       + Hint + spaces_to_end_of_line(Hint) +
                       "(Press 'c' for help)" );
    setDisplayBox(display_box);
    after_turn.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_Info(char display_box[][61])
{
    setDisplayBox(display_box);
    Info.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_Controls(char display_box[][61])
{
    setDisplayBox(display_box);
    Controls.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_FoundYugo(char display_box[][61])
{
    setDisplayBox(display_box);
    FoundYugo.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_FoundPinto(char display_box[][61])
{
    setDisplayBox(display_box);
    FoundPinto.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_FoundRoadster(char display_box[][61])
{
    setDisplayBox(display_box);
    FoundRoadster.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_caught_by_Elon_1(char display_box[][61])
{
    setDisplayBox(display_box);
    caught_by_Elon_1.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_caught_by_Elon_2(char display_box[][61])
{
    setDisplayBox(display_box);
    caught_by_Elon_2.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_Elon_awake(char display_box[][61])
{
    setDisplayBox(display_box);
    Elon_awake.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}

void display_endScreen()
{
    // TESLA logo
    cout << "                        " << "   _____                         ____                 _ " << endl;
    cout << "                        " << "  / ____|                       / __ \\               | |" << endl;
    cout << "                        " << " | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __| |" << endl;
    cout << "                        " << " | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__| |" << endl;
    cout << "                        " << " | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |  |_|" << endl;
    cout << "                        " << "  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|  (_)" << endl;
    cout << "                        " << "                                            " << endl;
    cout << "                        " << "             Press 'p' to play again" << endl;
    cout << "                        " << "     Press 's' to see your total game stats" << endl;

}

void display_stats(char display_box[][61])
{
    Display Stats(return_Turn() + spaces_to_end_of_line(return_Turn())
                  + return_Pinto() + spaces_to_end_of_line(return_Pinto())
                  + return_Yugo() + spaces_to_end_of_line(return_Yugo())
                  + return_total_caught_by_Elon_times() + spaces_to_end_of_line(return_total_caught_by_Elon_times())
                  + return_Roadster());
    Stats.message_to_display_box(display_box);
    displayDisplayBox(display_box);
}



/* - Set Functions - */
void Display::set_message(string message)
{
    this->message = message;
}



/* - Get Functions - */
string Display::get_message()
{
    return this->message;
}

string get_hint_far()
{
    return Roadster_far.get_message();
}

string get_hint_notsoFar()
{
    return Roadster_notsoFar.get_message();
}

string get_hint_close()
{
    return Roadster_close.get_message();
}

string get_hint_veryClose()
{
    return Roadster_veryClose.get_message();
}
