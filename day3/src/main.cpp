#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "BatteryBank/BatteryBank.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    BatteryBank bb = BatteryBank();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    int result = bb.solve(fileOutput);
    long result2 = bb.solve2(fileOutput);

    std::cout << "Result 1: " << std::to_string(result) << std::endl;
    std::cout << "Result 2: " << std::to_string(result2) << std::endl;

    // 776380 is too low

    return 0;
}