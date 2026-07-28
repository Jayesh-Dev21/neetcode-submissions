class Solution:
    def maxProfit(self, p: List[int]) -> int:
        maxP = 0
        m = p[0]
        for i in range(1,len(p)):
            m = min(m, p[i])
            profit = p[i] - m;
            maxP = max(profit, maxP)
        return maxP
        