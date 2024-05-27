class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int i=0;
        int n=nums.size();
        vector<int>arr(32);
        int j=0;
        while(j<n)
        {
            for(int x=31;x>=0;x--)
            if(nums[j]&(1<<x))
            arr[x]++;
            
            for(int x=31;x>=0;x--)
            {
                while(arr[x]>1)
                {
                    for(int z=31;z>=0;z--)
                    if(nums[i]&(1<<z))
                    arr[z]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};