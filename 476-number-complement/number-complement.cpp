class Solution {
public:
    int findComplement(int num) {
        int ind=-1;
        for(int i=31;i>=0;i--)
        if(num & (1<<i)){
        ind=i;break;}
        for(int i=0;i<=ind;i++)
        {
            num=num^(1<<i);
        }
        return num;

    }
};