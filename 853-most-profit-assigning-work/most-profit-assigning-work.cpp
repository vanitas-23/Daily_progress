class Solution {
public:
    int maxProfitAssignment(vector<int>& dff, vector<int>& pro,
                            vector<int>& w) {
        vector<pair<int, int>> arr;
        int n = dff.size();
        for (int i = 0; i < n; i++)
            arr.push_back({dff[i], pro[i]});

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
            dff[i] = arr[i].first, pro[i] = arr[i].second;

        for (int i = 1; i < n; i++)
            pro[i] = max(pro[i], pro[i - 1]);

        for (auto i : w) {
            auto it = upper_bound(dff.begin(), dff.end(), i) - dff.begin();
            if (it == 0)
                continue;
            ans += pro[it - 1];
        }
        return ans;
    }
};