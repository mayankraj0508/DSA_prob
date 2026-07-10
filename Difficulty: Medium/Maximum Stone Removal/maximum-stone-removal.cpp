class Solution {
  public:
     unordered_set<int>visited;
     void dfs(int  i, vector<vector<int>>&graph){
         if(visited.find(i)!=visited.end()){
             return ;
         }
         visited.insert(i);
         for(auto neighbour : graph[i]){
             dfs(neighbour,graph);
         }
     }
    int maxRemove(vector<vector<int>>& stones) {
        vector<vector<int>>graph(20005);
        unordered_set<int>node;
        for(int i =0; i<stones.size(); i++){
            int u  = stones[i][0];
            int v =  stones[i][1]+10000;
            graph[u].push_back(v);
            graph[v].push_back(u);
            node.insert(u);
            node.insert(v);
        }
       int count  = 0; 
        for(auto x : node){
            if(visited.find(x)==visited.end()){
                count++;
                dfs(x,graph);
            }
        }
        int n   = stones.size();
        return n-count;
        
    }
};