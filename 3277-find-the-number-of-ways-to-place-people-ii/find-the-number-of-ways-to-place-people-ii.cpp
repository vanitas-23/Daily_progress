class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
       
        int ans = 0;
        int n = p.size();
         sort(p.begin(),p.end(),[] (vector<int> &a,vector<int> &b)
          {
              if(a[0]==b[0])return a[1]>b[1];
              else return a[0]<b[0];
          });
        for(int i=0;i<n-1;i++){
            int a = p[i][0];
            int b = p[i][1];
            int maxi = INT_MIN;
            int fx=1,fy=1;
            for(int j=i+1;j<n;j++){
                if(p[j][0]==a){
                    if(fx){
                        ans++;
                        fx=0;
                    }
                }
                else if(p[j][1]==p[i][1] && fy){
                    ans++;
                    fy=0;
                }
                else{
                    if(p[j][1]<b && p[j][1]>maxi)ans++;
                }
                if(p[j][1]<=b)maxi = max(maxi,p[j][1]);
            }
        }
        return ans;
    }
};