class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[] = {-1,1,0,0};    
        int dy[] = {0,0,1,-1};
        int rows = grid.size();
        int cols = grid[0].size();
        int cnt=-1,ones=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<rows;i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    ones++;
                }
            }
        }
        
        while(!q.empty()){
            
            int sz = q.size();
            for(int j=0;j<sz;j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int new_x = x+dx[i], new_y = y + dy[i];
                    if(new_x >= 0 && new_x < rows && new_y >=0 && new_y < cols && grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                        ones--;
                    }
                }
            }
            cnt++;
            
        }
        if(ones != 0 ) return -1;
        else if(cnt==-1)return 0;
        else return cnt;
        
    }
};