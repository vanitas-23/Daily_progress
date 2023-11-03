class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>res;
        int sz=target.size();
        int k=0;
        for(int i=1;i<=n;i++){
            if(k==sz)
            break;
            if(target[k]==i){
                 res.push_back("Push");
                 k++;
            }
            else
            res.push_back("Push"),res.push_back("Pop");
            
        }
        return res;
    }
};