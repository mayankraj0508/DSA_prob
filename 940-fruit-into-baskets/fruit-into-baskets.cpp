class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int  a = -1;
        int  b = -1;
        int ans = 0;
        int sum = 0;
        vector<int>freq(2,0);
        while(i<nums.size() && j<nums.size()){
            if(a==-1 && b==-1){
                a = nums[j];
                freq[0]++;
                sum = sum + nums[j];
                j++;
            }
            else if(a==-1){
                freq[0]++;
                a = nums[j];
                sum  = sum + nums[j];
                j++;
            }
              else if(nums[j]==a){
                freq[0]++;
                sum = sum+nums[j];
                j++;
            }
            else if(b==-1){
                freq[1]++;
                b = nums[j];
                sum  = sum + nums[j];
                j++;
            }
          
            else if(nums[j]==b){
                freq[1]++;
                sum   =sum + nums[j];
                j++;
            }

            else {
                ans = max(ans,j-i);
                while(i<nums.size()){
                    if(nums[i]==a){
                        freq[0]--;
                        sum  = sum-nums[i];
                        if(freq[0]==0){
                            break;
                        }
                    }
                    else{
                        freq[1]--;
                        sum  = sum-nums[i];
                        if(freq[1]==0){
                            break;
                        }
                    }
                    i++;
                }
                i++;
                if(freq[0]==0){
                    a =-1;
                }
                if(freq[1]==0){
                    b = -1;
                }



            }
           
        }
        ans = max(ans,j-i);
        return ans;
    }
};