#ifndef GAME_DATA_H
#define GAME_DATA_H
#include <string>
#include <vector>
#include <iostream>


//              * This is the class that I am currently working on *


//              game_data Class
//            What it is used for:
//
//  (2) Creates a game_data object for a kind of data that will be tracked
//      - uses the struct "dataStruct" to store a piece of data's name and value into 1 value of the game_data object's vector
//      - i.e. game_data Turn(turnVector,
//  (3)



struct dataPoint {
    std::string DP_name;
    int DP_value;
};



class game_data
{

private:
        std::vector <dataPoint> vector_of_DP; //vector 'Data' contains int data and string name (i.e. vector <game_data> Turns (2) = (turn_0, 0) (turn_1,1);

public:
        /* - Constructors - */
    game_data();
    game_data(std::string first_DP_name, int first_DP_value);


    /* - Main Functions - */
    void add_DP (std::string newDP_name, int newDP_value);
    void increment_DP(std::string function);

    /* - Main Functions (callable by other classes) - */
    void increment_Turn();
    void increment_found_Pinto();
    void increment_found_Yugo();
    void increment_found_Roadster();
    void increment_found_car(char symbol);
    void display_Turn();
    void reset_Turns(game_data Turns);
    void reset_data();
    void reset_caught_by_Elon();
    std::string return_Turn();
    std::string return_Pinto();
    std::string return_Yugo();
    std::string return_Roadster();

    void increment_caught_by_Elon();
    bool check_Elon_caught_once();
    bool check_Elon_caught_twice();
    void display_caught_by_Elon_times();
    std::string return_caught_by_Elon_times();
    std::string return_total_caught_by_Elon_times();

    /* - Print Functions - */
    void print_all_DP();
    void print_last_DP();
    void print_last_DP_name();
    void print_last_DP_value();

    /* - Get Functions - */
    std::string get_last_DP_name(); //gets last datapoint name of a data vector
    int get_last_DP_value(); //gets last datapoint val of a data vector
    int get_Turn();


    /* - Set Functions - */


};



#endif // GAME_DATA_H
