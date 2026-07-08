class Solution {
  public:
    vector<int>indegree;
    unordered_set<int>visited;
    void bfs_topo(vector<vector<int>>&graph){
        queue<int>q;
        for(int i =0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
                visited.insert(i);
            }
        }
        
        while(q.size()){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                int x = q.front();
                q.pop();
                for(auto neighbour : graph[x]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
            }
        }
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        indegree.resize(V,0);
        vector<vector<int>>graph(V);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
            
        }
        bfs_topo(graph);
        if(visited.size()<V){
            return true;
        }
        return false;
      
    }
};