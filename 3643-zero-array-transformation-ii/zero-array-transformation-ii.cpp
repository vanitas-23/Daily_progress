class Solution {
public:
    bool f(int mid,vector<int> nums,vector<vector<int>>& q,int n)
    {
        vector<int>arr(n);
        for(int i=0;i<mid;i++)
        {
            arr[q[i][0]]+=q[i][2];
            if(q[i][1]+1<n)
            arr[q[i][1]+1]-=q[i][2];
        }
        for(int i=1;i<n;i++)
        arr[i]+=arr[i-1];
        for(int i=0;i<n;i++)
        {
            if(max(0,nums[i]-arr[i])>0)
            return 0;
        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int l=0;
        int r=q.size();
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(f(mid,nums,q,n))
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