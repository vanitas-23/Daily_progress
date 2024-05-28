class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int>croak(5);
        for (char c: croakOfFrogs) {
            if (c == 'c') {
                croak[0]++;
                if (croak[4] != 0) croak[4]--;
            }
            else if (c == 'r') {
                if (croak[0] <= 0) return -1;
                croak[0]--;
                croak[1]++;
            }
            else if (c == 'o') {
                if (croak[1] <= 0) return -1;
                croak[1]--;
                croak[2]++;
            }
            else if (c == 'a') {
                if (croak[2] <= 0) return -1;
                croak[2]--;
                croak[3]++;
            }
            else if (c == 'k') {
                if (croak[3] <= 0) return -1;
                croak[3]--;
                croak[4]++;
            }
        }
        
        if(croak[0] != 0 || croak[1] != 0 || croak[2] != 0 || croak[3] != 0) return -1;
        return croak[4];
    }
};