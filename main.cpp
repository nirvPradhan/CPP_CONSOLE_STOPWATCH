// main.cpp : Defines the entry point for the application.

//

#pragma once

#include <iostream>
#include <fstream>		// file i/o NOT DONE YET
#include <windows.h>	// get keystates

#include "Stopwatch.h"

// HANDLE KEYBOARD INPUT

// main function
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	Stopwatch stopwatch(SECONDS);

	printf("\x1b[2J");
	for (;;) {
		// end program if user presses q.
		if(GetKeyState('Q') & 0x8000)
			break;

		// if the smallest period has elapsed print current time.q
		if (stopwatch.elapsed())
			printf("\x1b[2J");
			printf("\x1b[H");
			
			// Help messsage with controls
			std::cout << "Stopwatch Diary:\n\t\- Press Q to quit.\n" << std::endl;
			
			stopwatch.print();
	}

	std::cout << "End of File." << std::endl;
	return 0;
}
