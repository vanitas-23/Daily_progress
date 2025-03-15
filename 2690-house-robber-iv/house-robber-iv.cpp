class Solution {
public:
    bool check(vector<int>& nums,int k,int mid,int n)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=mid)
            i++,k--;
            if(k==0)
            return 1;
        }
        return 0;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=1e9+1;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(nums,k,mid,n))
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};