class Solution {
public:
    
    string s;
    int N,K;
    
    int H(int x){
        if(x==1)
            return 1;
        
        if(x<10)
            return 2;
        if(x<100)
            return 3;
        return 4;
    }
    
    int store[105][105];
    int sol(int index,int k){
        if(index==N){
            return 0;
        }
        
        if(store[index][k]!=-1)
            return store[index][k];
        
        int ans=N;
        
        char prev=s[index];
        int L=0;
        int tempk=k;
        
        if(tempk>0){
            ans=min(ans,sol(index+1,tempk-1));
        }
        
        for(int i=index;i<N;i++){
            if(s[i]==prev){
                L++;
                ans=min(ans,H(L)+sol(i+1,tempk));
            } 
            else{
                ans=min(ans,H(L)+sol(i,tempk));
                if(tempk>0)
                    tempk--;
                else
                    break;
            }
            
            
        }
        
        
        
        return store[index][k]=ans;
        
    }
    int getLengthOfOptimalCompression(string t, int k) {
        s=t;
        N=(int)s.size();
        K=k;

        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++)
                store[i][j]=-1;
        }
        
        return sol(0,k);
    }
};