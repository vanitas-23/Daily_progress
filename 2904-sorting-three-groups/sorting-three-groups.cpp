class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int ans = 1;
        for(int i=1;i<n;i++){
            int x = upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            if(x==temp.size()) temp.push_back(nums[i]);
            else{
                temp[x] = nums[i];
            }
        }
        return n-temp.size();
        
    }
};