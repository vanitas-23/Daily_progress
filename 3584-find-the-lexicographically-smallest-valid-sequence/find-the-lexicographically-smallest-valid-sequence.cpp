class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        vector<int> c(n);
        int j = m - 1;

        // Step 1: Fill the `c` array which tracks how many characters can match w2 from the suffix of w1
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && w1[i] == w2[j]) {
                c[i] = (i == n - 1) ? 1 : c[i + 1] + 1;
                j--;
            } else {
                c[i] = (i == n - 1) ? 0 : c[i + 1];
            }
        }

        // Step 2: Try to find the valid sequence of indices
        j = 0;
        vector<int> ans;
        int victory = -1;
        
        for (int i = 0; i < n; i++) {
            if (w1[i] == w2[j]) {
                ans.push_back(i);
                j++;
                if (j == m) {
                    break;
                }
            } else {
                // Check if we can match the remaining part of w2 from the suffix
                if ((i == n - 1 ? 0 : c[i + 1]) >= m - j - 1) {
                    ans.push_back(i);
                    j++;
                    victory = i + 1;
                    break;
                }
            }
        }

        // If we already found a full match, return the answer
        if (ans.size() == m) {
            return ans;
        }

        // If no partial sequence was valid, return an empty result
        if (victory == -1) {
            return vector<int>();
        }

        // Step 3: Continue matching the remaining characters of w2 starting from `victory`
        for (int i = victory; i < n; i++) {
            if (w1[i] == w2[j]) {
                ans.push_back(i);
                j++;
            }
            if (j == m) {
                break;
            }
        }

        // Return the answer if we found a valid sequence, otherwise return an empty vector
        return (ans.size() == m) ? ans : vector<int>();
    }
};