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
int GiftShop::solve(std::string& ranges) {

    int sum = 0;

    // Solve problem here.
    auto temp = idStringHandler(ranges);

    return sum;
}


/*
 * Solution for problem 2
 */
int GiftShop::solve2(std::string& ranges) {

    return 0;
}


/*
 * Helper function
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

bool GiftShop::isValid(int id) {
    auto idStr = std::to_string(id);
    if (idStr.length() % 2 != 0) return true;

    auto mid = idStr.length()/2;
    
    return idStr.substr(0, mid).compare(idStr.substr(mid)) != 0;
}