class Solution {
public:
    int trap(vector<int>& nums) {
        int  n = nums.size();
        // vector<int>pge(n);
        // vector<int>nge(n);
        // pge[0] = -1;
        // stack<int>st;
        // st.push(0);
        // for(int i =1; i<n; i++){
        //     while(st.size() &&  nums[st.top()]<nums[i]){
        //         st.pop();
        //     }
        //     if(st.size()==0){
        //         pge[i] = -1;
        //     }
        //     else{
        //         pge[i] = st.top();
        //     }
        //     st.push(i);
        // }
        // stack<int>rt;
        // nge[n-1] = -1;
        // rt.push(n-1);
        // for(int i=n-2; i>=0 ; i--){
        //     while(rt.size() && nums[rt.top()]<=nums[i]){
        //         rt.pop();;
        //     }
        //     if(rt.size()==0){
        //         nge[i] =-1;
        //     }
        //     else{
        //         nge[i] = rt.top();
        //     }
        //     rt.push(i);
        // }
        // int sum = 0;
        // for(int  i =0; i<nums.size(); i++){
        //     if(nge[i]==-1 || pge[i]==-1){
        //         continue;
        //     }
        //     else{
        //         sum = sum  + min(nums[nge[i]],nums[pge[i]])-nums[i];
        //     }
        // }
        // return sum;   
        vector<int>premax(n);
        vector<int>sufmax(n);
        int a = nums[0];
        int b = nums[n-1];
        premax[0] = a;
        sufmax[0] = b;
        for(int i =1; i<nums.size(); i++){
            premax[i] = max(nums[i],a);
            a = premax[i];
        }
        for(int i =n-1; i>=0 ; i--){
            sufmax [i]= max(nums[i],b);
            b = sufmax[i];
        }
        int sum = 0;
        for(int i =0; i<nums.size(); i++){
            sum = sum+ min(premax[i],sufmax[i])-nums[i];
        }
        return sum;
    }
};