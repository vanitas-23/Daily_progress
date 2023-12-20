class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        cost = sum(nsmallest(2, prices))
        return money-cost if money >= cost else money