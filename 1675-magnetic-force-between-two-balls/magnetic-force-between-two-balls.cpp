class Solution {
public:
    bool f(int mid,int n,vector<int>& position, int m)
    {
        int ball = 1;
        int lastPos = position[0];

        for(int i = 0; i<n; i++)
        {
            if(position[i] - lastPos >= mid)
            {
                ball++;
                if(ball==m)
                    return true;
                 lastPos = position[i];
            }
        }

        return false;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int l=1;
        int h=*max_element(pos.begin(),pos.end());
        int ans=h;
        int n=pos.size();
        while(l<=h)
        {
            int mid=(l+h)/2;
            //cout<<mid<<" ";
            if(f(mid,n,pos,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
};