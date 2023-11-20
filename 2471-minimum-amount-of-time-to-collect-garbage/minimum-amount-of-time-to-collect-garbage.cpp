class Solution {
public:
    int garbageCollection(vector<string>& grb, vector<int>& travel) {
        int time=grb[0].size();
        int m=0,g=0,p=0,sum=0;
        for(int i=1;i<grb.size();i++){
            sum+=travel[i-1];
            for(char c:grb[i])
            {
                if(c=='M')
                m=sum;
                if(c=='G')
                g=sum;
                if(c=='P')
                p=sum;
             time++;
            }

           
        }
        time+=(m+p+g);
        return time;
    }
};