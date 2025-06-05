class DisjointSet {
    public:
        DisjointSet(int n) : N(n), sz(n), pars(n, -1) {
             iota(pars.begin(),pars.end(),0);
        }
        void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }
        int find(int x) {return ( x==pars[x] )? x : pars[x]=find(pars[x]) ;}
        int size() { return sz; }
        int count(int x) { return -pars[find(x)]; }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if(x==y) return false;
            sz--;
            if(x>y) swap(x,y);
            pars[y]=x;
            return true;
        }
        bool isSame(int x, int y) { return find(x) == find(y); }
    private:
        int N, sz;
        vector<int> pars;
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        DisjointSet ds(26);
        for(int i=0;i<n;i++)
        ds.unite(s1[i]-'a',s2[i]-'a');
        string res="";
        for(char c:baseStr)
        res+=('a'+ds.find(c-'a'));
        return res;
    }
};