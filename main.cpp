#include <iostream>
#include "GameSource.cpp"
using namespace std;

/*  Game: Tesla
 *  Authors: Maxwell Scholtes and Michael Wauligman
 *
 *                ~ Current Progress ~
 *
 *  Game Objects:
 *      - The game grid                         DONE
 *      - The game space                        DONE
 *      - Elon, his cars, and the user          DONE
 *      - Object collision and conditions       DONE
 *      - Elon waking up/ moving                DONE
 *
 *
 *  Game Controls:
 *      - The Game's movement controls          DONE
 *      - The Game's menu controls              DONE
 *
 *  Game Data:
 *      - Turns                                 DONE
 *      - Cars found                            DONE
 *      - High Scores                           DONE
 *      - Starman                               DONE
 *
 *  Display:
 *      - Hints                                 ****
 *      - Turns                                 DONE
 *      - Grid/Game                             DONE
 *      - Hiding/ showing cars/Elon             DONE
 *      - Elon has awoken                       DONE
*/

int main()
{
    srand(time(0)); // start randtime so that random functions can be used
    Game(); // Call the "GameLoop" function from GameSource.cpp to play the game
}
