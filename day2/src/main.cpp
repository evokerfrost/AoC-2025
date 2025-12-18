#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "GiftShop/GiftShop.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    GiftShop gs = GiftShop();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    long result = gs.solve(fileOutput[0]);
    //long result2 = gs.solve2(fileOutput[0]);

    std::cout << "Result 1: " << std::to_string(result) << std::endl;
    //std::cout << "Result 2: " << std::to_string(result2) << std::endl;

    return 0;
}