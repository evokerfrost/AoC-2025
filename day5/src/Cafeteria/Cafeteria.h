#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <string>
#include <vector>

class Cafeteria {
    public:
        Cafeteria();

        // Solution to first problem
        int solve(std::vector<std::string>& ranges);

        //Solution to second problem
        long solve2(std::vector<std::string>& ranges);
    private:
        std::vector<std::pair<long, long>> rangeVector;
        bool inRange(long num) ;
};

#endif