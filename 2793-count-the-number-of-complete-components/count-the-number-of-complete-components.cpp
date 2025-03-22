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
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<int>inD(n);
        for(auto i:edges)
        ds.unite(i[0],i[1]);
        for(auto i:edges)
        inD[i[0]]++,inD[i[1]]++;
        set<int>st;
        vector<int>req;
        for(int i=0;i<n;i++)
        {
            if(inD[i]==inD[ds.find(i)] && inD[i]==ds.count(ds.find(i))-1)
            st.insert(ds.find(i));
            else
            req.push_back(i);
        }
        for(auto i:req)
        {
            auto it=st.find(ds.find(i));
            if(it!=st.end())
            st.erase(it);
        }
        return st.size();
    }
};