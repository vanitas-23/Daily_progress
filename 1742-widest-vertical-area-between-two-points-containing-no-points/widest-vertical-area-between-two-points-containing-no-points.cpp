class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>st;
        
        for(auto i:points)
        st.insert(i[0]);

        vector<int>pts(st.begin(),st.end());
        int ans=0;
        for(int i=1;i<pts.size();i++)
        ans=max(ans,pts[i]-pts[i-1]);

        return ans;

        
        
    }
};