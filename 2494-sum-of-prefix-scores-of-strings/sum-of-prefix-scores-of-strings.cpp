class TrieNode {
public:
    map<char, pair<int,TrieNode*>> children;
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c].second = new TrieNode();
                node->children[c].first=1;
            }
            else
            node->children[c].first++;
            node = node->children[c].second;
        }
        node->isEndOfWord = true;
    }
    int length(string s)
    {
        int ans=0;
        auto node=root;
        for(char c:s)
        {
            if(node->children.find(c)==node->children.end())
            return ans;
            ans+=node->children[c].first;
            node=node->children[c].second;
        }
        return ans;
    }
    
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie tr;
        for(auto i:words)
        tr.insert(i);
        vector<int>ans;
        for(auto i:words)
        ans.push_back(tr.length(i));
        return ans;
    }
};