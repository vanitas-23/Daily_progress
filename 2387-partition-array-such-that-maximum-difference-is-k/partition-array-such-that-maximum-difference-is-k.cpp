class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
       int req=0;
       priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(pq.size()){
            int curr=pq.top();
            pq.pop();
            while(pq.top()<=curr+k && pq.size()>0)
            pq.pop();
            req++;
        }
        return req;
    }
};