#define word words
class Solution {
public:
    int f(int i,int n,vector<string>& word,int last,int first,vector<vector<vector<int>>>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i][last][first]!=-1)
        return dp[i][last][first];
        int op1 = 0;
        //cout<<i<<" "<<first<<" "<<last<<endl;
        if(last==words[i][0]-'a')
        op1=word[i].size()-1+f(i+1,n,words,words[i].back()-'a',first,dp);
        else
        op1=word[i].size()+f(i+1,n,words,words[i].back()-'a',first,dp);
        int op2 = 0;
        if(first==words[i].back()-'a')
        op2 = word[i].size()-1+f(i+1,n,words,last,words[i][0]-'a',dp);
        else
        op2=word[i].size()+f(i+1,n,words,last,words[i][0]-'a',dp);
        return dp[i][last][first]=min(op1,op2);
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        int n=words.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
        return f(1,n,words,words[0].back()-'a',words[0][0]-'a',dp)+word[0].size();
    }
};