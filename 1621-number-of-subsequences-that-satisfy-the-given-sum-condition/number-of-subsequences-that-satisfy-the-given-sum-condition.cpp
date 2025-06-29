const int MOD=1e9+7;
class Solution {
public:
    int mod_expo(int a,int b)
    {
        if(b==0)
        return 1;
        if(b==1)
        return a;
        long long x=mod_expo(a,b/2);
        x=(x%MOD * x%MOD+MOD)%MOD;
        if(b%2)
        return (x % MOD * a % MOD + MOD)%MOD;
        return x;
    }
    int numSubseq(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=0;
       int n=nums.size();
       for(int i=0;i<n;i++)
        {
            int id=upper_bound(nums.begin(),nums.end(),-nums[i]+k)-nums.begin();
            id--;
            if(id>=i)
            ans=(ans%MOD+mod_expo(2,id-i))%MOD;
        }
        return ans;
    }
};