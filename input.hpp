#include <iostream>
#include <vector>

using namespace std;

class Input {
public:
    vector<int> askToRemoveLines();
    bool        askToRemoveStopwords();
    bool        askSortingOrder();
};

// Returns indexes to be removed
vector<int> Input::askToRemoveLines(){
    vector<int> linesToRemove;
    string line;
    do {
        cout << "Desea borrar alguna linea? (ENTER si no) ";
        getline(cin, line);
        if (line != "")
            linesToRemove.push_back(stoi(line));
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
