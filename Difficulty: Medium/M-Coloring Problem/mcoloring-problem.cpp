class Solution {
  public:
    vector<vector<int>>graph;
    void add_edge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int v;
    bool f(int i, vector<int>&color, int m){
        if(i==v)  return true;
        
        for(int k = 1; k<=m; k++){
            bool flag  = false;
            for(int l = 0; l<graph[i].size(); l++){
                if(color[graph[i][l]]==k) {
                    flag  = true;
                    break;
                }
              
            }
            if(!flag) {
                color[i] = k;
                bool x = f(i+1,color,m);
                if(x) return true;
                color[i] = -1;
                
            }
        }
        return false;
        
        
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        this->v = v;
        graph.resize(v);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int x = edges[i][1];
            add_edge(u,x);
        }
        vector<int>color(v,-1);
        return f(0,color,m);
        
        
        
    }
};