class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>adj[n+1];
        map<pair<int,int>,int>mp;
        for(auto i:times)
        {
            adj[i[0]].push_back(i[1]);
            mp[{i[0],i[1]}]=i[2];
        }
        vector<int>dst(n+1,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dst[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            //cout<<x.second<<endl;
            for(auto i:adj[x.second])
            {
                //cout<<i<<" "<<x.second<<endl;
                if(dst[i]==-1)
                {
                    //cout<<i<<" "<<x.second<<endl;
                    dst[i]=x.first+mp[{x.second,i}];
                    pq.push({x.first+mp[{x.second,i}],i});
                }
                else if(dst[i]>x.first+mp[{x.second,i}])
                {
                    dst[i]=x.first+mp[{x.second,i}];
                    pq.push({x.first+mp[{x.second,i}],i});
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        if(dst[i]==-1)
        return -1;
        return *max_element(dst.begin(),dst.end());
    }
};