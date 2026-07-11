class Solution {
public:
    long long f (int count){
        return (long long)(count)*(count-1)/2;
    }
    unordered_set<int>visited;
    void dfs(vector<vector<int>>&graph, int i, int &count){
        if(visited.find(i)!=visited.end()){
            return ;
        }
        count++;
        visited.insert(i);
        for(auto neighbour : graph[i]){
            dfs(graph,neighbour,count);
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);

        for(int i =0; i<edges.size(); i++){
            int  u = edges[i][0];
            int  v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
         long ans  = 0;
         long temp = 0;
        for(int i = 0; i<n; i++){
            if(visited.find(i)==visited.end()){
                int count  = 0;
                dfs(graph,i,count);
                ans  =  ans + count;
                temp = temp +f(count);
            }
        }
        return f(ans)-temp;
        
    }
};