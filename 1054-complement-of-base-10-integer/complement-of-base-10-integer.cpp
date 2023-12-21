class Solution {
public:
    
    int bitwiseComplement(int n) {
        if(n==0)
        return 1;
        int i=31;
        for(;i>=0;i--)
        if((n&(1<<i))==(1<<i))
        break;

        for(int j=0;j<=i;j++)
        n^=(1<<j);

        return n;

    }
};