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
    bool f(string &a,string &b)
    {
        int cnt=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                cnt++;
        }
     //   cout<<cnt<<" ";
        return cnt<=2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        ds.unite(i,i);

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(f(strs[i],strs[j]))
        ds.unite(i,j);//,cout<<i<<" "<<j<<endl;

        int ans=0;
       for(int i=0;i<n;i++)
        if(ds.find(i)==i)
        ans++;
        return ans;

    }
};