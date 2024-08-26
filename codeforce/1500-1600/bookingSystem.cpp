#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;

bool use[mxN];
vector<ar<int, 3>> ans; // {guest_id, table_id, guest_pay}
vector<ar<int, 2>> table; // {room, table_id}
vector<ar<int, 3>> guest; // {pay, number, guest_id}

int n, k;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        guest.push_back({b, a, i});
    }
    cin >> k;
    for(int i=0; i<k; ++i) {
        int a;
        cin >> a;
        table.push_back({a, i});
    }
    sort(guest.begin(), guest.end(), greater<ar<int, 3>>());
    sort(table.begin(), table.end());
    for(int i=0; i<n; ++i) {
        for(int j=0; j<table.size(); ++j) {
            if(!use[j]&&guest[i][1]<=table[j][0]) {
                ans.push_back({guest[i][2], table[j][1], guest[i][0]});
                use[j]=1;
                break;
            }
        }
    }

    int m=0;
    for(int i=0; i<ans.size(); ++i)
        m+=ans[i][2];
    cout << ans.size() << " " << m << endl;
    for(auto a : ans)
        cout << a[0]+1 << " " << a[1]+1 << endl;
}
