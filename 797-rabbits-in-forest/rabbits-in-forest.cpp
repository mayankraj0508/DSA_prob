class Solution {
public:
    int numRabbits(vector<int>& nums) {
        map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int ans  = 0;
        // return ans ;

        for(auto x:m){
            int freq = x.second;
            int answer = x.first;
            if(answer==0){
                ans  =  ans + freq;
            }
            else{
                int div = freq/(answer+1);
                int rem= freq%(answer+1);
                if(rem==0){
                    ans  =  ans + div*(answer+1);
                }
                else if(div==0){
                    ans  =  ans + answer+1;
                }
                else{
                    ans  =  ans + div*(answer+1) + answer+1;

                }
           
            }
          
        }
        return ans ;
    }
};