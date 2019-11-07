#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Printer {
public:
    void processData(vector<vector<T>> A);
};


template<typename T>
void Printer<T>::processData(vector<vector<T>> A){
    for (auto r : A) {
        for (auto w : r)
            cout << w << " ";
        cout << "\n";
    }
}

