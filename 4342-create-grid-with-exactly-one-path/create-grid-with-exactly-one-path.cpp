class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m);
        for(int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                if(i==0){
                    ans[i].push_back('.');
                }
              else  if(j==n-1){
                    ans[i].push_back('.');
                }
                else if(i!=0 && j!=n-1){
                    ans[i].push_back('#');
                }
            }
        }
        for(int i=0; i<ans.size(); i++){
           
                cout<<ans[i]<<",";
            
        }
        
        // for(int j=0;j<n; j++){
        //     ans[0][j] = '.';
        // }
        // for(int i =0; i<m; i++){
        //     ans[i][n-1] = '#';
        // }
   return ans ;
      //  return ans ;
        
    }
};