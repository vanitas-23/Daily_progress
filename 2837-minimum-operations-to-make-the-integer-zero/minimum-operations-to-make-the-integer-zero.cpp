class Solution {
public:
    int makeTheIntegerZero(int n1, int n2) {
        for(int k=1;k<=32;k++)
        {
            if(1ll*n1-k*1ll*n2<=0) break;
            if(__builtin_popcountl(1ll*n1-k*1ll*n2)<=k && k<=(1ll*n1-k*1ll*n2))
            return k;
        }
        return -1;
    }
};