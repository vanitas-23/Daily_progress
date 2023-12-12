class Solution:
    def getGoodIndices(self, A: List[List[int]], target: int) -> List[int]:

        return [i for i,(a,b,c,m) in enumerate(A) if pow(pow(a, b, 10), c, m) == target]
        