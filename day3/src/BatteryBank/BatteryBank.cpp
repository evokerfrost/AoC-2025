#include "BatteryBank.h"
#include <algorithm>
#include <cmath>
#include <iostream>
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
long BatteryBank::solve2(std::vector<std::string>& banks) {

    long sum = 0;

    for(std::string& bank : banks) {
        sum += findLargestJoltage2(bank);
    }

    return sum;
}


/*
 * Find the largest Joltage possible in string (2 numbers).
 */
int BatteryBank::findLargestJoltage(std::string& bankString) {
    
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


/*
 * Find the largest Joltage possible in string (12 numbers).
 */
long BatteryBank::findLargestJoltage2(std::string& bankString) {

    const int batNum = 12;

    std::vector<int> joltageVector(batNum, 0);
    int searchingFor = 0;

    // Loop over the entire bankString
    for(int i = 0; i < bankString.length(); i++) {

        // Save the actual integer for the current char
        int battery = bankString[i]-'0';

        // If the only option is to turn on the rest of the batteries, just turn them on.
        if(batNum - searchingFor == bankString.length() - i) {

            // The call to max handles the final character. joltageVector[searchingFor] is usually 0.
            joltageVector[searchingFor] = std::max(battery, joltageVector[searchingFor]);
            if (searchingFor != batNum-1) searchingFor++;
            continue;
        }

        // Check if the battery improves the current joltage
        if(battery > joltageVector[searchingFor]) {

            // Find the optimal battery to replace, and zero every following battery.
            for (int j = searchingFor; j >= 0 && batNum-(j+1) != bankString.length() - i; j--) {
                if(battery > joltageVector[j]) {
                    joltageVector[j] = 0;
                    searchingFor = j;
                }
                else break;
            }

            joltageVector[searchingFor] = battery;
            if (searchingFor != batNum-1) searchingFor++;
        }
    }

    // Add everything together.
    long sum = 0;
    for(int i = 0; i < batNum; i++) sum += (joltageVector[i]*(std::pow(10, batNum-(i+1))));
    return sum;
}


/*
 * Print vectors
 */
void BatteryBank::printVec(std::vector<int> vec) {
    
    std::cout << std::endl;

    for(auto& num : vec) {
        std::cout << std::to_string(num);
    }
    std::cout << std::endl;
}