class Solution {
public:
    vector<vector<int>> dp;
    int f(string &s1, string &s2, int &x, int l, int r) {
        if(l>=r) return 0;
        if(s1[l]==s2[l]) return f(s1, s2, x, l+1, r);
        if(s1[r]==s2[r]) return f(s1, s2, x, l, r-1);
        if(dp[l][r]!= -1) return dp[l][r];
        int option1= min(x, r-l) + f(s1, s2, x, l+1, r-1);
        
        int l1= l+1;
        while(s1[l1]==s2[l1]) l1++;
        int option2= min(x, l1-l) + f(s1, s2, x, l1+1, r);
        int r1= r-1;
        while(s1[r1]==s2[r1]) r1--;
        int option3= min(x, r-r1) + f(s1, s2, x, l, r1-1);
        return dp[l][r]= min(option1, min(option2, option3));
    }
    int minOperations(string s1, string s2, int x) {
        dp.resize(501, vector<int>(501, -1));
        int count= 0;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) count++;
        }
        if(count%2 != 0 ) return -1;
        if(count == 0) return 0;
        return f(s1, s2, x, 0, s1.length()-1);
    }
};