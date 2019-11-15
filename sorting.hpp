#include <iostream>
#include <vector>

using namespace std;

string toUpper(string s) {
    string res = s;
    for (char &c : res)
        c = toupper(c);
    return res;
}

string vectorToString(vector<string> v) {
    string s;
    for (auto &w : v)
        s += toUpper(w);
    return s;
}

bool caseInsensitiveAscCmp(vector<string> lhs, vector<string> rhs) {
    string l = vectorToString(lhs);
    string r = vectorToString(rhs);
    return l < r;
}

bool caseInsensitiveDescCmp(vector<string> lhs, vector<string> rhs) {
    string l = vectorToString(lhs);
    string r = vectorToString(rhs);
    return l > r;
}

class SortingFilter {
public:
    SortingFilter();
    SortingFilter(bool ascOrder) : sortAscending(ascOrder) {};
    vector<vector<string>> processData(vector<vector<string>> A);
private:
    bool sortAscending;
};

vector<vector<string>> SortingFilter::processData(vector<vector<string>> A){
    vector<vector<string>> ordered = A;
    sort(ordered.begin(), ordered.end(), sortAscending ? caseInsensitiveAscCmp : caseInsensitiveDescCmp);
    return ordered;
}