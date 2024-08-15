class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int>st;
        int n=nums.size();
        for(int i=x;i<n;i++)
        st.insert(nums[i]);
        int j=x;
        int ans=1e9;
        for(int i=0;i<n-x;i++)
        {
            auto it=st.lower_bound(nums[i]);
            if(it!=st.end())
            ans=min(ans,abs(nums[i]-*it));
            if(it!=st.begin())
            {
                it--;
                ans=min(ans,abs(nums[i]-*it));
            }
            st.erase(st.lower_bound(nums[i+x]));
        }
        return ans;
    }
};