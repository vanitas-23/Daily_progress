class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>arr(26);
        for(auto i:words)
        for(char c:i)
        arr[c-'a']++;

        int n=words.size();
        for(int i=0;i<26;i++)
        if(arr[i]%n!=0)
        return 0;

        return 1;
    }
};