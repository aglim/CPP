// https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text
//color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236
// a Dev-C++ tested console application by vegaseat 07nov2004

#include <iostream>
#include <windows.h> // WinApi header

using namespace std; // std::cout, std::cin

void main()
{
	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool line = false;
	bool column = false;
	// you can loop k higher to see more color choices
	for (int i = 0; i < 8; i++) {
		column ? line = true: line = false;
		
		for (int k = 0; k < 8; k++)
		{
			// pick the colorattribute k you want
			SetConsoleTextAttribute(hConsole, line * (16*4));
			cout << " ";
			line = !line;
		}
		column = !column;
		cout << endl;
	}
	system("pause");	
}