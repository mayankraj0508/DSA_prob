class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0; 
        int j = 0;
        int l = k;
        int mx_size = 0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]==1){
                j++;
            }
            else{
                if(k){
                    k--;
                    j++;
                }
            
                else{
                    mx_size = max(mx_size,j-i);
                   
                        while(i<nums.size() && nums[i]!=0){
                            i++;
                        }

                        i++;
                        k++;
    

                }
            }
        }
        mx_size = max(mx_size,j-i);
        return mx_size;




        
    }
};