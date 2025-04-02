class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>pre(n),suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)
            suff[i]=max(suff[i+1],nums[i]);
        long long res=0;
        for(int i=1;i<n-1;i++)
            res=max(res,(pre[i-1]-nums[i]*1LL)*suff[i+1]);
        
        return res;
    }
};