class Solution {
public:
    int f(int i , vector<vector<int>>&nums){
        int n = nums[0].size();
        vector<int>input(n);
        for(int j = 0; j<n; j++){
            // check for each row
              input[j] =  nums[i][j];

        }
        vector<int>nse(n);
        nse[n-1] = n;
        stack<int>st;
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(st.size() && input[i]<=input[st.top()]){
                st.pop();
            }
            if(st.size()) nse[i] = st.top();
            else nse[i] = n;
            st.push(i);
        }

        vector<int>pse(n);
        pse[0] = -1;
        stack<int>rt;
        rt.push(0);
        for(int i = 1; i<n; i++){
            while(rt.size() && input[i]<=input[rt.top()]){
                rt.pop();;
            }
            if(rt.size()) pse[i] = rt.top();
            else pse[i] = -1;
            rt.push(i);
        }
        int ans  = 0; 
        for(int i = 0; i<n; i++){
             int left  = nse[i]-i-1;
             int right  = i-pse[i]-1;
             ans  = max(ans,(left+right+1)*input[i]);
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m   = matrix.size();
        int n   = matrix[0].size();
        bool flag  = true;
        vector<vector<int>>nums(m,vector<int>(n));

        for(int j = 0; j<n; j++){
            if(matrix[0][j]=='0'){
                nums[0][j] = 0;
            }
            else{
                nums[0][j] = 1;
                flag  = false;


            }

        }
        for(int i = 1; i<m; i++){
            for(int j  = 0; j<n; j++){
                if(matrix[i][j]=='0'){
                    nums[i][j] = 0;
                }
                else{
                    nums[i][j] = nums[i-1][j]+1;
                    flag  = false;
                }
            }
        }
        if(flag) return 0;
        int ans  = 1;
     for(int i = 0; i<m; i++){
        ans  = max(ans,f(i,nums));


     }

      return ans ;
        
    }
};