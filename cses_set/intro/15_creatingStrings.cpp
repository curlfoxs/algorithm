#include <bits/stdc++.h>

using namespace std;

#define ll long long

set<string> ans;
bool used[8];

void dfs(string s, string cur, int x, int n) {
    if(x==n) {
        ans.insert(cur);
        return;
    }
    for(int i=0; i<n; ++i) {
        if(used[i])
            continue;
        used[i]=1;
        dfs(s, cur+s[i], x+1, n);
        used[i]=0;
    }
}


int main() {
    string s;
    cin >> s;
    int n=s.size();
    // 简答的插入排序实现，先做一个有序序列出来
    // for(int i=1; i<n; ++i) { // 不断地扩大有序队伍
    //     char t=s[i];
    //     int j;
    //     for(j=i-1; j>=0&&s[j]>t; --j)
    //         s[j+1]=s[j]; // 往后移
    //     s[++j]=t;
    // }
    sort(s.begin(), s.end()); // 先做一个有序序列出来
    string cur;
    dfs(s, cur, 0, n);
    cout << ans.size() << endl;
    for(string a : ans)
        cout << a << endl;
}
