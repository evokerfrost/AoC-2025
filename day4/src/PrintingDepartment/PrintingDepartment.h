#ifndef PRINTINGDEPARTMENT_H
#define PRINTINGDEPARTMENT_H

#include <string>
#include <vector>

class PrintingDepartment {
    public:
        PrintingDepartment();

        // Solution to first problem
        int solve(std::vector<std::string>& paper);

        //Solution to second problem
        long solve2(std::vector<std::string>& paper);
    private:
        // Helper functions
        std::vector<std::vector<bool>> getMatrix(std::vector<std::string>& input);
        void printMatrix(std::vector<std::vector<bool>> matrix);
};

#endif