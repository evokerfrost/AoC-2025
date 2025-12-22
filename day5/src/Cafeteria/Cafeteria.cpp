#include "Cafeteria.h"
#include <iostream>
#include <string>
#include <vector>

Cafeteria::Cafeteria() {
    return;
}


/*
 * Solution for problem 1
 */
int Cafeteria::solve(std::vector<std::string>& ranges) {

    int sum = 0;

    int line;

    // Handle fresh ingredient ranges
    for (line = 0; ranges[line].compare("") != 0; line++) {

        auto dashpos=ranges[line].find_first_of('-');
        long p1 = std::stol(ranges[line].substr(0, dashpos));
        long p2 = std::stol(ranges[line].substr(dashpos+1));

        // First part of day3p1...
    }

    // Handle available ingredients
    for(line=line+1; line < ranges.size(); line++) {
        // Second part of day3p1...
    }
    
    return sum;
}


/*
 * Solution for problem 2
 */
long Cafeteria::solve2(std::vector<std::string>& ranges) {

    int sum = 0;

    return sum;
}