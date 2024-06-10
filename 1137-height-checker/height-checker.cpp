class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        auto x=heights;
        sort(heights.begin(),heights.end());
        int ans=0;
        for(int i=0;i<n;i++)
        if(heights[i]!=x[i])
        ans++;
        return ans;
    }
};