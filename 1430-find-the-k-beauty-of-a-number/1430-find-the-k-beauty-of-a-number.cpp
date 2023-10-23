class Solution {
public:
    int divisorSubstrings(int num, int k) {
     string s = to_string(num);
        int answer = 0;
    int n=s.size();
        for(int i = 0;i + k <=n;i ++) {
            int x = stoi(s.substr(i, k));
            if(x != 0 && num % x == 0)
                answer ++;
        }
        return answer;
    }
};