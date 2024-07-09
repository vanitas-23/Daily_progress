class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) {
        double all=0;
        int curr=1;
        int n=cus.size();
        for(int i=0;i<n;i++)
        {
            curr=max(curr,cus[i][0]);
            all+=(curr+cus[i][1]-cus[i][0]);
            curr=curr+cus[i][1];
        }
        return all/n;
    }
};