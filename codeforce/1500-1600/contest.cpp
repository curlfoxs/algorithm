#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

float a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    float misha=max(3*a/10, a-a/250*c);
    float vasya=max(3*b/10, b-b/250*d);
    if(misha==vasya)
        cout << "Tie";
    else if(misha<vasya)
        cout << "Vasya";
    else
        cout << "Misha";
}
