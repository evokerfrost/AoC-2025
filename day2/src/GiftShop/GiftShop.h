#ifndef GIFTSHOP_H
#define GIFTSHOP_H

#include <string>
#include <vector>

class GiftShop {
    public:
        GiftShop();

        // Solution to first problem
        long solve(std::string& ranges);

        //Solution to second problem
        long solve2(std::string& ranges);
    private:
        // Helper functions
        std::vector<std::string> idStringHandler(std::string& ogString);
        bool isValid(long id);
};

#endif