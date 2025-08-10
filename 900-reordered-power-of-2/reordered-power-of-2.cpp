class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        vector<int>dg;
        while(n>0)
        {
            dg.push_back(n%10);
            n/=10;
        }
        int mask=0;
        queue<pair<int,int>>q;
        q.push({mask,0});
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            int mm=x.first;
            int nn=x.second;
            if(__builtin_popcount(mm)==dg.size())
            if(__builtin_popcount(nn)==1) return 1;
            for(int i=0;i<dg.size();i++)
            {
                if(mm&(1<<i)) continue;
                if(nn==0 && dg[i]==0) continue;
                mm^=(1<<i);
                q.push({mm,nn*10+dg[i]});
                mm^=(1<<i);
            }
        }
        return 0;
    }
};