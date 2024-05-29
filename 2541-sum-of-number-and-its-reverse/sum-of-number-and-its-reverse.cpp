class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        int y,x;
        for(int i = 0; i <= 1e5; i++){
            x = i,y = 0;
            while(x){
                y = y*10+(x%10);
                x /= 10;
            }
            if(i+y==num){
                return true;
            }
        }
        return false;
    }
};