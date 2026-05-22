class Solution {
public:
    static bool cmp(string &a, string &b){
         return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr(nums.size());
        for(int i =0; i<nums.size();i++){
            arr[i] = to_string(nums[i]);
        }
        sort(arr.begin(),arr.end(),cmp);
        string ans = "";
        int i =0;
        while(i<arr.size()){

            ans = ans+arr[i];
            i++;
            
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
      
        }
    
        
    
};