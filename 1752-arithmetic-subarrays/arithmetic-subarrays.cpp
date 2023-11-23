class Solution {
public:
    bool check(vector<int>& arr) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i:arr){
            mn=min(i,mn);
            mx=max(i,mx);
        }
        int n=arr.size();
        if((mx-mn)%(n-1)!=0)
        return 0;

        int d=(mx-mn)/(n-1);
        for(auto& i:arr)
        i-=mn;

        if(d==0)
        return mn==mx;
        unordered_set<int>st;
        for(int i:arr){
        if(i%d!=0)
        return 0;
        if(st.find(i/d)!=st.end())
        return 0;
        st.insert(i/d);
        }
        return 1;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        } 
        return ans;
    }
};