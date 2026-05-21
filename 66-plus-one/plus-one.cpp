class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i= digits.size()-1;
        int carry = 0;
        int val = 0;
        while(i>=0){ 
            if(i==digits.size()-1){
                val  = digits[i]+1;
                if(val<10){
                    digits[i] = val;
                    carry = 0;
                    break;
                }
                else{
                    carry = 1;
                }
                
            }
            val = digits[i]+carry;
            if(val<10){
                digits[i] = val;
                carry = 0;
                break;
            }
            else{
                carry = 1;
                digits[i]=0;
            }
            i--;

        }
        if(carry==1){
            vector<int>ans(digits.size()+1);
            ans[0] = 1;
            for(int i = 1; i<ans.size(); i++){
                ans[i]= digits[i-1];
            }
            return ans;
        }
        return digits;
        
    }
};