class Solution {
public:
    int f(int i,int n,vector<int>& nums, int firstLen, int secondLen,int fst,int snd,vector<vector<vector<int>>>& dp)
    {
        if(i>=n)
        return 0;
        if(dp[i][fst][snd]!=-1)
        return dp[i][fst][snd];
        int ntaken = f(i+1,n,nums,firstLen,secondLen,fst,snd,dp);
        int take1=0;
        int take2=0;
        if(fst==0 && i+firstLen-1 < n)
        {
            int sum=0;
            for(int j=i;j<=i+firstLen-1;j++)
            sum+=nums[j];
            take1=sum+f(i+firstLen,n,nums,firstLen,secondLen,1,snd,dp);
        }
        
        if(snd==0 && i+secondLen-1 < n)
        {
            int sum=0;
            for(int j=i;j<=i+secondLen-1;j++)
            sum+=nums[j];
            take2=sum+f(i+secondLen,n,nums,firstLen,secondLen,fst,1,dp);
        }

        return dp[i][fst][snd]=max({ntaken,take1,take2});
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,n,nums,firstLen,secondLen,0,0,dp);
    }
};