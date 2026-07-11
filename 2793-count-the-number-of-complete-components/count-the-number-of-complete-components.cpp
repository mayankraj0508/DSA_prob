class Solution {
public:
    unordered_set<int>visited;
    vector<vector<bool>>visited2;
    #define pp pair<int,int>
    void bfs(vector<vector<int>>&graph, int i, int &nodes, int &edges){
        queue<pp>q;
        q.push({i,-1});
        while(q.size()){
            int n = q.front().first;
            int p = q.front().second;
            q.pop();
            if(visited.find(n)==visited.end()){
                visited.insert(n);
                nodes++;
            }
            for(auto  neighbour : graph[n]){
                if(visited2[n][neighbour]==false){
                    visited2[n][neighbour] = true;
                    visited2[neighbour][n] = true;
                    edges++;
                    q.push({neighbour,n});
                
                }
            }
        }

    }
    int f(int n){
        return (n)*(n-1)/2;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(int i = 0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        visited2.resize(n,vector<bool>(n,false));
        int count_c = 0;
        int non_c = 0;
        for(int i =0; i<n; i++){
            if(visited.find(i)==visited.end()){
                count_c++;
                int nodes = 0;
                int edges = 0;
                bfs(graph,i,nodes,edges);
                if(edges<f(nodes) && nodes!=1 && nodes!=2){
                    non_c++;
                }
            }
        }
        return count_c-non_c;


        
    }
};