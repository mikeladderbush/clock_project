#include <iostream>
#include <string>
#include <vector>
#include "ClockFunctions.cpp"

using namespace std;

int main()
{

    // sets the variables for input.

    int hours;
    int minutes;
    int seconds;
    char separator1;
    char separator2;
    string day_or_night;

    cout << "Please enter your time in HH:MM:SS format and press enter." << endl;

    // the input takes our time values and separates them by the empty two separators;

    cin >> hours >> separator1 >> minutes >> separator2 >> seconds;
    cout << "Please specify AM or PM if in 12 hour format. If you'd like, enter 0 if you are using 24 hour format. Defaults to 12 hour AM if left unspecified." << endl;
    cin >> day_or_night;

    CheckTime(hours, minutes, seconds, day_or_night);

    // before our inputs are put into the display loop they are checked for what time of day they are set in.

    if (day_or_night == "0" && hours > 12)
    {
        hours = hours - 12;
        day_or_night = "PM";
    }
    else
    {
        day_or_night = "AM";
    }

    // The values are then put into the following functions in order to be formatted and then manipulated later.

    Formatter(hours, minutes, seconds, day_or_night);
    DisplayLoop(hours, minutes, seconds, day_or_night);

    return 0;
}