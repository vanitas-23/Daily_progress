class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int i:arr)
        mp[i]++;

        for(auto i:mp)
        st.insert(i.second);

        return st.size()==mp.size();
    }
};