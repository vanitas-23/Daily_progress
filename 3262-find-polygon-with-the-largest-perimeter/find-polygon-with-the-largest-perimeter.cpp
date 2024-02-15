class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=-1;
        vector<long long>dm(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++)
            dm[i]+=dm[i-1];
        for(int i=2;i<n;i++)
        {
            if(dm[i-1]>nums[i])
                ans=dm[i];
        }
        return ans;
    }
};