class Solution {
public:
    int f(vector<int>&nums, int i, int j, int count){
       
        if(i>j){
            return 0;
        }
        if(count%2==0){
            return max(nums[i]+f(nums,i+1,j,count+1),nums[j]+f(nums,i,j-1,count+1));

        }
        else{
            return min(f(nums,i+1,j,count+1)-nums[i],f(nums,i,j-1,count+1)-nums[j]);
        }

    }
    bool predictTheWinner(vector<int>& nums) {
         int sum  = 0;
         for(int i =0; i<nums.size(); i++){
            sum  =  sum + nums[i];
         }
        int p1 = f(nums,0,nums.size()-1,0);
        int p2 = sum-p1;
        cout<<p1;
        return p1>=0;  
    }
};