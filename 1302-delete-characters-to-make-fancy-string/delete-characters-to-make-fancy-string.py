class Solution:
    def makeFancyString(self, s: str) -> str:
        res=""
        cnt=0
        pre='#'
        for c in s:
            if cnt==0:
                res+=c
                cnt=1
                pre=c
            else:
                if pre==c:
                    if cnt==1:
                        res+=c
                        cnt+=1
                else:
                    res+=c
                    cnt=1
                    pre=c
        return res
        