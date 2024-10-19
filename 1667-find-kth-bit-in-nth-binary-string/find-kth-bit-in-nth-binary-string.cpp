class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)
        return '0';
        int len=(1<<n)-1;
        int mid=(len+1)/2;
        if(k==mid)
        return '1';
        if(k<mid)
        return findKthBit(n-1,k);
        return findKthBit(n-1,len+1-k)=='0'?'1':'0';
    }
};