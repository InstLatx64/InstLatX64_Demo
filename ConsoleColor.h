// ConsoleColor.h
// Copyleft Vincent Godin
// https://www.codeproject.com/articles/16431/add-color-to-your-std-cout

#pragma once
#include <iostream>
#include <windows.h>

enum CharColor : WORD {
	                  //IRGB
	COLOR_BLACK		= 0b0000,
	COLOR_DARKBLUE	= 0b0001,
	COLOR_DARKGREEN	= 0b0010,
	COLOR_LIGHTBLUE	= 0b0011,
	COLOR_BRICK		= 0b0100,
	COLOR_VIOLET	= 0b0101,
	COLOR_GOLD		= 0b0110,
	COLOR_GREY		= 0b0111,
	COLOR_SILVER	= 0b1000,
	COLOR_BLUE		= 0b1001,
	COLOR_GREEN		= 0b1010,
	COLOR_AQUA		= 0b1011,
	COLOR_RED		= 0b1100,
	COLOR_PURPLE	= 0b1101,
	COLOR_YELLOW	= 0b1110,
	COLOR_WHITE		= 0b1111
};

inline std::ostream& blue(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& red(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& green(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& yellow(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& gold(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED);
	return s;
}

inline std::ostream& white(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

inline std::ostream& magenta(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

struct color {
	color(WORD attribute) :m_color(attribute) {};
	WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, const color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c.m_color);
	return i;
}

// Copyleft Vincent Godin

