class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        if(nums[0]!=0)
            ans++;
        for(int i=0;i<n;i++){
             if(nums[i]<i+1 && i+1<n  && nums[i+1]>i+1)
               ans++;
            else if(i==n-1 && nums[i]<i+1)
                ans++;
        }
          
        return ans;
    }
};