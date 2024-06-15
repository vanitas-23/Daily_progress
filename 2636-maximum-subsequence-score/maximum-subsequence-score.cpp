class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        arr.push_back({nums2[i],nums1[i]});
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<n;i++)
        nums2[i]=arr[i].first,nums1[i]=arr[i].second;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        long long temp=0;
        for(int i=0;i<k;i++)
        pq.push(nums1[i]),temp+=nums1[i];
        long long ans=temp*nums2[k-1];
        for(int i=k;i<n;i++)
        {
            pq.push(nums1[i]);
            auto x=pq.top();
            pq.pop();
            temp+=nums1[i];
            temp-=x;
            ans=max(ans,temp*nums2[i]);
        }
        return ans;
    }
};