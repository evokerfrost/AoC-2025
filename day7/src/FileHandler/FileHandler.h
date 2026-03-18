#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
class FileHandler {
    public:
        FileHandler();
        std::vector<std::string> readFile(const std::string& fileName);
        std::vector<std::string> splitString(std::string& str, char divider);
    private:
};

#endif
