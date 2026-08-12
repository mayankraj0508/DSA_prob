class Solution {
  public:
    void merge(vector<int>&nums, int i, int mid, int j , int &ans){
        // merging 
        vector<int>temp;
        int p1 = i;
        int p2 = mid+1;
        while(p1<=mid && p2<=j){
            if(nums[p1]>nums[p2]){
                ans  =  ans + mid-p1+1;
                temp.push_back(nums[p2]);
                p2++;
            }
            else{
                temp.push_back(nums[p1]);
                p1++;
            }
        }
        while(p1<=mid){
            temp.push_back(nums[p1]);
            p1++;
        }
        while(p2<=j){
            temp.push_back(nums[p2]);
            p2++;
        }
        for(int idx = i; idx<=j; idx++){
            nums[idx] = temp[idx-i];
        }
    }
    void mergesort(vector<int>&nums, int i , int j, int &ans){
        if(i==j || i>j){
            return ;
        }
        int mid  = i+(j-i)/2;
        mergesort(nums,i,mid,ans);
        mergesort(nums,mid+1,j,ans);
        //merging 
        merge(nums,i,mid,j, ans);
    }
    int inversionCount(vector<int> &nums) {
        // merge sort 
        int ans  = 0;
        mergesort(nums,0,nums.size()-1, ans );
        return ans ;
        
       
        
    }
};