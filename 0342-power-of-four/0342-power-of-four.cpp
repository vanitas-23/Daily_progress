class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)
        return 0;
        int x=ffs(n);

        
        return (x%2) && __builtin_popcount(n)==1;
    }
};