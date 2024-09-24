class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool f(int i, int n, string s, TrieNode* node) {
        if (node == nullptr) return false; 

        if (i == n) return node->isEndOfWord;  

        if (s[i] != '.') {
            
            if (node->children.find(s[i]) != node->children.end())
                return f(i + 1, n, s, node->children[s[i]]);
            else
                return false;
        } else {
           
            for (auto& child : node->children) {
                if (f(i + 1, n, s, child.second)) {
                    return true;  
                }
            }
            return false; 
        }
    }

    bool search(string word) {
        return f(0, word.size(), word, root);
    }
};
