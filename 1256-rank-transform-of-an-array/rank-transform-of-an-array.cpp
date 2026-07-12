class Solution {
public:
   #define pp pair<int,int>
   static bool cmp(pp &a , pp &b){
      return a.first<b.first;
   }
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<pp>ss(arr.size());
       for(int i = 0; i<arr.size(); i++){
          ss[i] = {arr[i],i};
       }
       sort(ss.begin(),ss.end(),cmp);
       vector<int>ans(arr.size());
       int rank  = 0;
       int prev = INT_MIN;
       for(int i= 0; i<ss.size(); i++){
            int num = ss[i].first;
            int idx = ss[i].second;
           
            if(num>prev){
            rank++;
            prev  = num;
            }
            ans[idx] = rank;
       }
       return ans ;
        
    }
};