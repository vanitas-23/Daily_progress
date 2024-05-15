class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>inD(n);
        for(auto i:roads)
        inD[i[0]]++,inD[i[1]]++;
        unordered_map<int,long long>mp;
        priority_queue<pair<long long,int>>pq;
        for(int i=0;i<n;i++)
        pq.push({inD[i],i});
        int z=n;
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            mp[x.second]=z--;
        }
        long long res=0;
        for(auto i:roads)
        res+=(mp[i[0]]+mp[i[1]]);

        return res;
    }
};