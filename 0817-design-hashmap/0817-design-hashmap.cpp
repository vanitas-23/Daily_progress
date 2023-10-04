class Node{
public:
    int val;
    int key;
    Node* left = NULL;
    Node* right = NULL;
    
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class MyHashMap {
private:
    Node* root;
    
    Node* helpPut(Node* root, int key, int val){
        if(root == NULL)
            return new Node(key, val);
        if(root->key == key)
            root->val = val;
        else if(root->key > key)
            root->left = helpPut(root->left, key, val);
        else
            root->right = helpPut(root->right, key, val);
        return root;    
    }
    
    int helpGet(Node* root, int key){
        if(root == NULL) return -1;
        if(root->key == key) return root->val;
        if(root->key > key) return helpGet(root->left, key);
        return helpGet(root->right, key);
    }
    
    Node* helpDelete(Node* root, int key){
        if(root == NULL) return NULL;
        
        if(root->key > key)
            root->left = helpDelete(root->left, key);
        else if(root->key < key)
            root->right = helpDelete(root->right, key);
        else{
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            else if(root->left == NULL){
                auto temp = root->right;
                return temp;
            }
            else if(root->right == NULL){
                auto temp = root->left;
                return temp;
            }
            else{
                auto m = getMin(root->right);
                root->key = m->key;
                root->val = m->val;
                root->right = helpDelete(root->right, m->key);
            }
        }
        return root;
    }
    
    Node* getMin(Node* root){
        auto c = root;
        while(c && c->left){
            c = c->left;
        }
        return c;
    }
    
public:
    MyHashMap() {
        root = (Node *)nullptr;
    }
    
    void put(int key, int value) {
        root = helpPut(root, key, value);
    }
    
    
    int get(int key) {
        return helpGet(root, key);
    }
    
    void remove(int key) {
        root = helpDelete(root, key);
    }
};