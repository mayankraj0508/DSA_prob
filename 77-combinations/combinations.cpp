class Solution {
public:
    vector<vector<int>>ans;
    void f(int sum ,int n,int k,vector<int>&temp){
           if(temp.size()==k){
            ans.push_back(temp);
            // if(temp.size())
            // temp.pop_back();
            return ;
         }
        if(sum>n){
            // if(temp.size())
            // temp.pop_back();
            return ;
        }
      
         temp.push_back(sum);
         f(sum+1,n,k,temp);
         if(temp.size())
         temp.pop_back();
         f(sum+1,n,k,temp);   
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        f(1,n,k,temp);
        return ans;
        
    }
};