#ifndef TRASHCOMPACTOR_H
#define TRASHCOMPACTOR_H

#include <string>
#include <vector>

class TrashCompactor {
    public:
        TrashCompactor();

        // Solution to first problem
        int solve(std::vector<std::string>& ranges);

        //Solution to second problem
        long solve2(std::vector<std::string>& ranges);
    private:
};

#endif