class Solution {
public:
    int m=1e9+7;
    int maximumXorProduct(long long a, long long b, int n) {
       for(int i=n-1;i>=0;i--){
           if(a>b)
           swap(a,b);

           int b1=(a>>i)&1;


           if(!b1){
               a^=(1LL<<i);
               b^=(1LL<<i);
           }
       }
       return ((a%m)*1LL*(b%m))%m;
    }
};