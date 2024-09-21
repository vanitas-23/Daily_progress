class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>arr(n);
        iota(arr.begin(),arr.end(),1);
        auto cmp=[](int a,int b){
            string s=to_string(a);
            string t=to_string(b);
            return s<t;
        };
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};