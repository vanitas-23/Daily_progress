class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        
        return max(b - a for a, b in pairwise(sorted(list(zip(*points))[0])))