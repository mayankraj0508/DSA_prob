class Solution {
public:
    vector<int>size;
    vector<int>parent;
    int find(int a ){
        if(parent[a]==a){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    void unions(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return ;
        if(size[a]>=size[b]){
            size[a] += size[b];
            parent[b] = a;
        }
        else{
            size[b] += size[a];
            parent[a] = b;
        }
        return ;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
         size.resize(m*n,1);
         parent.resize(m*n);
         for(int i = 0; i<m*n ; i++){
            parent[i] = i;
         }
         int time  = 0;
         int first = 0;
         int last =m*n-1;
         while(true){
           
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    int ele = i*n+j;
                    if(grid[i][j]<=time){
                        
                        int dx[4] = {-1,1,0,0};
                        int dy[4] = {0,0,1,-1};
                        for(int k = 0; k<4; k++){
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]<=time){
                            int ele2 = nr*n+nc;
                        
                            unions(ele,ele2);
                        }
                        }


                    }
                }
            }
             if(find(parent[first])==find(parent[last])){
                return time ;
            }
            time++;
         }
         return time ;

        
    }
};