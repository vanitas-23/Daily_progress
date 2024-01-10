class Solution {
public:
   
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int rk=2;
        if(b==f){
            if(d==f && (e-c)*(c-a)>0)
                rk=2;
            else
                return 1;
        }
        
        if(a==e){
            if(c==e && (f-d)*(d-b)>0)
                rk=2;
            else
                return 1;
        } 
        if(abs(c-e)==abs(d-f)){
           // cout<<"hi"<<" ";
            if(abs(c-a)==abs(d-b) && (e-a)*(a-c)>0 && (f-b)*(b-d)>0)
            {
                rk=2;
            }
            else
                return 1;
        }
        return rk;
    }
};