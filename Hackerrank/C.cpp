#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int q;
ll fact[1<<20];
string t;

void genFact() {
    fact[0]=1;
    for(int i=1; i<=pow(10, 6); ++i)
        fact[i]=(fact[i-1]*i)%M;
}

ll powM(ll a, ll b, ll M) {
    ll ans=1;
    while(b) {
        if(b&1) {
            ans*=a;
            ans%=M;
            --b;
        }
        a=a*a;
        a%=M;
        b/=2;
    }
    return ans;
}

int main() {
    cin >> t;
    // cout << t.substr(57433, 46) << endl;;
    int n=t.size();
    vector<ar<int, 26>> cc(n+1);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<26; ++j)
            cc[i+1][j]=cc[i][j];
        cc[i+1][t[i]-'a']=cc[i][t[i]-'a']+1;
    }

    genFact();
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        vector<ll> freq;
        int mx=INT_MIN, cntMx=0;
        for(int i=0; i<26; ++i) {
            int c=cc[b][i]-cc[a-1][i];
            if(!c)
                continue;
            if(c>1) // No matter even and odd, just /2 add to freq
                freq.push_back(c/2);
            if(c&1) { // Each odd character can occupy middle pos
                ++cntMx;
            }
        }
        // cout << mx << ", " << cntMx << endl;
        ll s=0, dv=1;
        for(ll& f : freq) {
            // cout <<"f: " << f <<endl;
            s+=f;
            dv=(dv*fact[f])%M;
        }
        // cout << s << " " << fact[s] << " "  << dv << " " << powM(dv, M-2, M) <<endl;
        ll ans=(fact[s]*powM(dv, M-2, M))%M;
        if(cntMx>1)
            ans=(ans*cntMx)%M;
        cout << ans << endl;
    }
}
