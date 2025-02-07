class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>coCount;
        unordered_map<int,int>co;
        vector<int>ans;
        for(auto i:queries)
        {
            if(co.find(i[0])==co.end())
            {
                co[i[0]]=i[1];
                coCount[i[1]]++;
            }
            else
            {
                coCount[co[i[0]]]--;
                if(coCount[co[i[0]]]==0)
                coCount.erase(co[i[0]]);
                co[i[0]]=i[1];
                coCount[i[1]]++;
            }
            ans.push_back(coCount.size());
        }
        return ans;
    }
};