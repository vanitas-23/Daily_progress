class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(auto i:nums)
        {
            int x=i;
            int sum=0;
            while(x>0)
            {
                sum+=x%10;
                x/=10;
            }
            mp[sum].push(i);
            while(mp[sum].size()>2) mp[sum].pop();
        }
        int ans=-1;
        for(auto i:mp)
        {
            auto x=i.second;
            if(x.size()!=2) continue;
            int temp=x.top();
            x.pop();
            temp+=x.top();
            x.pop();
            ans=max(ans,temp);
        }
        return ans;
    }
};