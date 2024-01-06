class Solution {
public:
    int f(vector<int>& st,vector<int>& et,vector<int>& val, int i,int n,int k,vector<vector<int>>&  dp){
        if(k==0)
        return 0;
        if(i==n)
        return 0;
        if(dp[i][k]!=-1)
        return dp[i][k];
        int taken=val[i]+f(st,et,val,upper_bound(st.begin(),st.end(),et[i])-st.begin(),n,k-1,dp);
        int ntaken=f(st,et,val,i+1,n,k,dp);
        return dp[i][k]=max(ntaken,taken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<int>st(n);
        vector<int>et(n);
        vector<int>val(n);
        for(int i=0;i<n;i++){
            st[i]=events[i][0];
            et[i]=events[i][1];
            val[i]=events[i][2];
        }
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(st,et,val,0,n,k,dp);
    }
};