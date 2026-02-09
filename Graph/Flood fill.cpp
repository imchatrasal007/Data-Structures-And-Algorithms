You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.
Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.
class Solution {
  public:
   void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans,int initialcolor,int newColor,int delRow[],int delCol[]){
       ans[row][col]=newColor;
       int n=image.size();
       int m=image[0].size();
       for(int i=0;i<4;i++){
           int nrow=row+delRow[i];
           int ncol=col+delCol[i];
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialcolor && ans[nrow][ncol]!=newColor){
               dfs(nrow,ncol,image,ans,initialcolor,newColor,delRow,delCol);
           }
       }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int initialcolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,image,ans,initialcolor,newColor,delrow,delcol);
        return ans;
    }
};
