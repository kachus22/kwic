#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

template<typename T>
class Reader {
public:
    void processData(vector<vector<T>>& A);
    vector<vector<T>> deleteLinesByNumber(const vector<vector<T>> &A, set<int>& lineNumbers);
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
vector<vector<T>> Reader<T>::deleteLinesByNumber(const vector<vector<T>> &A, set<int>& lineNumbers) {
    // pass vect to map
    cout << "Lineas a borrar\n";
    vector<vector<T>> newLines;
    for(int i = 0; i < A.size(); i++) {
        if(!lineNumbers.count(i + 1))
            newLines.push_back(A[i]);
        else {
            cout << (i + 1) << " ";
            for (auto w : A[i])
                cout << w << " ";
            cout << endl;
        }
    }

    return newLines;
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