class Solution {
  public:
    unordered_map<int,unordered_map<int,int>>m;
     int f(int i , vector<int>&nums, bool last ){
         if(i>=nums.size()) return m[i][last] =  0;
         if(m[i].find(last)!=m[i].end()) return m[i][last];
         if(last==false){
             return m[i][last] = max(nums[i]+f(i+1,nums,true),f(i+1,nums,last));
         }
         else  {
             return m[i][last] =  f(i+1,nums,false);
             
         }
         
     }
    int findMaxSum(vector<int>& arr) {
        // code here
        
        return f(0,arr,false);
        
    }
};