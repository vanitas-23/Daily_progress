class DisjointSet {
public:
    DisjointSet(int n) : N(n), sz(n), pars(n, -1) {}
    
    void reset() { sz = N, fill(pars.begin(), pars.end(), -1); }

    int find(int x) { return pars[x] < 0 ? x : pars[x] = find(pars[x]); }

    int size() { return sz; }

    int count(int x) { return -pars[find(x)]; }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        --sz;
        if (pars[x] < pars[y]) swap(x, y);
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
    vector<int> minimumCost(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        vector<int> ans;
        DisjointSet ds(n);
        vector<int> ands(n, -1);

        for (auto& edge : e) {
            int a = edge[0], b = edge[1], w = edge[2];
            int ra = ds.find(a);
            int rb = ds.find(b);

            if (ra != rb) {
                ds.unite(a, b);
                int r = ds.find(a);
                if (ands[ra] == -1) ands[ra] = w;
                else ands[ra] &= w;
                if (ands[rb] == -1) ands[rb] = w;
                else ands[rb] &= w;
                ands[r] = ands[ra] & ands[rb]; 
            } else {
                int r = ra;
                if (ands[r] == -1) ands[r] = w;
                else ands[r] &= w;
            }
        }

        for (auto& qu : q) {
            int a = qu[0], b = qu[1];
            if (ds.isSame(a, b)) {
                ans.push_back(ands[ds.find(a)]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
