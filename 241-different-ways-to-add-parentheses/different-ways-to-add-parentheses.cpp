class Solution {
public:
    vector<int> f(int i,int n,string exp,vector<vector<vector<int>>>& dp)
    {
        if(dp[i][n].size()!=0)
        return dp[i][n];
        vector<int>arr;
        bool op=0;
    
        for(int j=i;j<n;j++)
        {
            if(exp[j]=='+' || exp[j]=='-' || exp[j]=='*')
            {
                op=1;
                auto x=f(i,j,exp,dp);
                auto y=f(j+1,n,exp,dp);
                for(auto l:x)
                for(auto r:y)
                {
                    if(exp[j]=='+')
                    arr.push_back(l+r);
                    else if(exp[j]=='-')
                    arr.push_back(l-r);
                    else
                    arr.push_back(l*r);
                }
            }
        }
        if(op==0)
        arr.push_back(stoi(exp.substr(i,n-i)));
        return dp[i][n]=arr;
    }
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1));
        return f(0,n,exp,dp);
    }
};