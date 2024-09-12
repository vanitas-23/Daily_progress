class Solution {
public:
    int countConsistentStrings(string all, vector<string>& words) {
        int ele = 0;
        for (char c : all)
            ele |= (1 << (c - 'a'));

        int ans = 0;
        for (auto i : words) {
            int temp = 0;
            ans++;
            for (char c : i)
                temp |= (1 << (c - 'a'));
            for(char c='a';c<='z';c++)
            {
                if(temp&(1<<(c-'a')))
                {
                    if(ele&(1<<(c-'a')))
                    {
                        continue;
                    }
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};