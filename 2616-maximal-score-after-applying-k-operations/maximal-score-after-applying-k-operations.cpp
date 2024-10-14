class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(int i:nums)
        pq.push(i);
        for(int i=0;i<k;i++)
        {
            long long x=pq.top();
            pq.pop();
            ans+=x;
            pq.push(ceil(x*1.0/3));
        }
        return ans;
    }
};