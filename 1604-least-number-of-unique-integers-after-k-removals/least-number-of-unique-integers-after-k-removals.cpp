class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i:arr)
        mp[i]++;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:mp)
        pq.push(i.second);
        int ans=mp.size();
        while(!pq.empty() && k>0)
        {
            auto x=pq.top();
            pq.pop();
            if(x>k)
            {
                return ans;
            }
            k-=x;
            ans--;
        }
       return ans;
    }
};