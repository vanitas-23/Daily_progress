#define ll long long
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& frq) {
        int n=nums.size();
        multiset<ll>st;
        unordered_map<int,ll>mp;
        vector<ll>ans;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]+=frq[i];
                st.insert(frq[i]);
                ans.push_back(*st.rbegin());
                continue;
            }
            ll prv=mp[nums[i]];
            auto it=st.lower_bound(prv);
            st.erase(it);
            mp[nums[i]]+=frq[i];
            st.insert(mp[nums[i]]);
            ans.push_back(*st.rbegin());
        }
        return ans;
    }
};