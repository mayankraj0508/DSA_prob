class Solution {
public:
vector<int>parent;
vector<int>size;
   // map of email and parent
   int find(int a){
       if(a==parent[a]){
        return a;
       }
       return parent[a] = find(parent[a]);
   }

   void unions(int a, int b){
      a= find(a);
      b = find(b);
      if(a==b) return ;
      if(size[a]>=size[b]){
        size[a] = size[a]+size[b];
        parent[b]  = a;

      }
      else{
        size[b] = size[a]+size[b];
        parent[a]  = b;
      }
   }
   unordered_map<string,vector<int>>m;

    void f(vector<vector<string>>&accounts){
        for(int i = 0; i<accounts.size(); i++){
            for(int j = 1; j<accounts[i].size(); j++){
                m[accounts[i][j]].push_back(i);
               
            }
        }

    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       
        int n = accounts.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0; i<accounts.size(); i++){
            parent[i] = i;
        }
        f(accounts);
        for(auto x: m){
            // x.second 
            for(int i = 0; i<x.second.size()-1; i++){
                unions(x.second[i],x.second[i+1]);
            }
        }
        
        unordered_map<int,unordered_set<string>>ma;
        for(int i  =0; i<accounts.size(); i++){
            int p = find(parent[i]);
            string ps = accounts[p][0];
        //    if(ma.find(p)==ma.end()){
              
                    for(int j = 1; j<accounts[p].size(); j++){
                        ma[p].insert(accounts[p][j]);
                    }
                
                
            
       
    
                   for(int j = 1; j<accounts[i].size();j++){
                      ma[p].insert(accounts[i][j]);
                   }
                
            
        }
        vector<vector<string>>ans;
        for(auto x: ma){
        
            vector<string>temp;
            int key   = x.first;
            string name = accounts[key][0];
            temp.push_back(name);
            for(auto p : x.second){
                temp.push_back(p);
            }
            sort(temp.begin()+1,temp.end());
            ans.push_back(temp);
        }
        return ans ;

        
    }
};