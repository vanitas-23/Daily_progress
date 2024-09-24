class TrieNode {
public:
    TrieNode* children[2] = {nullptr, nullptr};
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int bit = c - '0';
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int get(string val) {
        int ans = 0;
        TrieNode* node = root;
        for (int i = 0; i < 32; i++) {
            int bit = val[i] - '0';
            if (node->children[1 - bit]) {
                ans += (1 << (31 - i));
                node = node->children[1 - bit];
            } else if (node->children[bit]) {
                node = node->children[bit];
            } else {
                return ans;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trr;
        for (auto i : nums)
            trr.insert(bitset<32>(i).to_string());
        int ans = 0;
        for (auto i : nums)
            ans = max(ans, trr.get(bitset<32>(i).to_string()));
        return ans;
    }
};
