class Solution {
public:
    long long dfs(int i,vector<int>& arr){
        long long res=0;
        int n=arr.size();
        int mn=INT_MAX;
        
            for(int j=i+1;j<n;j++){
                if(arr[j]<mn)
                    mn=arr[j];
                res+=mn;
            }
        
        mn=INT_MAX;
        
            for(int j=i-1;j>=0;j--){
                if(arr[j]<mn)
                    mn=arr[j];
                res+=mn;
            }
        
        return res+arr[i];
    }
    long long maximumSumOfHeights(vector<int>& arr) {
        int mx=-1;
        
        int n=arr.size();
        long long ans=0;
        if(n==1)
            return arr[0];
         for(int i=0;i<n;i++){
             
            
            if(i>0 && i<n-1 && arr[i]>=arr[i-1] && arr[i]>=arr[i+1]){
                long long temp=dfs(i,arr);
                 ans=max(ans,temp);
            }
             if(i==0 && arr[i]>=arr[i+1]){
                  long long temp=dfs(i,arr);
                 ans=max(ans,temp);
             }
                // ans=max(ans,temp);
             if(i==n-1 && arr[i]>=arr[i-1]){
                  long long temp=dfs(i,arr);
                 ans=max(ans,temp);
             }
                 //ans=max(ans,temp);
                  
         }
        return ans;
    }
};