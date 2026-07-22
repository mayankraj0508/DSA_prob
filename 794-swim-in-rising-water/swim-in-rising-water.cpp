class Solution {
public: 
  
  #define pp pair<int,pair<int,int>>
   int swimInWater(vector<vector<int>>& grid) {
   vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
   priority_queue<pp,vector<pp>,greater<pp>>pq;
   //grid[0][0] = true;
   pq.push({grid[0][0],{0,0}});
   int dir[4] = {0,0,1,-1};
   int dic[4]  = {1,-1,0,0};
   while(pq.size()>0){
    auto curr = pq.top();
    pq.pop();
    int t =  curr.first;
    int row = curr.second.first;
    int col = curr.second.second;
    if(row==grid.size()-1&&col==grid[0].size()-1){
        return t;
    }
    if(visited[row][col]==true){
        continue;
    }
    else{
        visited[row][col] = true;
        for(int i =0; i<4; i++){
            int nr = row + dir[i];
            int nc = col +  dic[i];
            if(nr>=0&&nc>=0&&nr<grid.size()&&nc<grid[0].size()&&visited[nr][nc]==false){
                  pq.push({max(t,grid[nr][nc]),{nr,nc}});
            }
        }
        
    }

   }
   return -1;


       
   }
};
