class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(auto i:gifts)
        pq.push(i);
        while(k)
        {
            auto x=pq.top();
            pq.pop();
            pq.push(sqrt(x));
            k--;
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};