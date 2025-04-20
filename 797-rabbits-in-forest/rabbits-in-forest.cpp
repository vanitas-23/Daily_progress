class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int res=0;
        unordered_map<int,int>mp;
        for(auto i:ans)
        {
            if(mp.find(i)==mp.end())
            {
                res+=(i+1);
                if(i!=0)
                mp[i]=i;
            }
            else
            {
                mp[i]--;
                if(mp[i]==0)
                mp.erase(i);
            }
        }
        return res;
    }
};