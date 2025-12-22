#include "Cafeteria.h"
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
    rangeVector = std::vector<std::pair<long,long>>();

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

    long sum = 0;
    rangeVector = std::vector<std::pair<long,long>>();

    long line;

    // Handle fresh ingredient ranges
    for (line = 0; ranges[line].compare("") != 0; line++) {

        auto dashpos=ranges[line].find_first_of('-');
        long p1 = std::stol(ranges[line].substr(0, dashpos));
        long p2 = std::stol(ranges[line].substr(dashpos+1));

        rangeVector.insert(rangeVector.end(), {p1, p2});
    }

    combineRanges();
    sum = countRanges();

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


/*
 * Combines ranges in rangeVector.
 */
void Cafeteria::combineRanges() {
    
    int removalID;

    do {
        removalID = -1;
        for(long i = 0; i < rangeVector.size(); i++) {
            for(long j = i+1; j < rangeVector.size(); j++) {

                // End of j is in i
                if(rangeVector[i].first <= rangeVector[j].second && rangeVector[i].second >= rangeVector[j].second) {
                    removalID = j;

                    // Extend start of i to start of j if j is lower than i
                    if(rangeVector[i].first > rangeVector[j].first) rangeVector[i].first = rangeVector[j].first;
                }

                // Beginning of j is in i
                if(rangeVector[i].second >= rangeVector[j].first && rangeVector[i].first <= rangeVector[j].first) {
                    removalID = j;

                    // Extend end of i to end of j if j is higher than i
                    if(rangeVector[i].second < rangeVector[j].second) rangeVector[i].second = rangeVector[j].second;
                }

                // Entirety of j is in i
                if(rangeVector[i].first <= rangeVector[j].first && rangeVector[i].second >= rangeVector[j].second) {
                    removalID = j;
                }

                // Entirety of i is in j
                if(rangeVector[j].first <= rangeVector[i].first && rangeVector[j].second >= rangeVector[i].second) {
                    removalID = i;
                }

                // Vector needs to change...
                if(removalID >= 0) break;
            }

            // Vector needs to change...
            if(removalID >= 0) break;
        }

        // Remove the range that needs to change.
        if(removalID >= 0) rangeVector.erase(std::next(rangeVector.begin(), removalID));
    }while(removalID >= 0);
}


/*
 * Count all ranges in rangeVector
 */
long Cafeteria::countRanges() {

    long sum = 0;

    for(auto& pair : rangeVector) {
        
        sum += (pair.second-pair.first)+1;
    }

    return sum;
}