class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int pr = m*n;
        vector<int>flatten(m*n);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int index = i*n + j ;
                index = (index + k)%pr;
                flatten[index] = grid[i][j];

            }
        }
        int i = 0;
        int j = 0;
        int p = 0;
        while(i<m && j<n){
            grid[i][j] = flatten[p];
            j++;
            p++;
            if(j==n){
                j = 0;
                i++;
            }
        }
        return grid;
        
        
    }
};