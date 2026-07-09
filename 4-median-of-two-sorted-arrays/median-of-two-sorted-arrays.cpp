class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     if(nums1.size() > nums2.size())
    return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int number = 0;
        if(n%2!=0){
           number = (n+1)/2;
        }
        else{
            number = n/2;
        }
        int mn = min(n1,n2);
        int lo = 0;
        int hi = mn;
        while(lo<=hi){
            int  mid =lo+(hi-lo)/2;
           int mid2 = number - mid;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
           int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
           int  l1 = (mid > 0) ? nums1[mid-1] : INT_MIN;
            int r1 = (mid < n1) ? nums1[mid] : INT_MAX;
           
            if(l1<=r2  && l2<=r1){
                if(n%2==0){
                   int ans = max(l1,l2) + min(r1,r2);
                   double final_ans = (double)ans/2;
                   return final_ans;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return -1;


        
    }
};