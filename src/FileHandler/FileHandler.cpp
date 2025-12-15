#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

FileHandler::FileHandler() {
    return;
}

std::vector<std::string> FileHandler::readFile(const std::string& fileName) {
    auto retArr = std::vector<std::string>();

    std::ifstream filestream(fileName);
    std::string line;

    if (!filestream.is_open() || !filestream.good()) {
        std::cerr << "Error: File could not be opened, " << fileName << std::endl;
        exit(1);

    }

    while (std::getline(filestream, line)) {
        retArr.insert(retArr.end(), line);
    }

    filestream.close();

    return retArr;
}