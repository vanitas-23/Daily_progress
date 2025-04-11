class Solution {
public:
    int mod_expo(int a,int b,const int& MOD)
    {
        if(b==0)
        return 1;
        if(b==1)
        return a;
        long long x=mod_expo(a,b/2,MOD);
        x=(x%MOD * x%MOD+MOD)%MOD;
        if(b%2)
        return (x % MOD * a % MOD + MOD)%MOD;
        return x;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        const int MOD=1e9+7;
        while(i<=j)
        {
            if(nums[i]+nums[j]>target)
            j--;
            else
            {
                ans=(ans%MOD+mod_expo(2,j-i,MOD)%MOD)%MOD;
                i++;
            }
        }
        return ans;
    }
};