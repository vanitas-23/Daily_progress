class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        map<int,map<int,int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(nums[i]>0)
            {
                mp[cnt++][nums[i]%10]++;
                nums[i]/=10;
            }
        }
        long long ans=0;
        for(auto i:mp)
        {
            vector<long long>frq;
            for(auto x:i.second)
                frq.push_back(x.second);
            int m=frq.size();
            vector<long long>acc=frq;
            for(int j=m-2;j>=0;j--)
                frq[j]+=frq[j+1];
            for(int j=0;j<m-1;j++)
                ans+=acc[j]*frq[j+1];
        }
        return ans;
    }
};