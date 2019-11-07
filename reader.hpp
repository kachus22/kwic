#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Reader {
public:
    void processData(vector<vector<T>>& A);
};

template<typename T>
void Reader<T>::processData(vector<vector<T>>& A){
    string line;
    while (getline(cin, line) && !line.empty()) {
        vector<string> words;
        stringstream ss(line);
        T word;
        while (ss >> word) {
            words.push_back(word);
        }
        A.push_back(words);
    }
}
