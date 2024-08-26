#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array
#define pr pair
const ll mxN=2e5;

ll n, q[mxN];
vector<ar<ll, 3>> a, b, hull; // {y(0), slop, original_index}
ar<ll, 2> ans[mxN]; // {de, dv}

ar<ll, 2> cal_time(ar<ll, 3> l1, ar<ll, 3> l2) { // Caculate ller time
    ar<ll, 2> res;
    res[0]=abs(l1[0]-l2[0]);
    res[1]=abs(l1[1]-l2[1]);
    return res;
}
int cmp(ar<ll, 3> l1, ar<ll, 3> l2, ar<ll, 3> l3) { // Compare llersection position
    ar<ll, 2> t1=cal_time(l1, l2);
    ar<ll, 2> t2=cal_time(l1, l3);
    ll res=t1[0]*t2[1]-t1[1]*t2[0];
    if(res<0)
        return -1;
    else if(res==0)
        return 0;
    else
        return 1;
}
int main() {
    ifstream cin("falling.in");
    ofstream cout("falling.out");
    cin >> n;
    for(ll i=0; i<n; ++i) {
        ll x;
        cin >> x;
        a.push_back({x, -(i+1), i});
        b.push_back({x, -(i+1), i});
    }
    for(ll i=0; i<n; ++i)
        cin >> q[i], q[i]--;
    // cout << "hello" << endl;
    sort(a.begin(), a.end());
    // Case 1: a[q[i]][0] < a[i][0]
    for(ll i=n-1; ~i; --i) {
        while(hull.size()) {
            if(a[i][1]<hull.back()[1]) {
                hull.pop_back();
                continue;
            }
            if(hull.size()>=2&&cmp(a[i],  hull[hull.size()-1], hull[hull.size()-2])>=0) {
                hull.pop_back();
                continue;
            }
            break;
        }
        hull.push_back(a[i]);
        ll ix=a[i][2]; // original index
        // cout << "why?" << endl;
        // cout << hull.size() << endl;
        if(b[q[ix]][0]<b[ix][0]) {
            // cout << "why?" << endl;
            if(b[q[ix]][1]<=hull[0][1]) {
                ans[ix]={-1, -1};
                continue;
            }
            // cout << "why1" << endl;
            ll lb=0, rb=hull.size()-1;
            // cout << lb << " " << rb << endl;
            while(lb<rb) {
                // cout << "why2" << endl;
                ll mb=(lb+rb)/2;
                if(hull[mb+1][1]>b[q[ix]][1]) {
                    rb=mb;
                    continue;
                }
                if(cmp(b[q[ix]], hull[mb], hull[mb+1])>0)
                    lb=mb+1;
                else
                    rb=mb;
                // cout << "why3 "  << lb << " " << rb << endl;
            }
            // cout << "why4 " << lb << endl;
            ar<ll, 2> t=cal_time(hull[lb], b[q[ix]]);
            ll x=std::__gcd(t[0], t[1]);
            ans[ix]={t[0]/x, t[1]/x};
            // cout << "why5 " << ans[ix][0] << " " << ans[ix][1] << endl;
        }
    }
    // cout << "hello1" << endl;
    // Case 2: a[q[i]][0] > a[i][0]
    hull.clear();
    for(ll i=0; i<n; ++i) {
         while(hull.size()) {
            if(a[i][1]>=hull.back()[1]) {
                hull.pop_back();
                continue;
            }
            if(hull.size()>=2&&cmp(a[i], hull[hull.size()-1], hull[hull.size()-2])>=0) {
                hull.pop_back();
                continue;
            }
            break;
        }
        hull.push_back(a[i]);
        ll ix=a[i][2];
        // cout << "height: " << a[i][0] << " o_index: " << ix << endl;
        // cout << "t_height: " << b[q[ix]][0] << " t_index: " << q[ix] << endl;
        // cout << "hull_size" << hull.size() << endl;
        if(b[q[ix]][0]>b[ix][0]) {
            if(b[q[ix]][1]>=hull[0][1]) {
                ans[ix]={-1, -1};
                continue;
            }
            ll lb=0, rb=hull.size()-1;
            while(lb<rb) {
                ll mb=(lb+rb)/2;
                if(hull[mb+1][1]<b[q[ix]][1]) {
                    rb=mb;
                    continue;
                }
                if(cmp(b[q[ix]], hull[mb], hull[mb+1])>0)
                    lb=mb+1;
                else
                    rb=mb;
            }
            // cout << " ller line: " << hull[lb][0] << " o_index: " << hull[lb][2] << endl;
            ar<ll, 2> t=cal_time(hull[lb], b[q[ix]]);
            ll x=std::__gcd(t[0], t[1]);
            ans[ix]={t[0]/x, t[1]/x};
        }
    }
    for(ll i=0; i<n; ++i) {
        if(ans[i][0]==-1)
            cout << -1 << endl;
        else
            cout << ans[i][0] << "/" << ans[i][1] << endl;
    }
}
