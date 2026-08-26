// class Solution {
// public:
//      vector<vector<int>>dp;
//      int f(int i, int j,vector<vector<int>>&triangle){
//         if(i>=triangle.size()) return 0;
//         if(j>=triangle[i].size()) return INT_MAX;
//          if(dp[i][j]!=INT_MAX) return dp[i][j];
//         return dp[i][j] =  min(triangle[i][j]+f(i+1,j,triangle),triangle[i][j]+f(i+1,j+1,triangle));
//      }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         dp.resize(300,vector<int>(300,INT_MAX));
//         return f(0,0,triangle);
        
//     }
// };
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for(int i = triangle.size() - 2; i >= 0; i--) {
            for(int j =triangle[i].size()-1; j >=0; j--) {

                triangle[i][j] += min(
                    triangle[i+1][j],
                    triangle[i+1][j+1]
                );
            }
        }

        return triangle[0][0];
    }
};