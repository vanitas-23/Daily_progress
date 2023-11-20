class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        unordered_map<int,int>P;
        unordered_map<int,int>G;
        unordered_map<int,int>M;
        int n=garbage.size();
        int Pc=0,Gc=0,Mc=0;
        for(int i=0;i<n;i++){
            for(char c:garbage[i]){
                if(c=='P')
                P[i]++,Pc++;
                else if(c=='G')
                G[i]++,Gc++;
                else M[i]++,Mc++;
            }
        }
        //Paper
        

        for(int i=0;i<n;i++){
            if(Pc<=0)
            break;
            if(i==0)
            ans+=P[i];
            else ans+=P[i],ans+=travel[i-1];
            
            Pc-=P[i];
        }
        for(int i=0;i<n;i++){
            if(Mc<=0)
            break;
            if(i==0)
            ans+=M[i];
            else ans+=M[i],ans+=travel[i-1];
            
            Mc-=M[i];
        }
        for(int i=0;i<n;i++){
            if(Gc<=0)
            break;
            if(i==0)
            ans+=G[i];
            else ans+=G[i],ans+=travel[i-1];
            
            Gc-=G[i];
        }
        return ans;
    }
};