class Solution {
public:
    int candy(vector<int>& rating) {
        int n=rating.size();
        vector<int>res(n,1);
        for(int i=1;i<n;i++)
               if(rating[i-1]<rating[i])
               res[i]=res[i-1]+1;
        
        for(int i=n-2;i>=0;i--)
        if(rating[i]>rating[i+1])
        res[i]=max(res[i],res[i+1]+1);

        return accumulate(res.begin(),res.end(),0);
    }
};