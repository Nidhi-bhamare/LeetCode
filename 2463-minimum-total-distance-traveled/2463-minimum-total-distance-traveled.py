class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        robot.sort()
        factory.sort()
        
        n = len(robot)
        m = len(factory)
        
        # dp[i][j] = min distance for first i robots using first j factories
        dp = [[float('inf')] * (m + 1) for _ in range(n + 1)]
        
        # base case: 0 robots = 0 distance
        for j in range(m + 1):
            dp[0][j] = 0
        
        for j in range(1, m + 1):
            pos, limit = factory[j - 1]
            
            for i in range(1, n + 1):
                # option 1: skip this factory
                dp[i][j] = dp[i][j - 1]
                
                # option 2: assign k robots to this factory
                dist = 0
                for k in range(1, min(limit, i) + 1):
                    dist += abs(robot[i - k] - pos)
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + dist)
        
        return dp[n][m]