class Solution {
public:
    bool isGood(vector<int>& v) {
        
        int n = v.size();
        int mx = *max_element(v.begin(),v.end());
        
        set<int> s(v.begin(),v.end());
        bool flag = 1;
        int k = 1;
        
        for(auto x : s){
            if(x == k) k++;
            else{
                flag = 0;
                break;
            }
        }
        
        int ct = count(v.begin(),v.end(),mx);
        if(n == mx + 1 && ct == 2 && flag) return 1;
        else return 0;
    }
};