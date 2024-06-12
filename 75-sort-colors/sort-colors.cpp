class Solution {
public:
    void sortColors(vector<int>& nums) {
        int _0=0,_1=0,_2=0;
        for(int i:nums)
        if(i==0)
        _0++;
        else if(i==1)
        _1++;
        else
        _2++;
        for(int& i:nums)
        {
            if(_0>0)
            i=0,_0--;
            else if(_1>0)
            i=1,_1--;
            else
            i=2;
        }
    }
};