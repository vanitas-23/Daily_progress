class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        vector<int>res(a.size(),-1);
        int left=0;
        int right=0;
        for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[j]<=a[i]){
            res[i]=a[i]-a[j];
            break;}
        }
        if(res[i]==-1)
        res[i]=a[i];
        }
        return res;
    }

};