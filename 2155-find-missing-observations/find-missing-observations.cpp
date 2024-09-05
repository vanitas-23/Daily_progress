class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int x=accumulate(rolls.begin(),rolls.end(),0);
        int m=rolls.size();
        int req=mean*(n+m)-x;
        if(req<=0)
        return {};
        if(req>6*n)
        return {};
        int avg=req/n;
        int rem=req%n;
        
        if(avg==6 && rem>0)
        return {};
        vector<int>ans(n,avg);
        for(int i=0;i<n && rem>0 ;i++)
        {
            int pre=ans[i];
            ans[i]=min(6,pre+rem);
            rem=rem-(ans[i]-pre);
        }
        for(int i:ans)
        if(i<=0)
        return {};
        return ans;
    }
};