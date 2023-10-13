static int ___ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);return 0;}();

class Solution {
public:
    bool makeStringsEqual(string s, string target)
    {
        int a = 0;
        int b = 0;

        for(char i : s)
        {
            a += i == '1';
        }
        for(char i : target)
        {
            b += i == '1';
        }

        return a && b || !(a ^ b);
    }
};