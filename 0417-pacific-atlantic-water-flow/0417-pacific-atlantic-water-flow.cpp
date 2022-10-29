class Solution {
public:
    vector<vector<bool>>ocean1,ocean2;
    vector<vector<int>> ans;
    int n,m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        ocean1 = ocean2 = vector<vector<bool>>(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
           dfs(heights,ocean1,i,0);
        }
        for(int i=0;i<m;i++){
           dfs(heights,ocean1,0,i);
        }
        for(int i=0;i<n;i++){
           dfs(heights,ocean2,i,m-1);
        }
        for(int i=0;i<m;i++){
           dfs(heights,ocean2,n-1,i);
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,int i,int j){
        pair<int,int> next[] = {{0,1},{0,-1},{-1,0},{1,0}};
        if(vis[i][j])return;
        vis[i][j]=1;
        
        if(ocean1[i][j]==ocean2[i][j] && ocean1[i][j])
            ans.push_back({i,j});
        
        for(auto &ne :next){
            int x = ne.first + i , y = ne.second + j;
            if(x >=0 && x<n && y>=0 && y<m && !vis[x][y] && heights[i][j] <= heights[x][y]){
                dfs(heights,vis,x,y);
            }
                
        }
    }
};