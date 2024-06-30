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
            auto it = upper_bound(mp[nxt].begin(), mp[nxt].end(), idx);
            if (it == mp[nxt].end())
                break;
            idx = *it;
            flag = !flag;
        }
        else
        {
            auto it = upper_bound(mp[cur].begin(), mp[cur].end(), idx);
            if (it == mp[cur].end())
                break;
            idx = *it;
            flag = !flag;
        }
        res++;
    }
    return res;
}
    int maximumLength(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        mp[arr[i]%k].push_back(i);
        int ans=0;
        for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
        {
            if(i==j)
            continue;
            if(mp[i].size()==0 || mp[j].size()==0)
            continue;
            ans=max(ans,func(mp[i][0],i,j,mp));
        }
        for(auto i:mp)
        ans=max(ans,(int)i.second.size());
        return ans;
    }
};