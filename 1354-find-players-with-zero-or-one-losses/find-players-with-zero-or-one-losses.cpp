class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        array<bool, 100001> played = {};
        array<int, 100001> losses = {};
        
        for (const vector<int>& match : matches) {
            played[match[0]] = true;
            played[match[1]] = true;
            ++losses[match[1]];
        }
        
        vector<vector<int>> ans(2);

        for (int i = 0; i < size(played); ++i) {
            if (played[i]) {
                if (losses[i] == 0) {
                    ans[0].push_back(i);
                } else if (losses[i] == 1) {
                    ans[1].push_back(i);
                }  
            }
        }    
        return ans; 
    }    
};