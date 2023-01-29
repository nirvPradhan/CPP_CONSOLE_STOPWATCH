#include "FileIO.h"

FileIO::FileIO()
{
	std::cout << "YELLOW" << std::endl;

	f_stream.open("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (f_stream.fail()) {
		std::cout << "couldnt open file." << std::endl;
		return;
	}

	f_stream << " more lorem ipsum";
};

FileIO::~FileIO()
{
	f_stream.close();
}

void FileIO::Write(std::string write) {

	f_stream << write.c_str();
}
