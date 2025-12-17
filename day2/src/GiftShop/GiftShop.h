#ifndef GIFTSHOP_H
#define GIFTSHOP_H

#include <string>
#include <vector>
class GiftShop {
    public:
        GiftShop();
        long solve(std::string& ranges);
        long solve2(std::string& ranges);
    private:
        
        std::vector<std::string> idStringHandler(std::string& ogString);
        bool isValid(long id);
};

#endif