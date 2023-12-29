
struct Tree {
	typedef long long T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
class Solution {
public:
    
    int f(vector<int>& j, int d,int i,int n,Tree& t,int pre,vector<vector<vector<int>>>& dp){
        if(i == n && d == 0) return 0;
        if(i == n || d == 0) return 1e9;
        if(dp[i][d][pre+1]!=-1)
        return dp[i][d][pre+1];
        int ntaken=t.query(pre+1,i+1)+f(j,d-1,i+1,n,t,i,dp);
        int taken=f(j,d,i+1,n,t,pre,dp);

        return dp[i][d][pre+1]=min(ntaken,taken);
    }
    int minDifficulty(vector<int>& j, int d) {
        int n=j.size();
        Tree t(n,0);
        for(int i=0;i<n;i++)
        t.update(i,j[i]);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(d+1,vector<int>(n+1,-1)));
        return f(j,d,0,n,t,-1,dp)>=1e9?-1:f(j,d,0,n,t,-1,dp);
    }
};