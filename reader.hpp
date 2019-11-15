#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

template<typename T>
class Reader {
public:
    void processData(vector<vector<T>>& A);
    vector<vector<T>> deleteLinesByNumber(vector<vector<T>>& A, vector<int>& lineNumbers);
};

template<typename T>
void Reader<T>::processData(vector<vector<T>>& A){
    ifstream file;
    file.open("a.txt");
    if(!file.good())
        throw runtime_error("El archivo con ese nombre no existe");

    

    string line;
    int i = 0;
    cout << "Texto inicial\n";
    cout << "-------------\n";
    while (!file.eof()) {
        getline(file, line);
        vector<string> words;
        cout << ++i << " " << line << "\n";
        stringstream ss(line);
        T word;
        while (ss >> word) {
            words.push_back(word);
        }
        A.push_back(words);
    }
    cout << "-------------\n";
    file.close();
}

template<typename T>
vector<vector<T>> Reader<T>::deleteLinesByNumber(vector<vector<T>>& A, vector<int>& lineNumbers) {
    // pass vect to map
    map<int, <vector<T>>> lines;
    for(int i = 0; i < A.size(); i++) {
        if(lines.count(A[i]) > 0) {
            lines[i] = A[i];
        } 
    }

    // erase lines
    for(auto line : lineNumbers) {
        lines.erase(line);
    }

    // create new vector of lines and return them
    vector<vector<T>> newLines;
    for(auto linePair : lines) {
        newLines.push_back(linePair.second);
    }

    return newLines;
}