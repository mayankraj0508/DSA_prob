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
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        indegree.resize(n,0);
        vector<vector<int>>graph(n);
        for(int i =0 ; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        bfs_topo(graph);
        if(visited.size()<n){
            return false;
        }
        return true;
    }
};