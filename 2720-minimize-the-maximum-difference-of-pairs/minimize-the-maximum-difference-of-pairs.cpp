class Solution {
public:
    bool can(vector<int>& nums,int mid,int p,int n)
    {
        int cnt=0;
        int i=0;
        while(i<n-1)
        {
            if(nums[i+1]-nums[i]<=mid)
            cnt++,i++;
            i++;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=nums.back()-nums[0];
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(can(nums,mid,p,n))
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