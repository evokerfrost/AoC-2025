#include "Cafeteria.h"
#include <iostream>
#include <string>
#include <vector>

Cafeteria::Cafeteria() {
    rangeVector = std::vector<std::pair<long,long>>();
    return;
}


/*
 * Solution for problem 1
 */
int Cafeteria::solve(std::vector<std::string>& ranges) {

    int sum = 0;

    long line;

    // Handle fresh ingredient ranges
    for (line = 0; ranges[line].compare("") != 0; line++) {

        auto dashpos=ranges[line].find_first_of('-');
        long p1 = std::stol(ranges[line].substr(0, dashpos));
        long p2 = std::stol(ranges[line].substr(dashpos+1));

        rangeVector.insert(rangeVector.end(), {p1, p2});
    }

    // Handle available ingredients
    for(line=line+1; line < ranges.size(); line++) {
        long id = std::stol(ranges[line]);
        sum += inRange(id) ? 1 : 0;
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


/*
 * Returns if a number is in range of some range in rangeVector
 */
bool Cafeteria::inRange(long num) {
    for(std::pair<long,long> p : rangeVector) {
        if(num >= p.first && num <= p.second) {
            return true;
        }
    }

    return false;
}