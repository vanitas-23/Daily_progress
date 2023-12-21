class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        priority_queue<int>pq;
        for(auto i:points)
        pq.push(i[0]);

        int curr=pq.top();
        pq.pop();
        int ans=0;
        while(pq.size()){
            ans=max(ans,curr-pq.top());
            curr=pq.top();
            pq.pop();
        }
        return ans;
    }
};