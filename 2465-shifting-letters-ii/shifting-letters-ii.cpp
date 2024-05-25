class Solution {
public:
    char f(char c, int x) {

        int pos = c - 'a';
        int new_pos = (pos + x) % 26;
        if (new_pos < 0) {
            new_pos += 26;
        }
        char new_char = new_pos + 'a';
        return new_char;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n + 1);
        for (auto i : shifts)
            if (i[2] == 0)
                arr[i[0]]--, arr[i[1] + 1]++;
            else
                arr[i[0]]++, arr[i[1] + 1]--;
        for (int i = 1; i <= n; i++)
            arr[i] += arr[i - 1];
        for (int i = 0; i < n; i++)
            s[i] = f(s[i], arr[i]);
        return s;
    }
};