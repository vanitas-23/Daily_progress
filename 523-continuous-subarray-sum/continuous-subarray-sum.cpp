class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long,int>mp;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            long long rem=sum%k;
            cout<<rem<<endl;
            if(rem==0 && i>=1)
            return 1;
            if(mp.find(rem)!=mp.end()){
            if (i-mp[rem]>1)
            return 1;
            }
            else
            mp[rem]=i;
        }
        
        return 0;
    }
};