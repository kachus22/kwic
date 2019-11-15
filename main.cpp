#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "input.hpp"
#include "printer.hpp"
#include "reader.hpp"
#include "rotation.hpp"
#include "sorting.hpp"
#include <set>

using namespace std;

int main() {
    vector<vector<string>> lines;
    vector<vector<string>> unorderedRotations;
    Input io;
    Reader<string> reader;
    RotationFilter<string> rotateFilter;
    Printer<string> printer;


    // Read initial data
    reader.processData(lines);
    set<int> linesToRemove = io.askToRemoveLines();
    if (!linesToRemove.empty())
        lines = reader.deleteLinesByNumber(lines, linesToRemove);

    bool removeStopwords = io.askToRemoveStopwords();
    if (removeStopwords) reader.deleteStopWords(lines);
    // Pass each line through the rotation filter
    for(auto line : lines) {
        rotateFilter.processData(unorderedRotations, line);
    }
    
    bool sortingOrder = io.askSortingOrder();
    SortingFilter sortingFilter(sortingOrder);
    vector<vector<string>> sorted = sortingFilter.processData(unorderedRotations);
    // Order all the combinations and print them
    printer.processData(sorted);

    linesToRemove = io.askToRemoveLines();
    if (!linesToRemove.empty())
        sorted = reader.deleteLinesByNumber(sorted, linesToRemove);
    printer.processData(sorted);
}