class Solution {
  public:
    unordered_set<int>final;
    unordered_set<int>visited;
    vector<int>indegree;
    // void dfs(vector<vector<int>>&graph,int i,vector<bool>&path){
    //     if(visited.find(i)!=visited.end()){
    //         if(outdegree[i]==0){
    //             for(int i = 0; i<path.size(); i++){
    //                 if(path[i]==true){
    //                     final.insert(i);
    //                 }
    //             }
    //             return ;
    //         }
    //         return ;
    //     }
    //     visited.insert(i);
    //     path[i] = true;
    //     for(auto neighbour : graph[i]){
    //         dfs(graph,neighbour,path);
    //     }
    //     path[i] = false;
    // }
    vector<int> safeNodes(int V, vector<vector<int>>& prerequisites) {
        indegree.resize(V,0);
        vector<vector<int>>graph(V);
        //reversal of graph is done 
        for(int i =0 ; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
         vector<int>ans;
        //  unordered_set<int>visited;
       for(int i = 0; i<indegree.size(); i++){
           if(indegree[i]==0){
               q.push(i);
            //   visited.insert(i);
           }
       }
       while(q.size()){
           int x = q.front();
           ans.push_back(x);
           q.pop();
           for(auto neighbour : graph[x]){
               indegree[neighbour]--;
               if(indegree[neighbour]==0){
                   q.push(neighbour);
               }
           }
       }
       return ans ;
   
        
    }
};