class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(int i =0; i<bookings.size(); i++){
            int startidx = bookings[i][0];
            int endidx = bookings[i][1];
            int number  = bookings[i][2];
            ans[startidx-1] = ans[startidx-1] + number;
            if(endidx<n)
            ans[endidx] = ans[endidx]-number;
        }
        for(int i = 1; i<ans.size(); i++){
            ans[i] = ans[i]+ans[i-1];
          
        }
        return ans ;
        
    }
};