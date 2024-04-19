class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int car=0;
        for(int i=0;i<=31;i++)
        {
            if(a&(1<<i))
            {
                if(b&(1<<i))
                {
                    if(car==1)
                    ans|=(1<<i);
                    car=1;
                }
                else
                {
                  if(car==1)
                  car=1;
                  else
                  ans|=(1<<i);
                }
            }
            else{
                if(b&(1<<i))
                {
                    if(car==1)
                    car=1;
                    else
                    ans|=(1<<i);
                }
                else
                {
                    if(car)
                    ans|=(1<<i);
                    car=0;
                }
            }
        }
        return ans;
    }
};