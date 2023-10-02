class Solution {
public:
    bool winnerOfGame(string s) {
        int a=0,b=0;
        int n=s.size();
        for(int i=0;i<n-2;i++){
            if(s[i]=='A' && s[i+1]=='A' && s[i+2]=='A')
            a++;
            else if(s[i]=='B' && s[i+1]=='B' && s[i+2]=='B')
            b++;
        }
        return a>b;
    }
};