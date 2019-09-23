#include "Console.hpp"

c_Console* Console;

void c_Console::Start_Attaching()
{
	AllocConsole();
	freopen_s((FILE * *)stdin, "CONIN$", "r", stdin);
	freopen_s((FILE * *)stdout, "CONOUT$", "w", stdout);
}

void c_Console::Stop_Attaching()
{
	fclose((FILE*)stdin);
	fclose((FILE*)stdout);
	HWND Console_HWND = GetConsoleWindow();
	FreeConsole();
	PostMessageW(Console_HWND, WM_CLOSE, 0, 0);
}

void c_Console::Print_Log(std::string Text)
{
	cout << Text << "\n";
}

void c_Console::Log_Color(std::string Text, e_Colors Color)
{
	HANDLE h_Console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(h_Console, Color);
	cout << Text << "\n";
	SetConsoleTextAttribute(h_Console, 15);
}

void c_Console::Log_Color(const char Text, e_Colors Color)
{
	HANDLE h_Console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h_Console, Color);
	cout << Text << "\n";
	SetConsoleTextAttribute(h_Console, 15);
}