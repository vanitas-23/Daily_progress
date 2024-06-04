class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res, n = stones.size();
        res = max(stones[1] - stones[0], 0);
        for (int i = 2; i < n; i += 2) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        for (int i = 3; i < n; i += 2) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};