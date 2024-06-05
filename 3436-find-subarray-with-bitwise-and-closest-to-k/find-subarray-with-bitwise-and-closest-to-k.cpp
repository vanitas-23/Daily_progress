struct Tree {
	typedef long long T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return (a&b); } // (any associative fn)
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
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        Tree sg(n);
        for(int i=0;i<n;i++)
        sg.update(i,nums[i]);
        int ans=1e9;
        int j=0;
        int i=0;
        int ini=INT_MAX;
        while(j<n)
        {
            ini&=nums[j];
            ans=min(ans,abs(k-ini));
            while(i<=j && ini<k)
            {
                ini=sg.query(i,j+1);
                i++;
                ans=min(ans,abs(k-ini));
            }
            ans=min(ans,abs(k-ini));
            j++;
        }
        return ans;
    }
};