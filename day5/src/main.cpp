#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "Cafeteria/Cafeteria.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    Cafeteria c = Cafeteria();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    int result = c.solve(fileOutput);
    long result2 = c.solve2(fileOutput);

    std::cout << "Result 1: " << std::to_string(result) << std::endl;
    std::cout << "Result 2: " << std::to_string(result2) << std::endl;

    return 0;
}