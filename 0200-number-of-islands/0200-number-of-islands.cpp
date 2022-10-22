class Solution {
public:

    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
    
    void dfs(int x, int y, vector<vector<bool>> &vis,vector<vector<char>>& grid ){
        int dx[] = {-1,1,0,0};    
        int dy[] = {0,0,1,-1};
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int new_x = x+dx[i] , new_y = y+dy[i];
            if(new_x >=0 && new_x < grid.size() && new_y >=0 && new_y < grid[0].size() && !vis[new_x][new_y] &&                         grid[new_x][new_y]=='1')
                dfs(new_x,new_y,vis,grid);
            
        }
        
    }
};