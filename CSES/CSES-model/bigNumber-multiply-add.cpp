class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size(), n2=num2.size();
        vector<int> ans(n1+n2, 0);
        for(int i=n1-1; ~i; --i)
            for(int j=n2-1; ~j; --j) {
                ans[i+j+1]+=(int)(num1[i]-'0')*(int)(num2[j]-'0');
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
            
        string res;
        for(int i=0; i<ans.size(); ++i) {
            if(!i)
                while(i<ans.size()-1&&ans[i]==0) ++i;
            res+=(char)(ans[i]+'0');
        }
        return res;
    }
};



string add(string num1, string num2) {
    if(num1.size()<num2.size())
        return add(num2, num1);
    int cn=0;
    string ans;
    for(int i=num2.size()-1, j=num1.size()-1; ~i; --i,--j) {
        cn+=(int)(num2[i]-'0')+(int)(num1[j]-'0');
        num1[j]=(cn%10+'0');
        cn/=10;
    }
    for(int i=num1.size()-num2.size()-1; cn&&i>=0; --i) {
        cn+=(int)(num1[i]-'0');
        num1[i]=(cn%10+'0');
        cn/=10;
    }
    if(cn)
        num1="1"+num1;
    return num1;
}

string add(string num1, string num2) {
    int n1=num1.size(), n2=num2.size();
    if(n1<n2) return add(num2, num1);
    vector<int> ans(n1+1, 0);
    for(int i=n1-1, j=n2-1; ~j; --i, --j) {
        ans[i+1]+=(int)(num1[i]-'0')+(int)(num2[j]-'0');
        ans[i]=ans[i+1]/10;
        ans[i+1]%=10;
    }
    for(int i=n1-n2-1; ~i; --i) {
        ans[i+1]+=(int)(num1[i]-'0');
        ans[i]=ans[i+1]/10;
        ans[i+1]%=10;
    }
    string res;
    for(int i=0; i<ans.size(); ++i) {
        if(!)
            while(i<ans.size()-1&&ans[i]==0) ++i
        res+=to_string(a);
    }
    return res;
}
