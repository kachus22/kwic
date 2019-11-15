#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "input.hpp"
#include "printer.hpp"
#include "reader.hpp"
#include "rotation.hpp"
#include "sorting.hpp"

using namespace std;

int main() {
    vector<vector<string>> lines;
    vector<vector<string>> unorderedRotations;
    Input io;
    Reader<string> reader;
    RotationFilter<string> rotateFilter;
    Printer<string> printer;

    vector<int> linesToRemove = io.askToRemoveLines();
    bool removeStopwords = io.askToRemoveStopwords();
    bool sortingOrder = io.askSortingOrder();

    // Read initial data
    reader.processData(lines);
    if (!linesToRemove.empty())
        reader.deleteLinesByNumber(lines, linesToRemove);
    if (removeStopwords) reader.deleteStopWords(lines);
    // Pass each line through the rotation filter
    for(auto line : lines) {
        rotateFilter.processData(unorderedRotations, line);
    }
    
    SortingFilter sortingFilter(sortingOrder);
    vector<vector<string>> sorted = sortingFilter.processData(unorderedRotations);
    // Order all the combinations and print them
    printer.processData(sorted);

    linesToRemove = io.askToRemoveLines();
    if (!linesToRemove.empty())
        reader.deleteLinesByNumber(sorted, linesToRemove);
    printer.processData(sorted);
}