class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        map<int,string,greater<int>> r;
        string ss="";

        for(auto a : s)
            mp[a]++;

        for(auto a : mp)
            r[a.second]+=a.first;

        for (auto [f, chars] : r) {
            for (auto c : chars) ss.append(f, c);
        }
        return ss;
    }
};