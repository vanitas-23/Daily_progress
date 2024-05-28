class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mp;
        for(auto i:intervals){
        mp[i[0]]++;
        mp[i[1]+1]--;
        }
        int ans=0;
        int temp=0;
        for(auto i:mp)
        {
            temp+=i.second;
            ans=max(temp,ans);
        }
        return ans;
    }
};