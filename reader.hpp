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
    void deleteLinesByNumber(vector<vector<T>>& A, vector<int>& lineNumbers);
    void deleteStopWords(vector<vector<T>>& A);
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
void Reader<T>::deleteLinesByNumber(vector<vector<T>>& A, vector<int>& lineNumbers) {
    // pass vect to map
    map<int, vector<T>> lines;
    for(int i = 0; i < A.size(); i++) {
        lines[i] = A[i - 1];
    }

    // erase lines
    cout << "Lineas a borrar\n";
    for(auto line : lineNumbers) {
        cout << line << " ";
        for (auto w : lines[line])
            cout << w << " ";
        cout << endl;
        lines.erase(line);
    }
    cout << "-------------\n";

    // create new vector of lines and return them
    vector<vector<T>> newLines;
    for(auto linePair : lines) {
        newLines.push_back(linePair.second);
    }
    A = newLines;
}

template<typename T>
void Reader<T>::deleteStopWords(vector<vector<T>>& A) {
    ifstream file;
    file.open("stop.txt");
    string word;
    while (!file.eof()) {
        getline(file, word);
        for(auto &v : A)
            v.erase(std::remove(v.begin(), v.end(), word), v.end());
    }
    file.close();
}