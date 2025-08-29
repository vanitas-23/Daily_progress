class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans=0;
        long long odds=ceil(m*1.0/2);
        long long evens=(m/2);
        for(int i=1;i<=n;i++)
            if(i%2)
                ans+=evens;
            else
                ans+=odds;
        
        return ans;
    }
};