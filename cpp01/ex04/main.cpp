#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

	// validate inputs
	if (argc != 4) {
		std::cerr << "Usage: ./replace <filename> <old_text> <new_text>" << std::endl;
		return 1;
	}

	// assign inputs
	std::string filename = argv[1];
	std::string old_text = argv[2];
	std::string new_text = argv[3];

	// check if old file is empty
	if (old_text.empty()) {
		std::cerr << "Error: old_text cannot be empty." << std::endl;
		return 1;
	}

	// open file
	// .c_str() is needed to conform to the ctd-98 standard
	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error: cannot open input file." << std::endl;
		return 1;
	}

	// std::getline(infile, line) - to read whole file content line by line
	std::string content;
	std::string line;
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';
	}
	// In C++, file streams like std::ifstream and std::ofstream follow
	// RAII — Resource Acquisition Is Initialization.
	// You don’t have to close it manually — but it’s sometimes good practice.
	infile.close();

	// Do the replacement
	std::string result;
	size_t pos = 0;
	size_t found;
	// std::string::npos is a special constant in C++ that represents “no position” — basically meaning “not found”.
	while ((found = content.find(old_text, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += new_text;
		pos = found + old_text.length();
	}
	result += content.substr(pos);

	// create new file
	std::string new_filename = filename + ".replace";
	std::ofstream outfile(new_filename.c_str());
	if (!outfile) {
		std::cerr << "Error: cannot create output file." << std::endl;
		return 1;
	}

	// output the result to the outfile & close it
	outfile << result;
	outfile.close();

	return 0;
}
