class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        int emp=0;
        while(numBottles>0)
        {
            ans+=numBottles;
            emp+=numBottles;
            numBottles=0;
            while(emp>=numExchange)
            {
                emp-=numExchange;
                numBottles++;
                numExchange++;
            }
            //cout<<ans<<" "<<numExchange<<" "<<emp<<" "<<numBottles<<endl;
        }
        return ans;
    }
};