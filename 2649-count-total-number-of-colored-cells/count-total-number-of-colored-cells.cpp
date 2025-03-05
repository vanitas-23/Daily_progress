class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        if(n==1)
        return 1;
        int x=1;
        for(int i=1;i<=n;i++)
        {
            if(i<n) ans+=2*x;
            else ans+=x;
            x+=2;
        }
        return ans;
    }
};