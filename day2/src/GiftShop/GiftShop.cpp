#include "GiftShop.h"
#include <cstddef>
#include <string>
#include <vector>

GiftShop::GiftShop() {
    return;
}


/*
 * Solution for problem 1
 */
long GiftShop::solve(std::string& ranges) {

    long sum = 0;

    auto rangeStrings = idStringHandler(ranges);

    for (std::string s : rangeStrings) {
        auto dashpos=s.find_first_of('-');
        long p1 = std::stol(s.substr(0, dashpos));
        long p2 = std::stol(s.substr(dashpos+1));

        for (long i = p1; i <= p2; i++) {
            if(!isValid(i)) {
                sum += i;
            }
        }
    }

    return sum;
}


/*
 * Solution for problem 2
 */
long GiftShop::solve2(std::string& ranges) {

    return 0;
}


/*
 * Handle the id string.
 */
std::vector<std::string> GiftShop::idStringHandler(std::string& ogString) {

    
    auto retVector = std::vector<std::string>();
    
    std::size_t commaPos = ogString.find_first_of(',');

    if (commaPos == std::string::npos) {
        retVector.insert(retVector.end(), ogString);
        return retVector;
    }

    retVector.insert(retVector.end(), ogString.substr(0, commaPos));

    while (commaPos != std::string::npos) {
        std::size_t oldPos = commaPos+1;
        commaPos=ogString.find_first_of(',', commaPos+1);

        if (commaPos == std::string::npos) retVector.insert(retVector.end(), ogString.substr(oldPos));
        else retVector.insert(retVector.end(), ogString.substr(oldPos, commaPos-oldPos));
        
    }
    
    return retVector;
}

/*
 * Check if id is valid for solution 1.
 */
bool GiftShop::isValid(long id) {
    auto idStr = std::to_string(id);
    if (idStr.length() % 2 != 0) return true;

    auto mid = idStr.length()/2;
    
    return idStr.substr(    0, mid).compare(idStr.substr(mid)) != 0;
}