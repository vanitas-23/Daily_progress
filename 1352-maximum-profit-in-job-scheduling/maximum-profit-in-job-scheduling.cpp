class Solution {
public:
    int f(vector<int>& st, vector<int>& et, vector<int>& profit,int i,int n,vector<int>& dp){
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
    int taken=profit[i]+f(st,et,profit,lower_bound(st.begin(),st.end(),et[i])-st.begin(),n,dp);
    int ntaken=f(st,et,profit,i+1,n,dp);

    return dp[i]=max(taken,ntaken);
    }
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        
        int n=st.size();
        vector<pair<pair<int,int>,int>>arr;
        for(int i=0;i<n;i++)
        arr.push_back({{st[i],et[i]},{i}});

        sort(arr.begin(),arr.end());
        vector<int>pf(n);
        for(int i=0;i<n;i++){
        st[i]=arr[i].first.first;
        et[i]=arr[i].first.second;
        pf[i]=profit[arr[i].second];
        }
        profit=pf;
        vector<int>dp(n,-1);
        return f(st,et,profit,0,n,dp);
    }
};