#pragma once
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;

enum e_Colors
{
	DarkBlue = 1,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkPink,
	DarkYellow,
	DarkWhite,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Pink,
	Yellow,
	White
};

class c_Console
{
public:
	void Start_Attaching();
	void Stop_Attaching();
	void Print_Log(std::string Text);
	void Log_Color(std::string Text, e_Colors Color);
	void Log_Color(const char Text, e_Colors Color);
}; extern c_Console* Console;