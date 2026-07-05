class Solution {
public:
   #define pp pair<int,char>
   vector<int>colors;
  bool bfs(vector<vector<int>>&graph,int src){
       queue<int>q;
       q.push(src);
       colors[src] = 0;
       while(q.size()){
        int sz = q.size();
        for(int i =0; i<sz; i++){
            int v = q.front();
           int c = colors[v];
           q.pop();
            for(int j = 0; j<graph[v].size(); j++){
                if(colors[graph[v][j]]==c){
                            return false;
                 }
                if(colors[graph[v][j]]==-1){
                    
                        q.push(graph[v][j]);
                       
                        colors[graph[v][j]] = !c;
      
                }
            }

        }
       }
       return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        colors.resize(graph.size(),-1);
        int A = 0;
        int B  = 0;
        for(int i =0; i<graph.size(); i++){
        if(colors[i]==-1){
        bool ans  = bfs(graph,i);
        if(ans==false){
            return false;
        }
        }
        }
        return true ;
        
    }
};