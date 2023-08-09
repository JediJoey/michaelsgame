#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <iostream>
#include "game_data.h"
#include <iomanip>
#include <cmath>
#include "game_object.h"



//              display Class
//            What it is used for:
//
//  (1) This will be the last Class that I implement.
//      Any functions that have to do with printing to the console
//      will be modified to a display class object, and placed into this class



class Display
{
private:
    std::string message;

public:

    /* - Constructor - */
    Display(std::string message);


    /* - Main Functions - */
    void setDisplayBox(char display_box[][61]);
    void message_to_display_box(char display_box[15][61]);
    std::string spaces_to_end_of_line(std::string message);
    std::string get_hint_far();
    std::string get_hint_notsoFar();
    std::string get_hint_close();
    std::string get_hint_veryClose();


    /* - Display Functions - */
    void display_titleScreen();
    void display_DisplayBox(char display_box[][61]);
    void display_Controls(char display_box[][61]);
    void display_Info(char display_box[][61]);
    void display_FoundYugo(char display_box[][61]);
    void display_FoundPinto(char display_box[][61]);
    void display_FoundRoadster(char display_box[][61]);
    void display_caught_by_Elon_1(char display_box[][61]);
    void display_caught_by_Elon_2(char display_box[][61]);
    void display_endScreen();
    void display_stats(char display_box[][61]);
    void display_Elon_awake(char display_box[][61]);


    /* - Set Functions - */
    void set_message(std::string message);


    /* - Get Functions - */
    std::string get_message();

};

#endif // DISPLAY_H
