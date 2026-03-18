#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "Laboratory/Laboratory.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    Laboratory l = Laboratory();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    long result = l.solve(fileOutput);
    long result2 = l.solve2(fileOutput);

    std::cout << "Result 1: " << std::to_string(result) << std::endl;

    std::cout << "Result 2: " << std::to_string(result2) << std::endl;

    return 0;
}
