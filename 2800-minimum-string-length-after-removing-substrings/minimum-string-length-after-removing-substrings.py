class Solution(object):
    def minLength(self, s):
        x=True
        while x :
            if 'AB' in s:
                
                s=s.replace('AB','')
               # x=true
            elif 'CD' in s:
                s=s.replace('CD','')
               # x=true
            else:
                x=False
        return len(s)
       