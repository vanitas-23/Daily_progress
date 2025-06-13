class Solution {
public:
    bool f(int mid,int n,vector<int>& nums,int p)
    {
        int i=0;
        while(i<n-1)
        {
            if(nums[i+1]-nums[i]<=mid)
            p--,i++;
            if(p==0)
            return 1;
            i++;
        }
        return 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)
        return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=nums[n-1]-nums[0];
        int ans=r;
        while(l<=r)
        {
            int mid=(r-(r-l)/2);
            if(f(mid,n,nums,p))
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