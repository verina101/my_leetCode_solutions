class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                cnt=0;
                if(grid[i][j]==1)
                    ans = max(ans,dfs(i,j,grid,cnt));
            }
        }
        return ans;
    }
    int dfs(int i, int j ,vector<vector<int>>& grid, int& cnt){
         if(i<0|| j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=-1;
        cnt++;
        
        dfs(i+1,j,grid,cnt);
        dfs(i-1,j,grid,cnt);
        dfs(i,j+1,grid,cnt);
        dfs(i,j-1,grid,cnt);
        
        return cnt;
    }
};