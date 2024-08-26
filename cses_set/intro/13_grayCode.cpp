#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mxN=1e16, M=1e9+7;

int main() {
    int n;
    cin >> n;
    vector<string> v;
    v.push_back("0");
    v.push_back("1");
    for(int i=0; i<n-1; ++i) {
        vector<string> v1, v2;
        for(int j=0; j<v.size(); ++j)
            v1.push_back("0"+v[j]);
        for(int j=v.size()-1; j>=0; --j) // vector的倒序遍历
            v2.push_back("1"+v[j]);
        v1.insert(v1.end(), v2.begin(), v2.end()); // 两个vector合并
        v=v1;
    }
    for(string a : v)
        cout << a << endl;
}
