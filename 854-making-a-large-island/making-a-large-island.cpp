class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int m,n;
    int find(int a){
        if(parent[a]==a){
            return a ;
        }
        return parent[a] = find(parent[a]);
    }
    void unions(int a, int b){
        a =  find(a);
        b =  find(b);
        if(a==b){
            return;
        }
        if(size[a]>=size[b]){
            parent[b] = a;
            size[a] += size[b];
        }
        else{
            parent[a] = b;
            size[b] += size[a];
        }
       return ;
    }
     void dfs(int i, int j, vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0){
            return ;
        }
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k=0; k<4; k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[i][j]==1 && grid[nr][nc]==1){
                int ele1 = i*n+j;
                int ele2 = nr*n+nc;
                unions(ele1,ele2);

            }
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        this->m = m;
        this->n = n;
        parent.resize(m*n);
        size.resize(m*n,1);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int ele = i*n+j;
                parent[ele] = ele;
            }
        }
         
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                dfs(i,j,grid);
            }
        }
        int ans  = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==0){
                    int dx[4] = {-1,1,0,0};
                    int dy[4] = {0,0,1,-1};
                    int curr = 1;
                    unordered_set<int>par;
                    for(int k = 0; k<4; k++){
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n){
                            int ele1 = i*n +j;
                            int ele2 = nr*n+nc;
                            if(grid[nr][nc]==1){
                               int f = find(ele2);
                               par.insert(f);
                            }
                        }
                }
                for(auto x: par){
                    curr += size[x];
                }
                ans  = max(ans,curr);
                }
            }
        }
        if(ans==0){
           return m*n;
        }
        return ans ;

    
    }
};