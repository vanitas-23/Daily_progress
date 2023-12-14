class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        priority_queue<int,vector<int>,greater<int>>pq;

        int n=capacity.size();
        int ans=0;
        for(int i=0;i<n;i++){
        if(capacity[i]-rocks[i]==0)
        ans++;
        else
        pq.push(capacity[i]-rocks[i]);
        }
        while(a>0 && pq.size()>0){
            a-=pq.top();
            pq.pop();
            if(a>=0)
            ans++;
        }
        return ans;
    }
};