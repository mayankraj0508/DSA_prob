class Solution {
public:
  long long  find(vector<int>& nums, long long  mid) {
        long long sum  = 0;;
        long long stud = 0;
        for(int i = 0; i<nums.size(); i++){
            sum  = sum+nums[i];
       
            if(sum==mid){
                sum  = 0;
                stud++;
            }
            if(sum>mid){
                sum  = nums[i];
                stud++;
            }
        }
        if(sum!=0) stud++;
        return stud;
    }
    int findPages(vector<int>& nums, int k) {

        if(nums.size() < k)
            return -1;

        long long lo = LLONG_MIN;
        long long  hi = 0;
        long long  ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            lo = max(lo, (long long)nums[i]);
            hi += nums[i];
        }
        while(lo <= hi) {

            long long  mid = lo + (hi - lo) / 2;

            if(find(nums, mid) <= k) {
                ans = min(ans,mid);
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        if(ans==INT_MAX) return  -1;
        return ans ;
    }
};