class Solution {
public:
    string reorganizeString(string s) {
        vector<int> chrCounts(26);
        for (auto& chr : s)     chrCounts[chr - 'a']++;
    
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < 26; i++) {
            if (chrCounts[i] > 0) {
                q.push({chrCounts[i], 'a' + i});
            }
        }

        string result = "";
        auto prev = q.top();
        q.pop();
        result += prev.second;
        while (!q.empty()) {
            auto curr = q.top();
            q.pop();
            result += curr.second;
            if (--prev.first > 0) q.push(prev);
            prev = curr;
        }

        if (result.size() != s.size())   return "";
        return result;
    }
};