class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,word,0))
                        return true;
                }                    
            }
        }
        return false;
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int index){
        if(index == word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]!=word[index] )
            return false;
        
        board[i][j]='0';
        
        bool ans = (dfs(i+1,j,board,word,index+1)||dfs(i-1,j,board,word,index+1)
                    ||dfs(i,j+1,board,word,index+1)||dfs(i,j-1,board,word,index+1));
        
        board[i][j]=word[index];
        
        return ans;
        
    }
};