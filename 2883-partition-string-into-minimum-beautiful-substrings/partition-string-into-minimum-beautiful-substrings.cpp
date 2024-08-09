class Solution {
public:
    bool is(int x, long int y)
{
    if (x == 1)
        return (y == 1);
    long int pow = 1;
    while (pow < y)
        pow *= x;
    return (pow == y);
}
    int con(string s) {
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                num |= (1 << (n - i - 1));
        }
        return num;
    }
    int f(int i, int n, string s) {
        if (i == n)
            return 0;
        if(s[i]=='0')
        return 1e9;
        string curr = "";
        int ans=1e9;
        for (int j = i; j < n; j++) {
            curr += s[j];
            int x = con(curr);
            if (is(5,x))
            ans=min(ans,1+f(j+1,n,s));
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        int x = f(0,n,s);
        if(x>=1e9)
        return -1;
        return x;
    }
};