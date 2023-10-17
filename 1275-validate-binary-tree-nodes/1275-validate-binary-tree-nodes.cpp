static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class UnionFindSet {
    public:
        UnionFindSet(int n) : _parent(n), _size(n) {
            for (int i=0; i<n; i++) {
                _parent[i] = i;
                _size[i] = 1;
            }
        }
        bool Union(int x, int y) {
            int rootX = Find(x);
            int rootY = Find(y);
            if(rootX==rootY)
                return true;
            if(rootX != rootY){
                if(_size[rootY]>_size[rootX]){
                    _parent[rootX] = rootY;
                }
                else if(_size[rootY]<_size[rootX]){
                    _parent[rootY] = rootX;
                }
                else{
                    _parent[rootX] = rootY;
                    _size[rootY]++;
                }
            }
            return false;
        }
        int Find(int x) {
            if (_parent[x] == x) {
                return x;
            }
            return _parent[x] = Find(_parent[x]);
        }
        vector<int> getParent(){
            return _parent;
        }
    private:
        vector<int> _parent;
        vector<int> _size;
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        
        vector<int> indegree(n, 0);
        UnionFindSet ufs(n);
        for(int i = 0; i < n; i++){
            if(lc[i]!=-1){
                indegree[lc[i]]++;
                if(indegree[lc[i]]>1 || ufs.Union(i, lc[i]))
                    return false;
            }
            if(rc[i]!=-1){
                indegree[rc[i]]++;
                if(indegree[rc[i]]>1 || ufs.Union(i, rc[i]))
                    return false;
            }
        }
        
        vector<int> parent = ufs.getParent();
        int dif = 0, pre = -1;
        for(auto p : parent){
            //cout << p << " ";
            if(ufs.Find(p)!=pre){
                dif++;
                pre = p;
            }
        }
        //cout << endl;
        return dif==1;
    }
};