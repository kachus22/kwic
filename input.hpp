#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Input {
public:
    set<int> askToRemoveLines();
    bool        askToRemoveStopwords();
    bool        askSortingOrder();
};

// Returns indexes to be removed
set<int> Input::askToRemoveLines(){
    set<int> linesToRemove;
    string line;
    do {
        cout << "Desea borrar alguna linea? (ENTER si no) ";
        getline(cin, line);
        if (line != "")
            linesToRemove.insert(stoi(line));
    }
    while (line != "");
    return linesToRemove;
}

// True if stopwords will be removed
bool Input::askToRemoveStopwords(){
    cout << "Desea borrar stopwords? (y/n) ";
    string line;
    getline(cin, line);
    return line == "Y" || line == "y";
}

// True if ascending
bool Input::askSortingOrder(){
    cout << "Que tipo de orden desea? (asc/desc) ";
    string line;
    getline(cin, line);
    return line == "ASC" || line == "asc";
}
