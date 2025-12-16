#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
class FileHandler {
    public:
        FileHandler();
        std::vector<std::string> readFile(const std::string& fileName);
    private:
};

#endif
