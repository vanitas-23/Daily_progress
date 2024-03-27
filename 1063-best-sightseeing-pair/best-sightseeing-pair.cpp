class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        temp[i]=values[i]-i;
        for(int i=n-2;i>=0;i--)
        temp[i]=max(temp[i+1],temp[i]);
        int ans=0;
        for(int i=0;i<n-1;i++)
        ans=max(ans,i+values[i]+temp[i+1]);
        return ans;
    }
};