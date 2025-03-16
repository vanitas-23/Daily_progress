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
    int validSubarraySize(vector<int>& nums, int t) {
        priority_queue<pair<int,int>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        pq.push({nums[i],i});
        DisjointSet ds(n);
        vector<int>marked(n);
        for(int k=1;k<=n;k++)
        {
            int req=t/k;
            while(pq.size()>0 && pq.top().first>req)
            {
                auto x=pq.top();pq.pop();
                marked[x.second]=1;
                if(x.second-1>=0)
                {
                    if(marked[x.second-1])
                    ds.unite(x.second,x.second-1);
                }
                if(x.second+1<n)
                {
                    if(marked[x.second+1])
                    ds.unite(x.second,x.second+1);
                }
                if(ds.count(x.second)>=k)
                return k;
            }
            
        }
        return -1;
    }
};