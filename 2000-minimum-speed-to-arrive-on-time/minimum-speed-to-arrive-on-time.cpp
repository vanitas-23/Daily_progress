class Solution {
public:
    bool f(vector<int>& dist,double hour,int mid)
    {
        double taken=0.0;
        for(int i=0;i<dist.size()-1;i++)
        taken+=(ceil(dist[i]*1.0/mid));

        taken=taken+dist.back()*1.0/mid;
        //cout<<taken;
        return taken<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int h=1e9;
        int ans=-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(f(dist,hour,mid)){
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};