class Solution {
public:
    int limit;
    int memo[202][202][202][2];
    const int mod=1e9+7;
    long long dp(int zero,int one,int l,bool pvs){
        if(zero==0&&one==0)return 1;
        if(pvs!=-1&&memo[zero][one][l][pvs]!=-1)return memo[zero][one][l][pvs]%mod;
        long long ans=0;
        if(pvs==-1){
            if(zero)ans+=dp(zero-1,one,1,0);
            if(one)ans+=dp(zero,one-1,1,1);
        }else if(pvs==1){
            if(l+1>limit){
                if(zero)ans+=dp(zero-1,one,1,0);
            }else{
                if(one)ans+=dp(zero,one-1,l+1,1);
                if(zero)ans+=dp(zero-1,one,1,0);
            }
        }else{
            if(l+1>limit){
                if(one)ans+=dp(zero,one-1,1,1);
            }else{
                if(zero)ans+=dp(zero-1,one,l+1,0);
                if(one)ans+=dp(zero,one-1,1,1);
            }
        }
        if(pvs!=-1)memo[zero][one][l][pvs]=ans%mod;
        return ans%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo,-1,sizeof(memo));
        this->limit=limit;
        return dp(zero,one,0,-1)%mod;
    }
};