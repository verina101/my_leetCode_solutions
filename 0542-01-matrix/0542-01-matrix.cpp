class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols  = mat[0].size();
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        vector<vector<int>> ans(rows, vector<int>(cols,INT_MAX));
        queue<pair<int,int>>q;
        
        for(int i=0; i<rows; i++){
            for(int j=0;j<cols; j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
                    
            }
        }
        
        while(!q.empty()){
            pair<int,int> cell = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int new_x = cell.first + dx[i], new_y = cell.second + dy[i];
                if(new_x < rows && new_y < cols && new_x >=0 && new_y >=0){
                    if(ans[new_x][new_y] > ans[cell.first][cell.second]+1){
                        ans[new_x][new_y] = ans[cell.first][cell.second]+1;
                        q.push({new_x,new_y});
                    }
                }
            }
            
            
        }
        return ans;
        
    }
};