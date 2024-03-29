class Solution {
public:
    
bool backTracking(vector<vector<int>> &res, const vector<int> &nums, const int &trgt, int i, int sz, vector<int> &summerVec, int sum)
{
    if (trgt < sum || i == sz)
        return false;
    else if (trgt == sum)
    {
        res.push_back(summerVec);
        return true;
    }
    summerVec.push_back(nums[i]);
    bool with = backTracking(res, nums, trgt, i, sz, summerVec, sum + nums[i]);
    summerVec.pop_back();
    if (!with)
        return true;
    bool without = backTracking(res, nums, trgt, i + 1, sz, summerVec, sum);
    return with || without;
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    vector<int> summer;
    int sz = candidates.size();
    vector<vector<int>> res;
    backTracking(res, candidates, target, 0, sz, summer, sum);
    return res;
}

};