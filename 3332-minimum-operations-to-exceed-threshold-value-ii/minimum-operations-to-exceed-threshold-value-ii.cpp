class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i:nums)
            pq.push(i);
        int ans=0;
        while(pq.size()>=2)
        {
            long long x=pq.top();
            pq.pop();
            if(x>=k)
                break;
            
            long long y=pq.top();
            
            pq.pop();
            
         
            pq.push(min(x,y)*2+max(x,y));
            ans++;
        }
        return ans;
    }
};