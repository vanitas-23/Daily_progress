class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        auto x = times;
        sort(x.begin(), x.end());

        int n = times.size();
        int lst=x.back()[1];
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        pq.push(i);
        unordered_map<int,pair<int,int>>arr;
        map<int,vector<int>>dep;
        for(int i=0;i<n;i++)
        arr[times[i][0]]={times[i][1],i};
        vector<int>ans(n);
        for(int i=1;i<=lst;i++)
        {
            if(dep.find(i)!=dep.end())
            {
                for(auto j:dep[i])
                pq.push(j);
            }
            if(arr.find(i)!=arr.end())
            {
                ans[arr[i].second]=pq.top();
                dep[arr[i].first].push_back(pq.top());
                pq.pop();;
            }
            
        }
        return ans[t];
    }
};