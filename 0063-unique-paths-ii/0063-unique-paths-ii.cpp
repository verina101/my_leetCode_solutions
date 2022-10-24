class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        vector<vector<int>> dp(r,vector<int>(c));
        
        
        if(obstacleGrid[0][0]==1)
            return 0;
        dp[0][0]=1;
        
        for(int i=1;i<r;i++){
            dp[i][0] = (dp[i-1][0] && !obstacleGrid[i][0]) ? 1:0;
        }
        for(int i=1;i<c;i++){
            dp[0][i] = (dp[0][i-1] && !obstacleGrid[0][i]) ? 1:0;
        }
        
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(obstacleGrid[i][j])
                    dp[i][j]=0;
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};