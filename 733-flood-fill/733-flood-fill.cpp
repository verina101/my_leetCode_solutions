class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
    void dfs(int i, int j, vector<vector<int>>& image, int newColor, int oldColor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldColor)
            return;
        image[i][j]=newColor;
        dfs(i-1,j,image,newColor,oldColor);
        dfs(i+1,j,image,newColor,oldColor);
        dfs(i,j-1,image,newColor,oldColor);
        dfs(i,j+1,image,newColor,oldColor);
    }
};