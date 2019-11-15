#include <iostream>
#include <vector>

using namespace std;

string toUpper(string s) {
    string res = s;
    for (char &c : res)
        c = toupper(c);
    return res;
}

bool caseInsensitiveCmp(vector<string> lhs, vector<string> rhs) {
    string l;
    for (auto &w : lhs)
        l += toUpper(w);

    string r;
    for (auto &w : rhs)
        r += toUpper(w);

    return l < r;
}

class SortingFilter {
public:
    vector<vector<string>> processData(vector<vector<string>> A);
};

vector<vector<string>> SortingFilter::processData(vector<vector<string>> A){
    vector<vector<string>> ordered = A;
    sort(ordered.begin(), ordered.end(), caseInsensitiveCmp);
    return ordered;
}