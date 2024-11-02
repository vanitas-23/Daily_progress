class Solution:
    def isCircularSentence(self, s: str) -> bool:
        l=s.strip().split(' ')
        n=len(l)
        
        for i in range(1,n):
            if l[i-1][-1]!=l[i][0] :
                return False
        return l[-1][-1]==l[0][0]
        