class Solution {
public:
   long long  find(int mid, vector<int>&piles){
       long long hrs = 0;
       for(int i = 0; i<piles.size(); i++){
           if(piles[i]<=mid){
              hrs++;
           }
           else{
               int d = piles[i]/mid;
               int rem = piles[i]%mid;
               if(rem!=0) rem = 1;
               hrs = hrs + d +rem;
               
           }
       }
       return hrs;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi  = INT_MIN;
        sort(piles.begin(),piles.end());
        for(int i = 0; i<piles.size(); i++){
            hi = max(hi,piles[i]);
        }
        int ans  = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            long long  Cal  = find(mid,piles);
            if(Cal<=h){
                hi = mid-1;
                ans  = mid;

            }
            else{
                lo = mid+1;
            }
        }
        return ans ;
  
    }
};