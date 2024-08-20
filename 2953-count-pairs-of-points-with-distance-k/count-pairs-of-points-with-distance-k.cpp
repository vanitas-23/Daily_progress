class Solution {
public:
    long long hash(int x, int y) {
        return ((long long)x << 32) + y;
    }
    pair<int,int> getHash(long long hashValue) {
        return {hashValue >> 32, hashValue & (0xffffffff)}; 
    }
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<long long, int> freq;

        for (const auto &coordinate : coordinates) {
            freq[hash(coordinate[0], coordinate[1])] ++;
        }


        long long res = 0;
        for (int i = 0; i <= k; i ++) {
            int disX = i;
            int disY = k - i;
            for (const auto &coordinate : coordinates) {
                int matchX = disX ^ coordinate[0];
                int matchY = disY ^ coordinate[1];
                auto it = freq.find(hash(matchX, matchY));
                if (it != freq.end()) {
                    if (matchX == coordinate[0] && matchY == coordinate[1]) {
                        res += it->second - 1 ;
                    } else {
                        res += it->second;
                    }
                }
            }
        }
        return res / 2;
    }
};