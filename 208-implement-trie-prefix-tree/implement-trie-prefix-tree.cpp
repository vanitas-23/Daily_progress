struct Node{
    Node* links[26];
    bool flag=0;
    bool containsKey(char c){
        return links[c-'a']!=nullptr;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a']=node;
    }
    void setEnd(){
        flag=1;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c))
            node->put(c,new Node());
            node=node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c))
            return false;
            node=node->get(c);
        }
          return node->isEnd();
        
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c))
            return false;
            node=node->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */