class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans=0;
        long long sm=accumulate(nums.begin(),nums.end(),0ll);
        long long temp=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            temp+=nums[i];
            if(2*temp>=sm) ans++;
        }
        return ans;
    }
};