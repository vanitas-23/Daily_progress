class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>tot;
        unordered_map<int,int>curr;
        int n = nums.size();
        for(auto i:nums)
        tot[i]++;
        int mxE=0;
        int mxF=0;
        for(int i=0;i<n;i++)
        {
            curr[nums[i]]++;
            if(mxF<curr[nums[i]])
            {
                mxF=curr[nums[i]];
                mxE=nums[i];
            }
            int frq = tot[mxE]-curr[mxE];
            if(curr[mxE]>(i+1)/2 && frq>(n-i-1)/2)
            return i;
        }
        return -1;
    }
};