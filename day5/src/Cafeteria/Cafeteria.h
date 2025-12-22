#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <string>
#include <vector>

class Cafeteria {
    public:
        Cafeteria();

        // Solution to first problem
        int solve(std::vector<std::string>& paper);

        //Solution to second problem
        long solve2(std::vector<std::string>& paper);
    private:
};

#endif