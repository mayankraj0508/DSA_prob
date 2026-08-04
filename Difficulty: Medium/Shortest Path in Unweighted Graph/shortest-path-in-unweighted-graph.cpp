class Solution {
  public:
    #define pp pair<int,int>
    vector<vector<int>>graph;
    void add_edge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int  bfs(vector<vector<int>>&graph,int src, int des){
        queue<pp>q;
        unordered_set<int>visited;
        int dist  = 0;
        q.push({src,-1});
        visited.insert(src);
        while(q.size()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
            int v = q.front().first;
            int par = q.front().second;
            q.pop();
            if(v==des){
                return dist;
            }
            for(auto neighbour : graph[v] ){
                if(neighbour!=par&& visited.find(neighbour)==visited.end())
                q.push({neighbour,v});
                visited.insert(neighbour);
            }
            }
            dist++;
            
        }
     
            return -1;
    
    }
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
       if(src==dest){
           return 0;
       }
        graph.resize(V);
        for(int i = 0; i<edges.size(); i++){
            int u  = edges[i][0];
            int v  = edges[i][1];
            add_edge(u,v);
        }
       int ans  = bfs(graph,src,dest);
       if(ans<=0){
           return -1;
       }
        return ans;
        
        
        
    }
};
