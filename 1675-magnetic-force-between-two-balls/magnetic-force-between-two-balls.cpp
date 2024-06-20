class Solution {
public:
    bool f(int mid,int n,vector<int>& pos,int m)
    {
        int cnt=1;
        int i=0;
        while(i<n)
        {
            i=lower_bound(pos.begin(),pos.end(),pos[i]+mid)-pos.begin();
            //cout<<i<<" "<<mid<<endl;
            if(i<n)
            cnt++;
            else
            break;
        }
        //cout<<endl;
        return cnt>=m;
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