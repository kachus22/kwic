#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "printer.hpp"
#include "reader.hpp"
#include "rotation.hpp"
#include "sorting.hpp"

using namespace std;

int main() {
    vector<vector<string>> lines;
    vector<vector<string>> unorderedRotations;
    Reader<string> reader;
    RotationFilter<string> rotateFilter;
    SortingFilter sortingFilter;
    Printer<string> printer;

    // Read initial data
    reader.processData(lines);
    // Pass each line through the rotation filter
    for(auto line : lines) {
        rotateFilter.processData(unorderedRotations, line);
    }
    // Order all the combinations and print them
    printer.processData(sortingFilter.processData(unorderedRotations));
}