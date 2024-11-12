class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int>mp;
        for(auto i:items)
        mp[i[0]]=max(mp[i[0]],i[1]);
        vector<int>ans;
        auto it=mp.begin();
        auto pre=it;
        it++;
        while(it!=mp.end())
        {
            it->second=max(it->second,pre->second);
            pre++;
            it++;
        }
        for(int i:queries)
        {
            auto it=mp.upper_bound(i);
            if(it==mp.begin())
            {
                ans.push_back(0);
                continue;
            }
            it--;
            ans.push_back(it->second);
        }
        return ans;
    }
};