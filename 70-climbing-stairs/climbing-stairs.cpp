class Solution {
public:
    int climbStairs(int n) {
        int x=1;
        int y=2;
        if(n==1)
        return x;
        for(int i=2;i<n;i++)
        {
            int z=x+y;
            x=y;
            y=z;
        }
        return y;
    }
};