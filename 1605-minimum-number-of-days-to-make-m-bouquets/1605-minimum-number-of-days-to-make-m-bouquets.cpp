class Solution {
public:
    bool can(vector<int>& bloomDay, int m, int k,int days){
        int c=0;
        int temp=0;
        for(int i=0;i<bloomDay.size();i++){
           // cout<<temp;
            if(temp==k){
                c++;
                temp=0;
            }
            if(bloomDay[i]<=days)
            temp++;
            else
            temp=0;
        }
        if(temp==k)
        c++;
        return c>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        
        while(l<=h){
            int mid=h-(h-l)/2;
            if(can(bloomDay,m,k,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};