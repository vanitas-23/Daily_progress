#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int k) {
        vector<ll> arr(nums.begin(), nums.end());
        int n = arr.size();
        ll sum = accumulate(arr.begin(), arr.end(), 0ll);
        for (int i = 0; i < n; i++)
        arr.push_back(arr[i]);

        ll tot = k / sum;
        ll req = k % sum;
        // for(auto i:arr)
        // cout<<i<<" ";
        // cout<<endl;
        // cout<<tot<<" "<<sum<<" "<<req<<endl;
        if (req == 0) 
        return tot*n;
        ll curr = 0;
        int sz = 2 * n + 1;
        int i = 0;
        int j = 0;
        while (j < 2 * n) {
            curr += arr[j];
            while (curr > req)
                curr -= arr[i++];
            if (curr == req)
                sz = min(sz, j - i + 1);
            // cout<<i<<" "<<j<<" "<<curr<<endl;
            j++;
        }
        if (sz == 2 * n + 1)
            return -1;
        else
           return (tot * n + sz);
    }
};