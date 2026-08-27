class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ans  = 0;
        int n = nums.size();

        while(i<n && j<n){
            if(nums[j]==1){
                j++;
            }
            else{
                if(k<=0){
                    cout<<i<<" "<<j<<endl;
                    ans  = max(ans,j-i);
                    while(i<=j){
                        if(nums[i]==0){
                            i++;
                            break;
                        }
                        else{
                            i++;
                        }



                    }
                    j++;

                }
                else{
                    k--;
                    j++;
                }
            }
           
           
        }
        cout<<i<<" "<<j;
     ans  = max(ans,j-i);
        
        return ans ;
    }
};