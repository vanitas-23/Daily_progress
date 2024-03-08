class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n=hand.size();
        if(n%gs!=0)
        return 0;
        map<int,int>mp;
        for(int i:hand)
        mp[i]++;

       while(!mp.empty())
       {
           int curr=mp.begin()->first;
        //   cout<<curr<<" ";
           for(int i=0;i<gs;i++)
           if(mp[curr+i]==0)
           return 0;
           else if(mp[curr+i]==1)
           mp.erase(curr+i);
           else
           mp[curr+i]--;
           
       }
       return true;
    }
};