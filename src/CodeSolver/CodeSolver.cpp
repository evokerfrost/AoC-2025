#include "CodeSolver.h"
#include <string>

CodeSolver::CodeSolver() {
    dial=0;
    code=0;
    return;
}


/*
 * Solution for problem 1
 */
int CodeSolver::solve(std::vector<std::string>& combination) {

    code = 0;
    dial = 50;

    for(std::basic_string<char> action : combination) {
        char direction = action[0];
        int turn = std::stoi(action.substr(1));

        // Set modifier to -1 if dial should turn left. Set to 1 otherwise.
        int modifier = direction == 'L' ? -1 : 1;

        dial = dialHandler((dial + (turn*modifier)));
        if (dial == 0) code++;
    }


    return code;
}


/*
 * Solution for problem 2
 */
int CodeSolver::solve2(std::vector<std::string>& combination) {

    code = 0;
    dial = 50;

    for(std::basic_string<char> action : combination) {
        char direction = action[0];
        int turn = std::stoi(action.substr(1));
        int modifier = direction == 'L' ? -1 : 1;
        int oldDial = dial;
        
        dial = (dial + (turn*modifier));
        modifier = dial < 0 ? -1 : 1;
        code = code + (((dial == 0 || modifier < 0) && oldDial != 0) ? 1 : 0) + (dial * modifier) / 100;
        dial = dialHandler(dial);
    }

    return code;
}


/*
 * Helper function
 */
int CodeSolver::dialHandler(int dialVal) {

    int intmod = dialVal % 100;

    return intmod < 0 ? 100 + intmod : intmod;
}