class Solution {
public:
    bool f(vector<int>& nums,int k,int mid_sum)
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
    int shipWithinDays(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=1e9;
        int ans=h;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(f(nums,k,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};