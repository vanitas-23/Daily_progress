class Solution {
public:
    int func(int idx, int cur, int nxt, unordered_map<int, vector<int>>& mp)
{
    int res = 1;
    bool flag = 0;
    while (true)
    {
        if (!flag)
        {
            auto it = lower_bound(mp[nxt].begin(), mp[nxt].end(), idx);
            if (it == mp[nxt].end())
                break;
            idx = *it;
            flag = !flag;
        }
        else
        {
            auto it = lower_bound(mp[cur].begin(), mp[cur].end(), idx);
            if (it == mp[cur].end())
                break;
            idx = *it;
            flag = !flag;
        }
        res++;
    }
    return res;
}
    int maximumLength(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        mp[arr[i]%2].push_back(i);
        int ans=max(mp[0].size(),mp[1].size());
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                if(i==j)
                    continue;
                if(mp[i].size()==0 || mp[j].size()==0)
                continue;
                ans=max(ans,func(mp[i][0],i,j,mp));
            }
        return ans;
    }
};