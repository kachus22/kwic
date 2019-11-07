#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class SortingFilter {
public:
    vector<vector<T>> processData(vector<vector<T>> A);
};

template<typename T>
vector<vector<T>> SortingFilter<T>::processData(vector<vector<T>> A){
    vector<vector<T>> ordered = A;
    sort(ordered.begin(), ordered.end());
    return ordered;
}