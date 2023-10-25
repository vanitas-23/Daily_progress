class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
        return 0;
        int x=1<<(n-1);
        
        if(k==x)
        return n%2==0;

        if(k>x)
        return !kthGrammar(n-1,k%x);

        return kthGrammar(n-1,k%x);

    }
};