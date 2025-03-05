class Solution {
public:
    long long coloredCells(int n) {
        return n*1ll*n + (n-1)*1ll*(n-1);
    }
};