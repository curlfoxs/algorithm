#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mxN=1e16, M=1e9+7;

int ans[17];

void move(int num, int from, int to) {
    // 2 0 0
    if(num==1){
        cout << from << " " << to << endl;
    }
    else {
        int middle;
        set<int> st;
        st.insert(from);
        st.insert(to);
        for(int i=1; i<=3; ++i)
            if(st.find(i)==st.end())
                middle=i;
        move(num-1, from, middle);
        move(1, from, to);
        move(num-1, middle, to);
    }
}

int main() {
    int n;
    cin >> n;
    ans[1]=1;
    for(int i=2; i<=n; ++i)
        ans[i]=2*ans[i-1]+1;
    cout << ans[n] << endl;
    move(n, 1, 3);
}
