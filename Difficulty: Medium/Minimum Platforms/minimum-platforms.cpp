class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
         
         sort(arr.begin(),arr.end());
         sort(dep.begin(),dep.end());
         int i = 0;
         int j = 0;
         int ans  = 0;
         int ans2 = 0;
         while(i<arr.size() && j<dep.size()){
             if(arr[i]<=dep[j]){
                 ans++;
                 ans2 = max(ans,ans2);
                 i++;
             }
             else{
                 ans--;
                 j++;
             }
            
             
             
         }

         return ans2;
         
         
         
         
         
    }
};
