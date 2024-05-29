class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=num1;
        int n=__builtin_popcount(num2);
        int m=__builtin_popcount(num1);
        for(int j=0;j<32;j++)
        {
            if(x&(1<<j))
            {
                if(m>n)
                {
                    x^=(1<<j);
                    m--;
                }
            }
        }
        for(int j=0;j<32;j++)
        {
            if(x&(1<<j))
            continue;
            
                if(m<n)
                {
                    x^=(1<<j);
                    n--;
                }
        }
        return x;
    }
};