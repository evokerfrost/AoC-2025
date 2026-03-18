#ifndef LABORATORY_H
#define LABORATORY_H

#include <string>
#include <vector>

class Laboratory {
    public:
        Laboratory();

        // Solution to first problem
        long solve(std::vector<std::string>& rows);

        //Solution to second problem
        long solve2(std::vector<std::string>& rows);
    private:
        // Attributes
        std::vector<std::string> matrix;
        long sum;

        // Helper functions
        void progress(long row);
        long countTotal();
};

#endif