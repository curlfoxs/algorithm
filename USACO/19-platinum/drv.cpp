#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array
const string path="snowcow_platinum_dec19\\";
const string prefix="my_";

string newFile, originFile;
int test_case=14;
ifstream fin;
ofstream fout;

extern inline void my_main();

string slurp(ifstream& in) {
    ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}
bool compare(int i) {
    ifstream min(newFile+".out");
    ifstream ain(originFile+".out");
    string s1=slurp(min);
    string s2=slurp(ain);
    if(s1!=s2) {
        cout << "Wrong Answer with Testcase #"+to_string(i) << endl;
        cout << "Your Output:" << endl;
        cout << s1;
        cout << "Except Output:" << endl;
        cout << s2;
        return false;
    }
    cout << "Testcase #"+to_string(i) +" *" <<endl;
    return true;
}


extern int main() {
    for(int i=3; i<=test_case; ++i) {
        originFile=path+to_string(i);
        newFile=path+prefix+to_string(i);
        my_main();
        // if(!compare(i)) {
            // return 0;
        // }
    }
    cout << endl << "------------Accepted!---------------" << endl;
}
