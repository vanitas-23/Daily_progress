class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        vector<int>pre(n,-1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            if(nums[j]%nums[i]==0)
            {
                if(cnt[i]+1>cnt[j])
                {
                    cnt[j]=cnt[i]+1;
                    pre[j]=i;
                }
            }
        }
        vector<int>mark(n);
        for(int i=n-1;i>=0;i--)
        {
            if(mark[i])
            continue;
            vector<int>x;
            int curr=i;
            while(curr!=-1)
            {
                x.push_back(nums[curr]);
                mark[curr]=1;
                curr=pre[curr];
            }
            if((int)x.size()>(int)ans.size())
            ans=x;
        }
        return ans;
    }
};