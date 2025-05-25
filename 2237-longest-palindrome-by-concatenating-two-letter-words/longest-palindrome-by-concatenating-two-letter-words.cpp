class Solution {
public:
    int isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> mp1, mp2;
        for (auto i : words) {
            auto x = i;
            reverse(i.begin(), i.end());
            if (mp1.find(i) != mp1.end()) {
                ans += 2 * i.size();
                mp1[i]--;
                if (mp1[i] == 0)
                    mp1.erase(i);
            } else
                mp1[x]++;
        }
        int mx=0;
        for(auto i:mp1)
        {
            if(isPalindrome(i.first))
            mx=max(mx,(int)(i.first.size())*i.second);
        }
        return ans+mx;
    }
};