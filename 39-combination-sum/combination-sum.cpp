class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int> &candidates, int target, int sum, int indx, vector<int> &temp){

        if(sum == target){
            ans.push_back(temp);
            return;
        }

        int n = candidates.size();

        if(sum > target)  return;

        for(int i = indx; i < n; i++ ){
            temp.push_back(candidates[i]);
            solve(candidates, target, sum + candidates[i], i, temp);
            temp.pop_back();
        }

    }

    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp;

        sort(candidates.begin(),candidates.end());

        solve(candidates, target, 0, 0, temp);

        return ans;

        
    }
};