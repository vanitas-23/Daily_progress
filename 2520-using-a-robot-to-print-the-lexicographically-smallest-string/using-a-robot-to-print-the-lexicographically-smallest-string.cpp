class Solution {
public:
    string robotWithString(string s) {
        
        int n=s.size();
        string ans;
         vector<int> post(n);
         int i;
         post[n-1]=n-1;
         int c=n-1;
         for(i=n-2;i>=0;i--){
             
             if(s[i]<=s[c]){
                 c=i;
             }
             post[i]=c;
           
         }

         int curr=0;
            string t;

            while(curr<n){
            
             int c=post[curr];
             while(t.size()>0&&t[t.size()-1]<=s[c]){
                ans.push_back(t[t.size()-1]);
                t.pop_back();

             }
             for(int i=curr;i<=c;i++){
                 t.push_back(s[i]);
             }
             if(c==n-1){
                 break;
             }
             curr=c+1;

            }
            for(int i=t.size()-1;i>=0;i--){
               ans.push_back(t[i]);
            }

         return ans;

    }
};