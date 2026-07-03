class Solution {
public:
   void dfs(vector<vector<int>>&image,int actual,int dup,int i,int j){
       if(i>=image.size()||i<0||j>=image[0].size()||j<0){
        return ;
       }
       if(image[i][j]!=dup){
           return ;
       }
        int dx[4] = {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        for(int  x =0; x<4; x++){
        
                image[i][j] = actual;

                dfs(image,actual,dup,i+dx[x],j+dy[x]);
            
        }

   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int actual = color;
        int dup = image[sr][sc];
        if(dup==actual){
            return image;
        }
        dfs(image,actual,dup,sr,sc);
        return image;
   
        
    }
};