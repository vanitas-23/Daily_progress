class Solution {
public:
    int countCollisions(string dir) {
        int cnt=0;
        stack<char>st;
        for(int i=0;i<dir.size();i++){
            if(st.empty())
            st.push(dir[i]);
            else if(dir[i]=='L' && st.top()=='R'){
                cnt+=2;
               dir[i]='S';
               i--;
                st.pop();
            }
            else if(dir[i]=='L' && st.top()=='S')
            {
                cnt+=1;
            }
            else if(dir[i]=='S' && st.top()=='R')
            {
                cnt+=1;
                dir[i]=='S';
                i--;
                st.pop();
            }
            else
            st.push(dir[i]);
        }
        return cnt;
    }
};