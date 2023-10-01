class Solution {
public:
    set<vector<int>>st;

    void f(vector<int>& nums,int ind,vector<int> v){
        if(ind>=nums.size())
        return ;
        
        f(nums,ind+1,v);
        st.insert(v);
        v.push_back(nums[ind]);
        f(nums,ind+1,v);
        st.insert(v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>v;
        f(nums,0,v);
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};