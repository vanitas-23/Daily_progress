class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans=0;
        int curr=0;
        for(auto i:nums)
        {
            if(i>=curr)
            {
                curr=i;
                ans++;
            }
        }
        return ans;
    }
};