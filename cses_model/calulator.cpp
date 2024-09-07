#include <bits/stdc++.h>
#define ar array
#define ll long long 
using namespace std;

const int mxN=200;

int calculate(string s) {
    int num=0;
    char sign='+';
    vector<int> dg;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||i==s.size()-1) {
            if(s[i]>='0'&&s[i]<='9') num=num*10+(s[i]-'0');
            if(sign=='+')
                dg.push_back(num);
            else if(sign=='-')
                dg.push_back(-num);
            else if(sign=='*')
                dg.back()*=num;
            else if(sign=='/')
                dg.back()/=num;
            sign=s[i];
            num=0;
        }
        else if(s[i]>='0'&&s[i]<='9') {
            num=num*10+(s[i]-'0');
        }
    }
    int ans=0;
    for(int a : dg)
        ans+=a, cout << a << endl;
    return ans;
}
