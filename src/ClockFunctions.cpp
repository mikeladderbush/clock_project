#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Makes sure our time makes sense in either format.
void CheckTime(int hours, int minutes, int seconds, string day_or_night)
{

    if (hours > 24)
    {

        cout << "Please retry with a valid time";
        exit(EXIT_SUCCESS);
    }

    if (minutes > 60)
    {

        cout << "Please retry with a valid time";
        exit(EXIT_SUCCESS);
    }

    if (seconds > 60)
    {

        cout << "Please retry with a valid time";
        exit(EXIT_SUCCESS);
    }

    if (day_or_night == "AM" || day_or_night == "PM" || day_or_night == "0")
    {
    }
    else
    {
        cout << "Please retry with a valid time";
        exit(EXIT_SUCCESS);
    }
}

// Adds leading zeros when values are too small to have two digits.
void AddZero(int unit)
{

    if (unit >= 1 && unit < 10)
    {
        cout << "0" << unit;
    }
    else if (unit == 0)
    {
        cout << "00";
    }
    else
    {
        cout << unit;
    }
}

// Changes our given 12 hour format time into twenty four hour format.
void InputToTwentyFour(int hours, int minutes, int seconds, string day_or_night)
{

    if (day_or_night == "PM")
    {

        hours = hours + 12;
        AddZero(hours);
        cout << ":";
        AddZero(minutes);
        cout << ":";
        AddZero(seconds);
    }
    else if (day_or_night == "AM")
    {

        AddZero(hours);
        cout << ":";
        AddZero(minutes);
        cout << ":";
        AddZero(seconds);
    }
    else
    {

        cout << "please enter a valid time of day (AM or PM)" << endl;
    }
}

// This function takes in an integer that specifies which referenced variable to edit and edits it by adding 1 and correcting for overflowing time values.
// It also exits the program if the input "4" is given.
void AddToTime(int &hours, int &minutes, int &seconds, int unit)
{

    if (unit == 1)
    {
        hours = hours + 1;
    }
    else if (unit == 2)
    {
        minutes = minutes + 1;
        if (minutes >= 60)
        {
            hours = hours + 1;
            minutes = 0;
        }
    }
    else if (unit == 3)
    {
        seconds = seconds + 1;
        if (seconds >= 60)
        {
            minutes = minutes + 1;
            seconds = 0;
            if (minutes >= 60)
            {
                hours = hours + 1;
            }
        }
    }
    else if (unit == 4)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        cout << "Please enter a valid command" << endl;
    }
}

// Simple formatting function that takes our inputs, passes them to other functions for editing and then outputs them in proper format.
void Formatter(int hours, int minutes, int seconds, string day_or_night = " ")
{

    cout << "********************      ********************" << endl;
    cout << "*  12-Clock Hour   *      *   24-Clock Hour  *" << endl;
    cout << "*    ";
    AddZero(hours);
    cout << ":";
    AddZero(minutes);
    cout << ":";
    AddZero(seconds);
    cout << " " << day_or_night;
    cout << "   *      ";
    cout << "*     ";
    InputToTwentyFour(hours, minutes, seconds, day_or_night);
    cout << "     *" << endl;
    cout << "********************      ********************" << endl;
}

// Our display loop. Allows for the program to keep running until the user specifies to quit. Takes values given from input in main.
void DisplayLoop(int hours, int minutes, int seconds, string day_or_night)
{

    while (true)
    {

        if (hours >= 12)
        {
            hours = hours - 12;
            if (day_or_night == "AM")
            {
                day_or_night = "PM";
            }
            else
            {
                day_or_night = "AM";
            }
        }
        cout << "*********************" << endl;
        cout << "*1-Add One Hour     *" << endl;
        cout << "*2-Add One Minute   *" << endl;
        cout << "*3-Add One Second   *" << endl;
        cout << "*4-Exit Program     *" << endl;
        cout << "*********************" << endl;

        int a;
        cin >> a;

        AddToTime(hours, minutes, seconds, a);
        Formatter(hours, minutes, seconds, day_or_night);
    }
}
