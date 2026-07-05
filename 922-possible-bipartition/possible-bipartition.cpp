class Solution {
public:
    unordered_set<int>visited;
    bool bfs(vector<vector<int>>&graph , int i, vector<int>&colors){
        queue<int>q;
        q.push(i);
        colors[i] = 0;
        visited.insert(i);
        while(q.size()){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                int v = q.front();
                int c = colors[v];
                q.pop();
                for(int j = 0; j<graph[v].size();j++){
                    if(colors[graph[v][j]]==c){
                        return false;
                    }
                    if(visited.find(graph[v][j])==visited.end()){
                        colors[graph[v][j]] = !c;
                        visited.insert(graph[v][j]);
                        q.push(graph[v][j]);
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n+1);

        for(int i =0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>colors(n+1,-1);
        for(int i =1; i<=n; i++){
            if(visited.find(i)==visited.end()){
            bool ans  =  bfs(graph,i,colors);
            if(!ans){
                return false;
            }
            }
        }
        return true;
        
    }
};