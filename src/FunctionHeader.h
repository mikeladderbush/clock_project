#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Our function declarators.
void CheckTime(int hours, int minutes, int seconds, string day_or_night);
void AddZero(int unit);
void InputToTwentyFour(int hours, int minutes, int seconds, string day_or_night);
void AddToTime(int &hours, int &minutes, int &seconds, int unit);
void Formatter(int hours, int minutes, int seconds, string day_or_night);
void DisplayLoop(int hours, int minutes, int seconds, string day_or_night);
