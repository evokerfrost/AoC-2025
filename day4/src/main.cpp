#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "PrintingDepartment/PrintingDepartment.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    PrintingDepartment pd = PrintingDepartment();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    int result = pd.solve(fileOutput);
    long result2 = pd.solve2(fileOutput);

    std::cout << "Result 1: " << std::to_string(result) << std::endl;
    std::cout << "Result 2: " << std::to_string(result2) << std::endl;

    return 0;
}