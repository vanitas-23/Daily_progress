class Solution {
public:
    int pivotInteger(int n) {
        int x= n*(n+1)/2;
        //cout<<sqrt(x)<<" ";
        int y=sqrt(x);
        if(y*y==x)
            return y;
        return -1;
    }
};