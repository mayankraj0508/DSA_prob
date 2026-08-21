class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
      int temp = 0;
      int m = nums.size();
      int n = nums[0].size();
      for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){

            if(j==0&& nums[i][j]==0){
                temp = -1;

            }
            else if(nums[i][j]==0){
                nums[0][j] = 0;
                nums[i][0] = 0;
            }
        }
      }
      for(int i = m-1; i>0; i--){
        for(int j = n-1; j>0; j--){
            if(nums[i][j]!=0){
                    if(nums[0][j]==0||  nums[i][0]==0){
                        nums[i][j] = 0;
                    }
                
            }
        }
      }
      for(int j = n-1; j>=0; j-- ){
        if(nums[0][j]!=0){
        if(nums[0][j]==0 || nums[0][0]==0){
            nums[0][j] = 0;
        }
      }
      }
      for(int i =m-1; i>=0; i--){
        if(nums[i][0]==0 ||  temp==-1){
            nums[i][0] = 0;
        }
      }

        
    }
};