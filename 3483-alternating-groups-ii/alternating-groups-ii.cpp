class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int n=colors.size();
        int temp=1;
        int lst=colors[0];
        for(int i=1;i<n+k-1;i++)
        {
            if(colors[i%n]!=lst)
            temp++;
            else
            {
                ans+=max(0,temp-k+1);
                temp=1;
            }
            lst=colors[i%n];
            //cout<<lst<<endl;
        }
       // cout<<temp;
        ans+=max(0,temp-k+1);
        return ans;
    }
};