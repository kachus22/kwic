#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "printer.hpp"
#include "rotation.hpp"
#include "sorting.hpp"

using namespace std;

int main() {
    string line;
    vector<vector<string>> lines;
    vector<vector<string>> unorderedRotations;
    RotationFilter<string> rotateFilter;
    SortingFilter<string> sortingFilter;
    Printer<string> printer;

    while (getline(cin, line) && !line.empty()) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        lines.push_back(words);
    }
    
    // Pass each line through the rotation filter
    for(auto line : lines) {
        rotateFilter.processData(unorderedRotations, line);
    }

    // Order all the combinations and print them
    printer.processData(sortingFilter.processData(unorderedRotations));
}