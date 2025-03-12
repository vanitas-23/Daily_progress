template <typename T>
struct Tree
{
    vector<T> seg, baskets;
    int n;

    Tree(int n, vector<T> &b) : n(n), baskets(b)
    {
        seg.resize(4 * n, 0);
    }
    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2 + 1, l, mid);
        build(idx * 2 + 2, mid + 1, r);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
    int query(int idx, int l, int r, T x)
    {
        if (seg[idx] < x)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (seg[idx * 2 + 1] >= x)
            return query(idx * 2 + 1, l, mid, x);
        else
            return query(idx * 2 + 2, mid + 1, r, x);
    }
    void update(int idx, int l, int r, int pos, T val)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(idx * 2 + 1, l, mid, pos, val);
        else
            update(idx * 2 + 2, mid + 1, r, pos, val);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& bas) {
        int n=fruits.size();
        Tree tr(n,bas);
        tr.build(0,0,n-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            auto x=tr.query(0,0,n-1,fruits[i]);
            //cout<<x<<endl;
            if(x==-1)
                ans++;
            else
                tr.update(0,0,n-1,x,0);
        }
        return ans;
    }
};