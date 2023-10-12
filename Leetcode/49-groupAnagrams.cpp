class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> mp;
        for(int i=0; i<strs.size(); ++i) {
            array<int, 26> cc={};
            for(char d : strs[i])
                ++cc[d-'a'];
            mp[cc].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto p : mp)
            ans.push_back(p.second);
        return ans;
    }
};
