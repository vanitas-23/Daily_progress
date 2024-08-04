class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>st;
        for(int i=0;i<n;i++)
        st.insert(i);
        vector<int>res;
        for(auto i:queries)
        {
            auto x=st.upper_bound(i[0]);
            auto y=st.lower_bound(i[1]);
            st.erase(x,y);
            res.push_back(st.size()-1);
        }
        return res;
    }
};