class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int,vector<int>,greater<int>>q;
        
        int n=dist.size();
        for(int i=0;i<n;i++)
        q.push(ceil(1.0*dist[i]/speed[i]));
        int cnt=0;
        int k=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            if(cnt>=x)
            return cnt;
            cnt++;
            k++;
        }
        return cnt;
    }
};