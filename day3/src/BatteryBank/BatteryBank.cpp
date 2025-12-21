#include "BatteryBank.h"
#include <string>
#include <vector>

BatteryBank::BatteryBank() {
    return;
}


/*
 * Solution for problem 1
 */
int BatteryBank::solve(std::vector<std::string>& banks) {

    int sum = 0;

    for(std::string& bank : banks) {
        sum += findLargestJoltage(bank);
    }

    return sum;
}


/*
 * Solution for problem 2
 */
int BatteryBank::solve2(std::vector<std::string>& banks) {

    return -1;
}


/*
 * Find the largest Joltage possible in string.
 */
int BatteryBank::findLargestJoltage(std::string& bankString) {
    
    // {index, value]
    int largest = 0;
    int largestFollowing = -1;
    int secondLargest = 0;

    for(int i = 0; i < bankString.length(); i++) {

        if(bankString[i]-'0' > largestFollowing) largestFollowing = bankString[i]-'0';

        if(bankString[i]-'0' > largest) {
            secondLargest = largest;
            largest = bankString[i]-'0';
            largestFollowing = -1;
        }
    }

    return largestFollowing == -1 ? (secondLargest*10 + largest) : (largest*10 + largestFollowing);
}