#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=25, d[4][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n;
bool vis[mxN][mxN];

bool val(int ui, int uj) {
    return ui>=0&&ui<n&&uj>=0&&uj<n&&!vis[ui][uj];
}
int mnStep(int a, int b) {
    memset(vis, 0, mxN*mxN);
    int step=-1;

    return step;
}
int main() {
    cin >> n;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<n; ++j) {
            cout << mnStep(i, j) << " ";
        }
        cout << endl;
    }
}
