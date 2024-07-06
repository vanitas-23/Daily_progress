class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=(time/(n-1))%2;
        int pos=time%(n-1);
        if(dir)
        return n-pos;
        return pos+1;
    }
};