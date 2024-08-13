class Solution {
public:

    set<vector<int>> ans;

    void solve(vector<int> &candidates, int target, int sum, int indx, vector<int> &temp){

        if(sum == target){
            ans.insert(temp);
            return;
        }

        int n = candidates.size();

        if(sum > target)  return;

        for(int i = indx; i < n; i++ ){
            if(i>indx && candidates[i]==candidates[i-1])
            continue;
            temp.push_back(candidates[i]);
            solve(candidates, target, sum + candidates[i], i+1, temp);
            temp.pop_back();
        }

    }

    

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> temp;

        sort(candidates.begin(),candidates.end());

        solve(candidates, target, 0, 0, temp);
        vector<vector<int>>res;
        for(auto i:ans)
        res.push_back(i);
        return res;

        
    }
};