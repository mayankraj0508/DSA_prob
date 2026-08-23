class Solution {
public:
    int maxArea(vector<int>& nums) {
       int i = 0;
       int j  = nums.size()-1;
       int ans  =0;
       while(i<j){
          int a = min(nums[i],nums[j]);
          int dist = j-i;
          ans  = max(ans,(a*dist));
          cout<<ans<<" "<<endl;
          if(a==nums[i]){
             i++;

          }
          else{
             j--;
          }

       }
       return ans ;
    }
};