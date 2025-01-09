class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int prefixCount = 0;
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->prefixCount++;
        }
        node->isEndOfWord = true;
    }

    int searchPrefix(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return 0;
            }
            node = node->children[c];
        }
        return node->prefixCount;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie tr;
        for (const auto& word : words) {
            tr.insert(word);
        }
        return tr.searchPrefix(pref);
    }
};