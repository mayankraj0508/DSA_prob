class Solution {
public:
    int m ;
    int n;
    int f(int i, int j, vector<vector<int>>&nums, vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(visited[i][j]==true){
            return 0;
        }
        visited[i][j] = true;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        int ans  = nums[i][j];
        for(int k = 0; k<4; k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc] == false && nums[nr][nc]!=0){
              ans  = max(ans,nums[i][j] + f(nr,nc,nums,visited));

            }
        }
        visited[i][j] = false;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& nums) {
        int ans  = 0;
        vector<vector<bool>>visited;
      
        this->m = nums.size();
        this->n = nums[0].size();
           visited.resize(m,vector<bool>(n,false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(nums[i][j]!=0){
              
                ans  = max(ans,f(i,j,nums,visited));
                }
            }
        }
        return ans ;
        
    }
};