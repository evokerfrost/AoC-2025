#ifndef TRASHCOMPACTOR_H
#define TRASHCOMPACTOR_H

#include <string>
#include <vector>

class TrashCompactor {
    public:
        TrashCompactor();

        // Solution to first problem
        long solve(std::vector<std::string>& rows);

        //Solution to second problem
        long solve2(std::vector<std::string>& rows);
    private:
        typedef long (*Calculation)(long x, long y);

        // Helper functions
        std::vector<std::vector<std::string>> mathMatrix;
        void populateMathMatrix(std::vector<std::string>& rows);
        void populateMathMatrix2(std::vector<std::string>& rows);
        long positiveMin(long a, long b);
        std::vector<std::string> mathStringHandler(std::string& ogString);
        void printMathMatrix();
};

#endif