class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def f(i:int, n:int,s:str,st:set)->int:
            if i==n:
                return 0
            ans=0
            for j in range(i+1,n+1):
                temp=s[i:j]
                if temp not in st:
                    st.add(temp)
                    ans=max(ans,1+f(j,n,s,st))
                    st.remove(temp)
            return ans
        st=set()
        return f(0,len(s),s,st)