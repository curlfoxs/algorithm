#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define ar array

const int mxN=1e6, M=1000696969, B=69;
ll pB[mxN+1], h[mxN+1]; // pB B^mxN次幂, h表示长度为mxN的字符串的哈希值
int n;
string s;

ll hs(int i, int len) {
    int r=i+len;
    ll res;
    res=(h[r]-h[i]*pB[len])%M;
    if(res<0)
        res+=M;
    return res;
}
int main() {
    cin >> s;
    n=s.size();
    // 使用前缀和计算任意字符子串的哈希值
    // 前缀和通常是不包括当前元素的，可以理解为数目
    // 可能有时候需要考虑不同的基数进制，所以要有nb，
    pB[0]=1;
    for(int j=1; j<n; ++j) {
        pB[j]=(pB[j-1]*B)%M;
    }
    for(int j=1; j<=n; ++j) {
        h[j]=(h[j-1]*B+s[j-1]-'a'+1)%M;
    }


    for(int l=1; l<n; ++l) {
        if(hs(0, l)==hs(n-l, l))
            cout << l << " ";
    }
}
