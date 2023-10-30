class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> B(32);
        for(int x :arr)
            B[__builtin_popcount(x)].push_back(x);
        for (auto& b: B)
            sort(b.begin(), b.end());
        int count=0;
        for(int i=0; i<32; i++)
            for(int x: B[i])
                arr[count++]=x;
        return arr;
    }
};