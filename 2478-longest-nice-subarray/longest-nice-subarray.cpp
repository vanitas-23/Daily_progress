class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i=0;
        int j=0;
        vector<int>arr(32);
        while(j<n)
        {
            for(int k=0;k<32;k++)
            {
                if(nums[j]&(1<<k))
                arr[k]++;
            }
            for(int k=0;k<32;k++)
            {
                while(arr[k]>1)
                {
                    for(int k=0;k<32;k++)
                    {
                        if(nums[i]&(1<<k))
                        arr[k]--;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};