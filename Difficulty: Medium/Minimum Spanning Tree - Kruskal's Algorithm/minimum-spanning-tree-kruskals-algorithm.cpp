class Solution {
  public:
static bool cmp(vector<int>&a, vector<int>&b){
  return  a[2]<b[2];
}
vector<int>parent;
vector<int>size;
int find(int a){
   if(parent[a]==a){
    return a;
   }
   return parent[a] = find(parent[a]);
}
bool  unions(int &a, int &b){
   a = find(a);
   b = find(b);
   if(a==b){
     return true;
   }
   if(size[a]>=size[b]){
    size[a] = size[a] + size[b];
     parent[b] = parent[a];
   }
   else{
    size[b] = size[b] + size[a];
    parent[a] = parent[b];
   }
   return false;
}
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
parent.resize(V);
  size.resize(V,1);
   for(int i =0; i<V; i++){
    parent[i] = i;
  }
    sort(edges.begin(),edges.end(),cmp);
  vector<vector<int>>ans ;
  int e = edges.size();
  for(int i = 0; i<e; i++){
    int a  = edges[i][0];
    int b = edges[i][1];
    int wt = edges[i][2];
    bool flag  = unions(a,b);
    if(flag){
      continue;
    }
    else {
        ans.push_back({a,b,wt});
    }
  }
  int sum  = 0;
  for(int i = 0; i<ans.size(); i++){
  //  cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
    sum    = sum + ans[i][2];
  }
return sum ;
        
    }
};