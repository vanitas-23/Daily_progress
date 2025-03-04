class Solution {
public:

    bool checkPowersOfThree(int n) {
        while(n>0)
        {
            int x=n%3;
            if(x==2)
            return 0;
            n/=3;
        }
        return 1;
    }
};