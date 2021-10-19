class Solution(object):

    def minCostClimbingStairs(self, cost):

        n = len(cost)
        f = [0]*n
        
            
        for i in range(n-1, -1, -1):
            if i+1 < n and i+2 < n: 
                f[i] = cost[i] + min(f[i+1], f[i+2])
            else:
                f[i] = cost[i]
                

        return min(f[0],f[1])
        