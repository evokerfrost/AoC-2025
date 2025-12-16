#include <iostream>
#include <string>
#include <vector>
#include "FileHandler/FileHandler.h"
#include "CodeSolver/CodeSolver.h"

int main(int argc, const char* argv[]) {

    // Not enough arguments
    if (argc < 2) {
        return 1;
    }

    FileHandler fh = FileHandler();
    CodeSolver cs = CodeSolver();
    
    std::vector<std::string> fileOutput = fh.readFile(argv[1]);
    
    int result = cs.solve2(fileOutput);

    std::cout << "Result: " << std::to_string(result) << std::endl;

    return 0;
}