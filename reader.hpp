#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
class Reader {
public:
    void processData(vector<vector<T>>& A);
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
