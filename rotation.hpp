#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class RotationFilter {
public:
    void processData(vector<vector<T>>& A, vector<T> B);
private:
    vector<T> rotateData(vector<T> &A, int B);
};

template<typename T>
void RotationFilter<T>::processData(vector<vector<T>>& A, vector<T> B){
    for (int i = 0; i < B.size(); ++i) {
        auto rotation = rotateData(B, i);
        A.push_back(rotation);
    }
}

template<typename T>
vector<T> RotationFilter<T>::rotateData(vector<T> &A, int B) {
    vector<T> rotated; 
    for (int i = 0; i < A.size(); i++) {
        rotated.push_back(A[(i + B) % A.size()]);
    }
    return rotated;
}