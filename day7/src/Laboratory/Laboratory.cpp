#include "Laboratory.h"
#include <iostream>
#include <string>
#include <vector>

Laboratory::Laboratory() {
    this->matrix = std::vector<std::string>();
    this->sum = 0;
    return;
}


/*
 * Solution for problem 1
 */
long Laboratory::solve(std::vector<std::string>& rows) {

    this->matrix = std::vector<std::string>(rows);
    this->sum = 0;

    for (int row = 0; row < rows.size()-1; row++) {
        progress(row);
    }

    return sum;
}


/*
 * Solution for problem 2
 */
long Laboratory::solve2(std::vector<std::string>& rows) {

    long sum = 0;

    return sum;
}



// Private functions ------------------------------------


/*
 * Handle the row specified in the row variable (progress the tachyon beam).
 * This assumes that the previous row was handled earlier.
 */
void Laboratory::progress(long row) {

    // Handle the first row separately
    if (row == 0) {
        long startIndex = this->matrix[0].find_first_of('S');
        this->matrix[1][startIndex] = '|';
        return;
    }

    for (int i = 0; i < this->matrix[row].size(); i++) {
        
        // The beam does not continue here, skip to next character
        if(this->matrix[row-1][i] != '|') continue;

        // Check if there is a splitter here
        if(this->matrix[row][i] == '^') {
            this->sum++;
            this->matrix[row][i-1] = '|';
            this->matrix[row][i+1] = '|';
            this->matrix[row+1][i-1] = '|';
            this->matrix[row+1][i+1] = '|';
        }
        // Check if a beam continues here
        else if(this->matrix[row][i] == '|' && this->matrix[row+1][i] != '^') {
            this->matrix[row+1][i] = '|';
        }
    }
}


/*
 * Count the total number of techyon beams at the final row of matrix.
 */
long Laboratory::countTotal() {

    long sum = 0;
    for (char c : this->matrix[this->matrix.size()-1]) {
        if(c == '|') sum++;
    }

    return sum;
}