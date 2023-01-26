#pragma once
#include <chrono>
#include <list>

// Defines different period types and their values
#define HOURS			3
#define MINUTES			2
#define SECONDS			1
#define MILLISECONDS	0

/*
	Stopwatch 
*/
struct Stopwatch {
	std::chrono::steady_clock::time_point start; // start start of the stopwatch.
	std::chrono::steady_clock::time_point period_start; // starts a period.
	std::chrono::milliseconds period; // p is the smalles period in ms before print.

	Stopwatch(int p = 0)
		:start(std::chrono::steady_clock::now())
	{
		switch (p) {
			case HOURS:
				period = std::chrono::duration(std::chrono::hours(1));
				break;
			case MINUTES:
				period = std::chrono::duration(std::chrono::minutes(1));
				break;
			case SECONDS:
				period = std::chrono::duration(std::chrono::seconds(1));
				break;
			case MILLISECONDS:
				period = std::chrono::duration(std::chrono::milliseconds(1));
				break;
			default:
				std::cerr << "STOPWATCH ERROR: period defined DNE using default MILLISECONDS" << std::endl;
				period = std::chrono::duration(std::chrono::milliseconds(1));
				break;
		}
	}

	// checks if the period has elapsed
	bool elapsed() {
		if (std::chrono::steady_clock::now() - period_start > period) {
			period_start = std::chrono::steady_clock::now();
			return true;
		}
		return false;
	}


	// print the time in format : elapsed <..min(s):..sec(s):..ms>
	void print()
	{
		//TODO: print only periods that matter ones bigger than given period.

		// have to subtract larger time from total.
		auto elapsed = std::chrono::steady_clock::now() - start;
		auto hours = std::chrono::floor<std::chrono::hours>(elapsed);
		auto minutes = std::chrono::floor<std::chrono::minutes>(elapsed-hours);
		auto seconds = std::chrono::floor<std::chrono::seconds>(elapsed-hours-minutes);
		auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed-hours-minutes-seconds);

		std::cout << "elapsed <"
					<< minutes.count() <<"min(s):" 
					<< seconds.count() <<":sec(s)"
					<< milliseconds.count() <<"ms>"
					<< std::endl;
	}
};
