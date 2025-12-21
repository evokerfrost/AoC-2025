#include "PrintingDepartment.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

PrintingDepartment::PrintingDepartment() {
    matrix = std::vector<std::vector<bool>>();
    return;
}


/*
 * Solution for problem 1
 */
int PrintingDepartment::solve(std::vector<std::string>& paper) {

    int sum = 0;
    buildMatrix(paper);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] && getNumNeighbours(i, j) < 4) sum++;
        }
    }
    return sum;
}


/*
 * Solution for problem 2
 */
long PrintingDepartment::solve2(std::vector<std::string>& paper) {

    int sum = 0;

    buildMatrix(paper);

    // Look for accessible paper until no more paper can be found
    std::vector<std::pair<int, int>> removalList;
    do{
        // Empty removalList
        removalList = {};

        // Check which rolls of paper you can move
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {

                // Roll of paper can be moved. Add to removalList
                if (matrix[i][j] && getNumNeighbours(i, j) < 4) {
                    removalList.insert(removalList.end(), {i, j});
                    sum++;
                }
            }
        }

        // Remove all paper in removalList
        for (auto& removal : removalList) {
            matrix[removal.first][removal.second] = false;
        }
    }while(!removalList.empty());

    return sum;
}


/*
 * Get neighbours to specified row,col
 */
int PrintingDepartment::getNumNeighbours(int row, int col) {

    int count = 0;

    //std::cout << "Row: " << row << ", Col: " << col << std::endl;

    for (int i = std::max(0, row-1); i < std::min((int)matrix.size(), row+2); i++) {
        for (int j = std::max(0, col-1); j < std::min((int)matrix[row].size(), col+2); j++) {

            if(i == row && j == col) continue;

            if(matrix[i][j]) count++;
        }
    }

    //std::cout << count << std::endl;
    return count;
}


/*
 * Transfors the input string into a matrix. True indicates presence of paper
 */
void PrintingDepartment::buildMatrix(std::vector<std::string>& input) {

    matrix = std::vector<std::vector<bool>>();

    // Extract all paper positions
    for(auto& str : input) {
        matrix.insert(matrix.end(), std::vector<bool>());

        // Use lambda function for transforming a text matrix to a boolean one
        std::transform(str.begin(), str.end(),std::back_inserter(matrix[matrix.size()-1]),
        [](char c) -> bool {
            return c=='@';
        });
    }
}


/*
 * Print vectors
 */
void PrintingDepartment::printMatrix() {
    
    std::cout << std::endl;

    for(auto& vec : matrix) {
        for(bool b : vec) {
            std::cout << (b ? "@" : ".");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}