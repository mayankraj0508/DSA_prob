class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
         vector<int>left(n);
         left[0] = 1;
         for(int i =1; i<n; i++){
              if(rating[i]>rating[i-1]){
                left[i] = left[i-1]+1;
              }
              else{
                left[i] = 1;
              }
         }
         int sum  = 0;
        int  curr = 1;
        sum  = max(curr,left[n-1]);
           for(int i =n-2; i>=0; i--){
              if(rating[i]>rating[i+1]){
                curr = curr+1;
                sum  = sum + max(left[i],curr);
              }
              else{
                 curr = 1;
                 sum  = sum + max(left[i],curr);
              }
         }
       
         return sum  ;
     }
};