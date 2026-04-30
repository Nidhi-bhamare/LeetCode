class Solution(object):
    def maxPathScore(self, grid, k):
        m, n = len(grid), len(grid[0])
        
        # dp[i][j] = {cost: max_score}
        dp = [[{} for _ in range(n)] for _ in range(m)]
        
        # starting point
        dp[0][0] = {0: 0}
        
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                
                val = grid[i][j]
                cost = 1 if val > 0 else 0
                score = val
                
                current = {}
                
                # from top
                if i > 0:
                    for c, s in dp[i-1][j].items():
                        new_c = c + cost
                        if new_c <= k:
                            current[new_c] = max(current.get(new_c, 0), s + score)
                
                # from left
                if j > 0:
                    for c, s in dp[i][j-1].items():
                        new_c = c + cost
                        if new_c <= k:
                            current[new_c] = max(current.get(new_c, 0), s + score)
                
                dp[i][j] = current
        
        # get answer
        if not dp[m-1][n-1]:
            return -1
        
        return max(dp[m-1][n-1].values())