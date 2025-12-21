#ifndef BATTERYBANK_H
#define BATTERYBANK_H

#include <string>
#include <vector>

class BatteryBank {
    public:
        BatteryBank();

        // Solution to first problem
        int solve(std::vector<std::string>& banks);

        //Solution to second problem
        long solve2(std::vector<std::string>& banks);
    private:
        // Helper functions
        int findLargestJoltage(std::string& bankString);
        long findLargestJoltage2(std::string& bankString);
};

#endif