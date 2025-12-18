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

    long sum = 0;

    auto rangeStrings = idStringHandler(ranges);

    for (std::string s : rangeStrings) {
        auto dashpos=s.find_first_of('-');
        long p1 = std::stol(s.substr(0, dashpos));
        long p2 = std::stol(s.substr(dashpos+1));

        for (long i = p1; i <= p2; i++) {
            if(!isValid2(i)) {
                sum += i;
            }
        }
    }

    return sum;
}


/*
 * Handle the id string.
 */
std::vector<std::string> GiftShop::idStringHandler(std::string& ogString) {

    // Create a vector for storing all ranges entered in ogString
    auto retVector = std::vector<std::string>();
    
    // Get the first comma, and return a vector with the entire string if there are no commas
    std::size_t commaPos = ogString.find_first_of(',');
    if (commaPos == std::string::npos) {
        retVector.insert(retVector.end(), ogString);
        return retVector;
    }

    // Insert substring 0 until commaPos into the return vector
    retVector.insert(retVector.end(), ogString.substr(0, commaPos));

    // While commas are still found, keep looking for substrings of ogString
    while (commaPos != std::string::npos) {
        std::size_t oldPos = commaPos+1;
        commaPos=ogString.find_first_of(',', commaPos+1);

        // If there are no more commas, insert the rest of ogString in retVector. Otherwise, insert the relevant range (until next comma)
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

    // Only strings of even length can be incorrect
    if (idStr.length() % 2 != 0) return true;

    // Check if the first half of the string is equal to the second half
    auto mid = idStr.length()/2;
    return idStr.substr(0, mid).compare(idStr.substr(mid)) != 0;
}


/*
 * Check if id is valid for solution 2.
 */
bool GiftShop::isValid2(long id) {

    auto idStr = std::to_string(id);


    // Get the mid point
    auto mid = idStr.length()/2;


    // Check all possible repetitions of the string
    // Note that no repetitions can be found after the first half
    for (long rs = 1; rs <= mid; rs++) {

        bool valid=false;

        // Check if idStr could be made entirely of i-length repetitions (rs=repetition size)
        if (idStr.length() % rs != 0) continue;

        // Get the first repetition to find out what pattern we're looking for
        std::string pattern = idStr.substr(0, rs);
        for (long rn = 1; rn < idStr.length() / rs; rn++) {

            // Compare repetition number (rn) with pattern
            if (idStr.substr(rn*rs, rs).compare(pattern) != 0) {
                valid = true;
                break;
            }
        }

        // If a nonconforming repetition was found, keep looking with the next repetition size
        if(valid) continue;

        // Everything conforms to the repetition¸ return false
        return false;
    }

    // We didn't find anything incorrect. Return true
    return true;
}