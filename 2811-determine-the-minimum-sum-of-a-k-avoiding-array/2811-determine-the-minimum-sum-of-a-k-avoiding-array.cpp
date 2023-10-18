class Solution {
public:
    int minimumSum(int n, int k) {
       if(k/2>=n) return n*(n+1)/2;
       else return (n + (k-1)/2)*(n + (k-1)/2+ 1)/2 - (k-1)*(k-1+1)/2 + (k/2)*(k/2+1)/2;
    }
};