class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++)
        {
            int lsR=0;
            int grR=0;
            int lsL=0;
            int grL=0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                lsL++;
                else
                grL++;
            }
            for(int j=n-1;j>i;j--)
            {
                if(rating[j]<rating[i])
                lsR++;
                else
                grR++;
            }
            ans+=(lsL*grR);
            ans+=(lsR*grL);
        }
        return ans;
    }
};