class Solution {
public:
    int countOrders(int n) {
        int m=1e9+7;
        int ans=1;
        for(int i=2*n;i>0;i-=2)
        {
            long long x = i*1ll*(i-1)/2;
            ans=((ans%m)*(x))%m;
        }
        return ans%m;
    }
};