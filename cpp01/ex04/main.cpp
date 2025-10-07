#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

	// validate input
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <old_text> <new_text>" << std::endl;
        return 1;
    }

	// assign inputs
    std::string filename = argv[1];
    std::string old_text = argv[2];
    std::string new_text = argv[3];

    if (old_text.empty()) {
        std::cerr << "Error: old_text cannot be empty." << std::endl;
        return 1;
    }

	// open file
	// .c_str() is needed to conform to the 98 standard
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: cannot open input file." << std::endl;
        return 1;
    }

	// read whole file content line by line
    std::string content, line;
    while (std::getline(infile, line)) 
	{
        content += line;
        if (!infile.eof())
            content += '\n';
    }
    infile.close();

	// do the replacement
    std::string result;
    size_t pos = 0;
	size_t found;
    while ((found = content.find(old_text, pos)) != std::string::npos) 
	{
        result += content.substr(pos, found - pos);
        result += new_text;
        pos = found + old_text.length();
    }
    result += content.substr(pos);

	// create new file
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error: cannot create output file." << std::endl;
        return 1;
    }

    outfile << result;
    outfile.close();

    return 0;
}
