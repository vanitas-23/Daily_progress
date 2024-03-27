class Solution {
public:
    bool check(vector<int>& nums,int k,int mid_sum)
    {
        int n=nums.size();
        int splits=1;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            
            curr+=nums[i];
            if(curr>mid_sum)
            splits++,curr=nums[i];
        }

        return splits<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=1e9;
        int ans=0;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(check(nums,k,mid))
            {
                ans = mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};