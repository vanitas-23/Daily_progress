class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2=n/m;
        num2=(num2)*(num2+1)/2;
        num2*=m;
        return n*(n+1)/2-2*num2;
    }
};