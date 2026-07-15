
class Solution {
  public:
    #define pp pair<int,int>
    vector<vector<pp>>graph;
    unordered_set<int>visited;
    void bfs(priority_queue< pp, vector<pp>,greater<pp>>&pq,unordered_map<int,pp>&m){
        while(pq.size()){
            int node = pq.top().second;
            int wt   = pq.top().first;
            if(visited.find(node)!=visited.end()){
                pq.pop();
                continue;
            }
            visited.insert(node);
            pq.pop();
            for(auto neighbour : graph[node]){
                if(visited.find(neighbour.first)==visited.end() && neighbour.first!=node && m[neighbour.first].first>neighbour.second){
                    m[neighbour.first].first = neighbour.second;
                    m[neighbour.first].second = node;
                    pq.push({neighbour.second,neighbour.first});
                    
                    
                }
                
            }
            
        }
        
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        graph.clear();
        visited.clear();
        graph.resize(V);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
            
        }
        // prims algo 
        //map for node,{wt,paren}
        unordered_map<int,pp>m;
        int src = 0;
        m[src]= {0,-1};
     priority_queue< pp, vector<pp>,greater<pp>>pq;
        pq.push({0,0});
        for(int i = 1; i<V; i++){
            m[i] = {INT_MAX,-1};
        }
        bfs(pq,m);
        int sum  = 0;
        for(auto x: m){
            if(x.second.first!=INT_MAX)
            sum = sum + x.second.first;
        }
        return sum ;
        
        
        
    }
};