class Solution {
public:
    string maximumOddBinaryNumber(string s) {
     int cnt=0;
        for(char c:s)
            if(c=='1')
                cnt++;
        int n=s.size();
        string res(n,'0');
        res[n-1]='1';
        cnt--;
        for(int i=0;i<cnt;i++)
            res[i]='1';
        return res;
    }
};