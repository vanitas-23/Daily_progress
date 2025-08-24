class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int curr = 1;
        int lst = nums[0];
        int n=nums.size();
        for (int i = 1; i < n; i++) {
            if (lst == nums[i])
                curr++;
            else {
                if (lst == 1)
                    arr.push_back(curr);
                else
                    arr.push_back(-curr);
                lst = nums[i];
                curr = 1;
            }
        }
        if (lst == 1)
            arr.push_back(curr);
        else
            arr.push_back(-curr);
        if(arr.size()==1)
        return arr[0]>0?arr[0]-1:0;
        if(arr.size()==2)
        return max(arr[0],arr[1]);
        int ans=-1;

        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]==-1)
            ans=max(ans,arr[i-1]+arr[i+1]);
        }
        for(auto i:arr)
        cout<<i<<" ";
        return max(*max_element(arr.begin(),arr.end()),ans);
    }
};