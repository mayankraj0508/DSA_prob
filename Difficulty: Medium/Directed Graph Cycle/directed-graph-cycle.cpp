class Solution {
  public:
    unordered_set<int>visited;
    bool dfs(vector<vector<int>>&graph , int i,  int ref){
        visited.insert(i);
        for(int j = 0; j<graph[i].size(); j++){
           if(graph[i][j]==ref){
               return true;
           }
            if(visited.find(graph[i][j])==visited.end()&& dfs(graph,graph[i][j],ref)){
                return true;
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>graph(V);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
        for(int i =0; i<V; i++){
            visited.clear();
                if(dfs(graph,i,i)){
                    return true;
                }
            
        }
        return false;
        
    }
};