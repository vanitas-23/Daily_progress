class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>res;
        int n=s.size();
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            continue;
            else
            res.push_back({j,i-1}),j=i;
        }
        res.push_back({j,n-1});
        vector<vector<int>>ans;
        for(auto i:res)
        if(i[1]-i[0]>=2)
        ans.push_back(i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};