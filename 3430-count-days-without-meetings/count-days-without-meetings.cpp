class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        if(n<=1) return intervals;
        int a=intervals[0][0],b=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=b) b=max(b,intervals[i][1]);
            else{
                ans.push_back({a,b});
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }
        ans.push_back({a,b});
        return ans;
    }
    int countDays(int d, vector<vector<int>>& mtgs) {
       int ans=0;
        auto x=merge(mtgs);
        for(int i=1;i<x.size();i++){
            ans+=x[i][0]-x[i-1][1]-1;
        }
        ans+=x[0][0]-1;
        ans+=d-x.back()[1];
        return ans;
        }
};