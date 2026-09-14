class Solution {
  public:
    vector<string>ans;
    vector<vector<bool>>visited;
    void f(int i, int j,vector<vector<int>>&maze,string &temp){
        if(i>=maze.size() || i<0 || j>=maze[0].size() || j<0){
            return ;
            
        }
        if(maze[i][j]==0) return ;
        if(visited[i][j]==true) return ;
        if(i==maze.size()-1 && j==maze[i].size()-1) {
            ans.push_back(temp);
        }
        visited[i][j] = true;
        temp.push_back('R');
        f(i,j+1,maze,temp);
        if(temp.size()) temp.pop_back();
        temp.push_back('D');
        f(i+1,j,maze,temp);
        if(temp.size()) temp.pop_back();
        temp.push_back('L');
        f(i,j-1,maze,temp);
        if(temp.size()) temp.pop_back();
        temp.push_back('U');
        f(i-1,j,maze,temp);
        if(temp.size()) temp.pop_back();
        visited[i][j] = false;
        return ;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        visited.resize(maze.size(),vector<bool>(maze[0].size(),false));
        string temp = "";
        f(0,0,maze,temp);
        sort(ans.begin(),ans.end());
        return ans ;
        
    }
};