class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10, 0);
        for(char &c : num) cnt[c - '0']++;

        string res1, res2;
        for(int i = 9; i >= 0; i--){
            if(cnt[i] > 1 && (i > 0 || res1.size() > 0)){
                res1 += string(cnt[i] / 2, '0' + i);
                res2 += string(cnt[i] / 2, '0' + i);
                cnt[i] = cnt[i] % 2;
            } 
        }
        for(int i = 9; i >= 0; i--){
            if(cnt[i]){
                res1.push_back('0' + i);
                break;
            } 
        }
        reverse(res2.begin(), res2.end());
        return res1 + res2;
    }
};