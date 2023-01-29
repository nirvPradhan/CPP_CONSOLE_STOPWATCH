#pragma once
#include <fstream>
#include <string>
#include <iostream>

// Manages input and output to file
class FileIO {
private:
	std::fstream f_stream;
public:
	FileIO();

	~FileIO();

	void Write(std::string write);
};

