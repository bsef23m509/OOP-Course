#include<windows.h>

void setCursorAt(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// https://learn.microsoft.com/en-us/windows/console/readconsoleoutputcharacter
char readFrom(int x, int y)
{
	DWORD nLength = 1;
	char* str = new char[nLength * sizeof(TCHAR)];
	COORD readCoord;
	readCoord.X = x; readCoord.Y = y;
	DWORD num_read=0;
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)str, nLength, readCoord,(LPDWORD)&num_read);
	return *str;
}
//

enum ConsoleColor
{
	black=0,
	dark_blue=1,
	dark_green=2,
	dark_aqua,dark_cyan=3,
	dark_red=4,
	dark_purple=5,dark_pink=5,dark_magenta=5,
	dark_yellow=6,
	dark_white=7,
	gray=8,
	blue=9,
	green=10,
	aqua=11,cyan=11,
	red=12,
	purple=13,pink=13,magenta=13,
	yellow=14,
	white=15
};


void SetColor(int textcol,int backcol)
{
	bool textcolorprotect=true; //for future use
	/*doesn't let textcolor be the same as backgroung color if true*/
	if(textcolorprotect)
	{
		if((textcol%16)==(backcol%16))textcol++;
	}
	textcol%=16;
	backcol%=16;
	unsigned short wAttributes= (unsigned)textcol|((unsigned)backcol<<4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}

void SetColor(ConsoleColor textcol,ConsoleColor backcol)
{
	SetColor(int(textcol),int(backcol));
}
