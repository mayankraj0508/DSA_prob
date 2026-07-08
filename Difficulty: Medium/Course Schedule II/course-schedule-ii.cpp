class Solution {
  public:
    vector<int>indegree;
    void bfs_topo(vector<vector<int>>&graph, vector<int>&ans){
        queue<int>q;
        for(int i =0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                int x = q.front();
                q.pop();
                ans.push_back(x);
                for(auto neighbour : graph[x]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int n, vector<vector<int>> &edges) {
        vector<vector<int>>graph(n);
        indegree.resize(n,0);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        vector<int>ans;
        bfs_topo(graph,ans);
        if(ans.size()<n){
            return {};
        }
        return ans ;
    }
};