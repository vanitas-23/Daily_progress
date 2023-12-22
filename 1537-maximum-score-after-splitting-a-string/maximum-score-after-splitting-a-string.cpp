class Solution {
public:
    int maxScore(string s) {
        int zer=0,on=0;
        for(char c:s)
        if(c=='0') zer++;
        else on++;
        int c=0;
        int d=0;
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')
            c++;
            else
            d++;
            ans=max(ans,c+on-d);
        }
        return ans;
    }
};