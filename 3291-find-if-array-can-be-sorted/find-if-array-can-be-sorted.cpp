class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n=nums.size();
        int mx=-1;
        int mn=(1<<8)+1;
        int bts=-1;
        for(int i=0;i<n;i++)
        {
            int curr=__builtin_popcount(nums[i]);
            if(bts==-1)
            {
                mx=max(mx,nums[i]);
                mn=min(mn,nums[i]);
                bts=curr;
                continue;
            }
            if(bts==curr)
            {
                mx=max(mx,nums[i]);
                mn=min(mn,nums[i]);
            }
            else
            {
                arr.push_back({mx,mn});
                mn=nums[i];
                mx=nums[i];
                bts=curr;
            }
        }
        arr.push_back({mx,mn});
        int m=arr.size();
        for(int i=1;i<m;i++)
        if(arr[i-1].first>arr[i].second)
        return 0;
        return 1;
    }
};