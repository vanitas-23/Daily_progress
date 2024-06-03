class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        priority_queue<pair<int,int>>pq;
        int n=costs.size();
        vector<int>vis(n);
        for(int i=0;i<can;i++)
        {
            if(!vis[i])
            pq.push({-costs[i],-i});
            vis[i]=1;
        }
        for(int i=n-1;i>n-1-can;i--)
        {
            if(!vis[i])
            pq.push({-costs[i],-i});
            vis[i]=1;
        }
        int st=can;
        int end=n-1-can;
        cout<<st<<" "<<end<<endl;
        long long ans=0;
        while(k--)
        {
            auto x=pq.top();
            pq.pop();
            //cout<<x.first<<" ";
            ans=ans-x.first;
            if(-x.second<st)
            {
                if(st<n && !vis[st]){
                pq.push({-costs[st],-st});
                vis[st]=1;
                //cout<<st<<" ";
                st++;
                }
            }
            else
            {
                if(end>=0 && !vis[end])
                {
                    pq.push({-costs[end],-end});
                    vis[end]=1;
                    //cout<<end<<" ";
                    end--;
                }
            }
        }
        return ans;
    }
};