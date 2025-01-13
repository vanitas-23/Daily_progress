typedef pair<int, int> pi;
typedef pair<pi, pi> pii;
typedef tuple<int,int,int> ti;
typedef vector<vector<vector<signed>>> viii;
typedef vector<vector<int>> vii;
typedef vector<vector<pi>> vpi;
typedef vector<int> vi;
#define x first
#define y second
template <class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) { for (int i = 0; i < int(v.size()); i++) os << (i ? " " : "") << v[i]; return os; }

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mx=0;
        vpi v(n);
        for(auto &i:edges) {
            v[i[1]].push_back({i[0],i[2]});
            mx=max(mx,i[2]);
        }
        auto check=[&](int x)->bool {
            vi d(n);
            auto dfs=[&](auto &dfs,int cur)->void {
                d[cur]=1;
                for(auto &[a,b]:v[cur]) {
                    if(b>x||d[a]!=0) continue;
                    dfs(dfs,a);
                }
            };
            dfs(dfs,0);
            int res=0;
            for(auto &i:d) res+=i;
            return res==n;
        };
        //if(!check(mx)) return -1;
        int l=0,r=mx;
        int ans=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(check(mid)) {
                ans=mid;r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};