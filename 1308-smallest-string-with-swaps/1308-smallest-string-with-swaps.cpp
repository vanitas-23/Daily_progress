class Solution {
public:
    class DisjointSet {
    public:
        DisjointSet(int n) : N(n), sz(n), pars(n, -1) {
        }
        void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }
        int find(int x) { return pars[x] < 0 ? x : pars[x] = find(pars[x]); }
        int size() { return sz; }
        int count(int x) { return -pars[find(x)]; }
        bool unite(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) { return false; }
            --sz;
            if (pars[x] < pars[y]) { swap(x, y); }
            pars[y] += pars[x];
            pars[x] = y;
            return true;
        }
        bool isSame(int x, int y) { return find(x) == find(y); }
    private:
        int N, sz;
        vector<int> pars;
};
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DisjointSet st(n);
        for(auto i:pairs)
        st.unite(i[0],i[1]);
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;

        for(int i=0;i<n;i++)
        mp[st.find(i)].push(s[i]);
        for(int i=0;i<n;i++){
            int p=st.find(i);
            s[i]=mp[p].top();
            mp[p].pop();
        }
        return s;
    }
};