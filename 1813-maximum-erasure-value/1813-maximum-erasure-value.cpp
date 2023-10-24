class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         bitset<10001> included;
        int sum {nums.front()};
        int max_sum {sum};
        included.set(nums.front());
        for (size_t i {0}, j {1}; j < nums.size(); ++j) {
            for (; included.test(nums[j]); ++i) {
                sum -= nums[i];
                included.reset(nums[i]);
            }
            sum += nums[j];
            included.set(nums[j]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};