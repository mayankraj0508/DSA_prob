class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int m   = nums.size();
        int n = nums[0].size();
        int temp = 1;
        for(int i = 0; i<m; i++){
            for(int j  = 0; j<n; j++){
                if(nums[i][j]==0){
                    if(j==0){
                        temp = 0;
                      

                    }
                    else if(i==0){
                        nums[i][0] = 0;
                        
                    }
                    else{
                        nums[i][0] = 0;
                        nums[0][j] = 0;
                    }
                }
            }
        }
         
         for(int i = m-1;  i>0; i--){
            for(int j = n-1; j>0 ; j--){
             
                    if(nums[i][0]==0 || nums[0][j]==0){
                        nums[i][j]  = 0;
                    }
                
            }
         }
         for(int j = n-1; j>0; j--){
            
                if(nums[0][0]==0){
                    nums[0][j] = 0;
                }
             
         }
         for(int i = 0; i<m; i++){
        
            
                
                    if(temp==0){
                        nums[i][0] = 0;
                    }
                
           
         }
       
        
    }
};