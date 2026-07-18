class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int find(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    bool unions(int &a, int &b){
        a = find(a);
        b = find(b);
        if(a==b){
            return true;
        }
        if(size[a]>=size[b]){
            parent[b] = a;
            size[a]+=size[b];
        }
        else{
            parent[a] = b;
            size[b]+=size[a];
        }
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        size.resize(n,1);
        int count  = 0;
        unordered_set<int>visited;
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            visited.insert(u);
            visited.insert(v);
            bool ans  = unions(u,v);
          
            if(ans==true){
                count++;
                continue;
            }
          
        }
        // connected components 
        int c = 0;
        for(int i = 0; i<n; i++){
            if(parent[i]==i){
                c++;
            }
        }
        if(c-1<=count){
            return c-1;
        }
       return -1 ;


        
    }
};