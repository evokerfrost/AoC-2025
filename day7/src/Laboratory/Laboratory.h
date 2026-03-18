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

        // Helper functions
        std::vector<std::vector<std::string>> mathMatrix;
        void populateMathMatrix(std::vector<std::string>& rows);
        void populateMathMatrix2(std::vector<std::string>& rows);
        long positiveMin(long a, long b);
        std::vector<std::string> mathStringHandler(std::string& ogString);
        void printMathMatrix();
};

#endif