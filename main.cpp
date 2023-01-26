// main.cpp : Defines the entry point for the application.

//

#pragma once

#include <iostream>
#include <fstream>		// file i/o NOT DONE YET
#include <windows.h>	// get keystates

#include "Stopwatch.h"

int main()
{
	Stopwatch stopwatch(SECONDS + 12);
	for (;;) {
		// end program if user presses q.
		if(GetKeyState('Q') & 0x8000)
			break;

		// if the smallest period has elapsed print current time.
		if (stopwatch.elapsed())
			stopwatch.print();
	}

	std::cout << "End of File." << std::endl;
	return 0;
}
