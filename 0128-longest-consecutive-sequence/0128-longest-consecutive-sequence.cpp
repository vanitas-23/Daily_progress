class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};





class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        
        DisjointSet ds(n);

        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
           
           if(mp.find(nums[i])!=mp.end()) continue;
             
            mp[nums[i]]=i;

            if(mp.find(nums[i]+1)!=mp.end()){
                ds.unionBySize(i, mp[nums[i]+1]);
            }
            if(mp.find(nums[i]-1)!=mp.end()){
                ds.unionBySize(i, mp[nums[i]-1]);
            }
        }

        int max_size=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==ds.findUPar(i)){
                max_size=max(max_size,ds.size[i]);
            }
        }

      return max_size;

        }
};