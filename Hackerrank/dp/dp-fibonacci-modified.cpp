#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=20, M=1e9+7;
int n;
string dp[mxN+1];

string add(string a, string b) {
    int n=a.size(), m=b.size();
    int cf=0;
    string ans;
    for(int i=n-1, j=m-1; i>=0||j>=0||cf; --i, --j) {
        if(i>=0)
            cf+=(a[i]-'0');
        if(j>=0)
            cf+=(b[j]-'0');
        ans=to_string(cf%10)+ans;
        cf/=10;
    }
    return ans;
}

string mul(string a, string b) {
    if(a=="0"||b=="0")
        return "0";
    int n=a.size(), m=b.size();
    vector<int> ans(n+m, 0);
    for(int i=n-1; ~i; --i) {
        for(int j=m-1; ~j; --j) {
            ans[i+j+1]+=(a[i]-'0')*(b[j]-'0');
            ans[i+j]+=ans[i+j+1]/10;
            ans[i+j+1]%=10;
        }
    }
    string s;
    for(int i=0; i<ans.size(); ++i) {
        if(i==0)
            while(ans[i]==0) ++i;
        s+=(ans[i]+'0');
    }
    return s;
}

int main() {
    cin >> dp[1] >> dp[2] >> n;
    for(int i=3; i<=n; ++i) {
        dp[i]=add(dp[i-2], mul(dp[i-1], dp[i-1]));
    }
    cout << dp[n];
    // cout << add("99334", "3434") << endl;
}
