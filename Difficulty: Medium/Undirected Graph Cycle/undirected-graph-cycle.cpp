class Solution {
  public:
    #define pp pair<int,int>
     unordered_set<int>visited;
    bool bfs(int src,int v, vector<vector<int>>&graph){
       queue<pp>q;
       q.push({src,-1});
      
       
       visited.insert(src);
       while(q.size()){
           int f = q.front().first;
           int p  = q.front().second;
           q.pop();
           for(int j =0; j<graph[f].size();j++){
               if(p!=graph[f][j]){
                   if(visited.find(graph[f][j])!=visited.end()){
                       return true;
                   }
                   else{
                       
                       q.push({graph[f][j],f});
                       visited.insert(graph[f][j]);
                   }
               }
           }
       }
       return false;
    }

    bool dfs(vector<vector<int>>&graph, int i,int a,int parent,unordered_set<int>&visited){
        visited.insert(i);
        for(int j = 0; j<graph[i].size(); j++){
            if(graph[i][j]==a && parent!=a){
                return true;
            }
            else {
                if(visited.find(graph[i][j])==visited.end()){
                    if(dfs(graph,graph[i][j],a,i,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>graph(V);
        for(int i =0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        // for(int i = 0; i<V; i++){
        //     if(visited.find(i)==visited.end()){
        //         if(bfs(i,V,graph)){
        //             return true;
        //         }
        //     }
        // }
          for(int i = 0; i<V; i++){
        
                unordered_set<int>visited;
                if(dfs(graph,i,i,-1,visited)){
                    return true;
                }
            
        }
        return false;
        

    }
};