class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& nums) {
        int m  = nums.size();
        int n = nums[0].size();
        for(int i=0; i<m; i++){
            int a = n-2;
            int b = n-1; 
            while(a>=0 && b>=0){
                if(nums[i][b]=='.' && nums[i][a]=='#'){
                    swap(nums[i][b],nums[i][a]);
                }
                else if(nums[i][b]=='.' && nums[i][a]=='.'){
                    a--;
                }
                else if(nums[i][a]=='*' && nums[i][b]=='.'){
                    b = a;
                    a--;
                }
                else{
                    a--;
                    b--;
                }
               
            }
        }
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0; i<m; i++){
            for(int j = 0; j<n;j++){
                ans[j][m-i-1] = nums[i][j];
            }
        }
        return ans;
        
    }
};