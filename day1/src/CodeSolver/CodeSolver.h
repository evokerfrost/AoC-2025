#ifndef CODESOLVER_H
#define CODESOLVER_H

#include <string>
#include <vector>
class CodeSolver {
    public:
        CodeSolver();
        int solve(std::vector<std::string>& combination);
        int solve2(std::vector<std::string>& combination);
    private:
        int dial;
        int code;
        int dialHandler(int dialVal);
};

#endif