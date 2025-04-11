class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int m=n;
        nums.push_back(0);
        for(int i=0;i<n;i++)
        nums.push_back(nums[i]);
        n=nums.size();
        for(int i=1;i<n;i++)
        nums[i]+=nums[i-1];
        unordered_map<int,int>mp;
        int ans=m+1;
        for(int i=0;i<n;i++)
        {
            int req=nums[i]-x;
            if(mp.find(req)!=mp.end())
            {
                int j=mp[req];
                //cout<<i<<" "<<j<<endl;
                if((i>m && j<m))
                ans=min(ans,i-j-1);
                else if(i+1==m || j==m)
                ans=min(ans,i-j);
            }
            mp[nums[i]]=i;
        }
        return ans==m+1?-1:ans;
    }
};