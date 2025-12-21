#include "BatteryBank.h"
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

    int sum = 0;

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

    std::vector<int> joltageVector(batNum, -1);
    int searchingFor = 0;

    // Loop over the entire bankString
    for(int i = 0; i < bankString.length(); i++) {

        // Save the actual integer for the current char
        int battery = bankString[i]-'0';

        if(batNum - searchingFor == bankString.length() - i) {
            joltageVector[searchingFor] = battery;
            if (searchingFor != batNum-1) searchingFor++;
            
        }

        // Check if the battery improves the current joltage
        if(battery > joltageVector[searchingFor]) {

            // Check which, and how many, batteries to change
            for (int j = searchingFor-1; j >= 0 && batNum-(j+1); j--) {
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

    long sum = 0;

    // Add everything together.
    for(int i = 0; i < batNum; i++) sum += (joltageVector[i]*(10*(batNum-i)));

    return sum;
}