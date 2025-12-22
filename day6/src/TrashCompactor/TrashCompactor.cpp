#include "TrashCompactor.h"
#include <cstddef>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

TrashCompactor::TrashCompactor() {
    mathMatrix = std::vector<std::vector<std::string>>();
    return;
}


/*
 * Solution for problem 1
 */
long TrashCompactor::solve(std::vector<std::string>& rows) {

    mathMatrix = std::vector<std::vector<std::string>>();
    populateMathMatrix(rows);

    long sum = 0;
    long opRow = mathMatrix.size()-1;
    std::vector<long> resultVec = std::vector<long>();

    // Create lambda for arithmetic
    auto addition = [](long x, long y) -> long { return x + y; };
    auto multiplication = [](long x, long y) -> long { return x*y; };

    // Solve...
    for (long col = 0; col < mathMatrix[0].size(); col++) {

        // Set operator (see h-file for definition of Calculation)
        Calculation op;
        switch (mathMatrix[opRow][col].at(0)) {
            case '+':
                op = addition;
                break;
            case '*':
                op = multiplication;
                break; 
        }

        // Calculate this columns result
        long result = std::stol(mathMatrix[0][col]);
        for(long row = 1; row < opRow; row++) result = op(result, std::stol(mathMatrix[row][col]));

        resultVec.insert(resultVec.end(), result);
    }

    sum = std::accumulate(resultVec.begin(), resultVec.end(), decltype(resultVec)::value_type(0));
    return sum;
}


/*
 * Solution for problem 2
 */
long TrashCompactor::solve2(std::vector<std::string>& rows) {

    mathMatrix = std::vector<std::vector<std::string>>();
    populateMathMatrix2(rows);

    long sum = 0;
    long opRow = mathMatrix.size()-1;
    std::vector<long> resultVec = std::vector<long>();

    // Create lambda for arithmetic
    auto addition = [](long x, long y) -> long { return x + y; };
    auto multiplication = [](long x, long y) -> long { return x*y; };

    // Solve...
    for (long col = 0; col < mathMatrix[0].size(); col++) {

        // Set operator (see h-file for definition of Calculation)
        Calculation op;
        switch (mathMatrix[opRow][col].at(0)) {
            case '+':
                op = addition;
                break;
            case '*':
                op = multiplication;
                break; 
        }

        std::vector<long> numbers = std::vector<long>();

        for(long vertical = mathMatrix[0][col].size()-1; vertical >= 0; vertical--) {
            std::string str = std::string();
            for(long row = 0; row < opRow; row++)
                if (mathMatrix[row][col][vertical] != ' ') str.push_back(mathMatrix[row][col][vertical]);

            numbers.push_back(std::stol(str));
        }

        long result = numbers[0];
        for(long i = 1; i < numbers.size(); i++) result = op(result, numbers[i]);
        resultVec.insert(resultVec.end(), result);
    }

    sum = std::accumulate(resultVec.begin(), resultVec.end(), decltype(resultVec)::value_type(0));

    return sum;
}


/*
 * Populate mathMatrix with data from input. Chaotic af
 */
void TrashCompactor::populateMathMatrix2(std::vector<std::string>& rows) {

    std::string ops = rows[rows.size()-1];
    for (long row = 0; row < rows.size()-1; row++) {

        std::vector<std::string> mathRow = std::vector<std::string>();

        std::size_t segStart = positiveMin(ops.find_first_of('+'), ops.find_first_of('*'));
        std::size_t nextSeg = positiveMin(ops.find_first_of('+', segStart+1), ops.find_first_of('*', segStart+1));

        while (nextSeg != std::string::npos) {
            mathRow.push_back(rows[row].substr(segStart, (nextSeg-1)-segStart));

            segStart=nextSeg;
            nextSeg = positiveMin(ops.find_first_of('+',nextSeg+1), ops.find_first_of('*',nextSeg+1));
        }

        mathRow.push_back(rows[row].substr(segStart));
        mathMatrix.push_back(mathRow);
    }

    std::vector<std::string> opRow = std::vector<std::string>();

    std::size_t segStart = positiveMin(ops.find_first_of('+'), ops.find_first_of('*'));
    std::size_t nextSeg = positiveMin(ops.find_first_of('+', segStart+1), ops.find_first_of('*', segStart+1));

    while (nextSeg != std::string::npos) {
        opRow.push_back(ops.substr(segStart, 1));

        segStart=nextSeg;
        nextSeg = positiveMin(ops.find_first_of('+',nextSeg+1), ops.find_first_of('*',nextSeg+1));
    }
    opRow.push_back(ops.substr(segStart, 1));
    mathMatrix.push_back(opRow);
}


/*
 * Return a positive min if it exists
 */
long TrashCompactor::positiveMin(long a, long b) {
    if(a < 0) a = b;
    if(b < 0) b = a;

    return std::min(a, b);
}


/*
 * Populate mathMatrix with data from input
 */
void TrashCompactor::populateMathMatrix(std::vector<std::string>& rows) {
    
    for(std::string s : rows) {

        std::vector<std::string> mathRow = mathStringHandler(s);
        mathMatrix.insert(mathMatrix.end(), mathRow);
    }
}


/*
 * Modified from day2.
 */
std::vector<std::string> TrashCompactor::mathStringHandler(std::string& ogString) {

    // Create a vector for storing all ranges entered in ogString
    auto retVector = std::vector<std::string>();

    std::size_t textPos = ogString.find_first_not_of(' ');
    std::size_t spacePos = ogString.find_first_of(' ');
    std::size_t nextPos = ogString.find_first_not_of(' ', spacePos);

    while (nextPos != std::string::npos) {
        retVector.insert(retVector.end(), ogString.substr(textPos, spacePos-textPos));

        textPos=nextPos;
        spacePos = ogString.find_first_of(' ', textPos);
        nextPos = ogString.find_first_not_of(' ', spacePos);
    }

    retVector.insert(retVector.end(), ogString.substr(textPos));
    
    return retVector;
}


/*
 * Print math matrix
 */
void TrashCompactor::printMathMatrix() {
    for(auto& sv : mathMatrix) {
        for (auto& s : sv) {
            std::cout << s << ",";
        }
        std::cout << std::endl;
    }
}