#include "game_data.h"

using namespace std;


 /* - Constructors - */
game_data::game_data()
{

}
game_data::game_data(string first_DP_name, int first_DP_value)
{
    dataPoint DP;
    DP.DP_name = first_DP_name;
    DP.DP_value = first_DP_value;
    vector_of_DP.push_back(DP);
}



/* - Game Data (definitions) - */
game_data Turns("Turn: 1", 1); // defines game_data object for Turns
game_data caught_by_Elon("Times Elon caught you: 0", 0);
game_data total_caught_by_Elon("Total Times Elon caught you: 0", 0);
game_data found_yugo("Total Times you saw the Yugo: 0", 0);
game_data found_pinto("Total Times you saw the Pinto: 0", 0);
game_data found_Roadster("Total Roadster Wins: 0", 0);



/* - Main Functions - */
void game_data::add_DP (string newDP_name, int newDP_value)
{
    dataPoint DP;
    DP.DP_name = newDP_name;
    DP.DP_value = newDP_value;
    vector_of_DP.push_back(DP);
}

void game_data::print_last_DP()
{
    cout << "Last data point name: " << this->get_last_DP_name() << endl;
    cout << "Last data point value: " << this->get_last_DP_value() << endl;

}

void game_data::print_last_DP_name()
{
    cout << this->get_last_DP_name() << endl;
}

void game_data::print_last_DP_value()
{
    cout << this->get_last_DP_value() << endl;
}

void game_data::increment_DP(string function)
{
    const int current_turn_value = vector_of_DP.back().DP_value + 1;
    dataPoint next_turn;
    next_turn.DP_name = function + ": " + to_string(current_turn_value);
    next_turn.DP_value = current_turn_value;
    vector_of_DP.push_back(next_turn);
}

void game_data::reset_data()
{
    this->vector_of_DP.resize(1);
}


/* - Main Functions (callable by other classes) - */
void increment_Turn()
{
    Turns.increment_DP("Turn");
}

void increment_found_Yugo()
{
    found_yugo.increment_DP("Times you saw the Yugo");
}

void increment_found_Pinto()
{
    found_pinto.increment_DP("Times you saw the Pinto");
}

void increment_found_Roadster()
{
    found_Roadster.increment_DP("Total Roadster Wins");
}

void increment_found_car(char symbol)
{
    if(symbol == 'P')
    {
        increment_found_Pinto();
    }
    else if(symbol == 'Y')
    {
        increment_found_Yugo();
    }
}

void reset_Turns()
{
    Turns.reset_data();
}

void reset_caught_by_Elon()
{
    caught_by_Elon.reset_data();
}

void display_Turn()
{
    Turns.print_last_DP_name();
}

string return_Turn()
{
    return(Turns.get_last_DP_name());
}

string return_Pinto()
{
    return(found_pinto.get_last_DP_name());
}

string return_Yugo()
{
    return(found_yugo.get_last_DP_name());
}

string return_Roadster()
{
    return(found_Roadster.get_last_DP_name());
}

void increment_caught_by_Elon()
{
    caught_by_Elon.increment_DP("Times Elon caught you");
    total_caught_by_Elon.increment_DP("Total Times Elon caught you");
}

bool check_Elon_caught_twice()
{
    int caught_times = caught_by_Elon.get_last_DP_value();

    if(caught_times == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check_Elon_caught_once()
{
    int caught_times = caught_by_Elon.get_last_DP_value();

    if(caught_times == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display_caught_by_Elon_times()
{
    caught_by_Elon.print_last_DP_name();
}

string return_caught_by_Elon_times()
{
    return(caught_by_Elon.get_last_DP_name());
}

string return_total_caught_by_Elon_times()
{
    return(total_caught_by_Elon.get_last_DP_name());
}




/* - Get Functions - */
string game_data::get_last_DP_name() //gets last datapoint of a data vector
{
    int last_DP_position = vector_of_DP.size() - 1;
    string last_DP_name = vector_of_DP[last_DP_position].DP_name;
    return last_DP_name;

}

int game_data::get_last_DP_value()
{
    int last_DP_position = vector_of_DP.size() - 1;
    int last_DP_val = vector_of_DP[last_DP_position].DP_value;
    return last_DP_val;
}

int get_Turn()
{
    return Turns.get_last_DP_value();
}

 /* - Set Functions - */
