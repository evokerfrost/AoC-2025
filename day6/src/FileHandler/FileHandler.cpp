#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

FileHandler::FileHandler() {
    return;
}


/*
 * Read a file, and return a vector with all strings in the file
 */
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


/*
 * Split a string on dividers, and return a vector with the separated strings
 */
std::vector<std::string> FileHandler::splitString(std::string& str, char divider) {

    // Create a vector for storing all ranges entered in str
    auto ret = std::vector<std::string>();
    
    // Get the first divider, and return a vector with the entire string if there are no dividers
    std::size_t divPos = str.find_first_of(divider);
    if (divPos == std::string::npos) {
        ret.insert(ret.end(), str);
        return ret;
    }

    // Insert substring 0..divider into the return vector
    ret.insert(ret.end(), str.substr(0, divPos));

    // While dividers are still found, keep looking for substrings of str
    while (divPos != std::string::npos) {
        std::size_t oldPos = divPos+1;
        divPos=str.find_first_of(divider, divPos+1);

        // If there are no more commas, insert the rest of str in ret. Otherwise, insert the relevant range (until next divider)
        if (divPos == std::string::npos) ret.insert(ret.end(), str.substr(oldPos));
        else ret.insert(ret.end(), str.substr(oldPos, divPos-oldPos));
        
    }
    
    return ret;
}