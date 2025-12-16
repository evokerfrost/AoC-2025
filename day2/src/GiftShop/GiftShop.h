#ifndef GIFTSHOP_H
#define GIFTSHOP_H

#include <string>
#include <vector>
class GiftShop {
    public:
        GiftShop();
        int solve(std::string& ranges);
        int solve2(std::string& ranges);
    private:
        
        std::vector<std::string> idStringHandler(std::string& ogString);
        bool isValid(int id);
};

#endif