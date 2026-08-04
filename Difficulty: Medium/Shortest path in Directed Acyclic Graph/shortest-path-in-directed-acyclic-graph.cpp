class Solution {
  public:
    #define pp pair<int,int>
    vector<vector<pp>>graph;
    void add_edge(int u, int v, int wt){
        graph[u].push_back({v,wt});
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code her
        graph.resize(V);
        vector<int>ans(V,INT_MAX);
        for(int i = 0; i<edges.size(); i++){
             int u = edges[i][0];
             int v = edges[i][1];
             int wt= edges[i][2];
             add_edge(u,v,wt);
        }
        unordered_set<int>visited;
        int src = 0;
        ans[0] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        // minheap of wt,vertex
        pq.push({0,src});
        ans[src] = 0;
        while(pq.size()){
            int dis = pq.top().first;
            int v = pq.top().second;
            if(visited.find(v)!=visited.end()){
                pq.pop();
                continue;
            }
            pq.pop();
            visited.insert(v);
            for(auto neighbour : graph[v]){
                if(visited.find(neighbour.first)==visited.end() && ans[neighbour.first]>ans[v]+neighbour.second ){
                    pq.push({ans[v]+neighbour.second,neighbour.first});
                    ans[neighbour.first] = ans[v]+neighbour.second;
                    
                }
            }
            
        }
        for(int i = 0; i<ans.size(); i++){
            if(ans[i]==INT_MAX){
                ans[i] = -1;
                
            }
        }
        return ans ;
        
        
    }
};
