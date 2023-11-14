class Solution {
public:
    set<vector<int>>res;
    void f(int target,vector<int>& candidates,vector<int> temp){
        if(target==0){
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }

        for(int i=0;i<candidates.size();i++){
            vector<int>pre=temp;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                f(target-candidates[i],candidates,temp);
                temp=pre;
            }
        }
      //  f(target,candidates,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        f(target,candidates,temp);

        vector<vector<int>> ans;
        for(auto i:res)
        ans.push_back(i);
        return ans;
    }
};