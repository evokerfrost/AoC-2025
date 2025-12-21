#include "PrintingDepartment.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

PrintingDepartment::PrintingDepartment() {
    return;
}


/*
 * Solution for problem 1
 */
int PrintingDepartment::solve(std::vector<std::string>& paper) {

    int sum = 0;
    getMatrix(paper);
    return sum;
}


/*
 * Solution for problem 2
 */
long PrintingDepartment::solve2(std::vector<std::string>& paper) {

    long sum = 0;

    return sum;
}


/*
 * Transfors the input string into a matrix. True indicates presence of paper
 */
std::vector<std::vector<bool>> PrintingDepartment::getMatrix(std::vector<std::string>& input) {
    auto ret = std::vector<std::vector<bool>>();

    // Extract all paper positions
    for(auto& str : input) {
        ret.insert(ret.end(), std::vector<bool>());

        // Use lambda function for transforming a text matrix to a boolean one
        std::transform(str.begin(), str.end(),std::back_inserter(ret[ret.size()-1]),
        [](char c) -> bool {
            return c=='@';
        });
    }

    return ret;
}


/*
 * Print vectors
 */
void PrintingDepartment::printMatrix(std::vector<std::vector<bool>> matrix) {
    
    std::cout << std::endl;

    for(auto& vec : matrix) {
        for(bool b : vec) {
            std::cout << (b ? "@" : ".");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}