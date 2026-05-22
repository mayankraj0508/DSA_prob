class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&candidates,int i, int sum , int target,vector<int>temp){
        if(sum==target){
            ans.push_back(temp);
            if(temp.size())
            temp.pop_back();
            return;
        }
        if(i>=candidates.size() || sum>target){
            if(temp.size())
            temp.pop_back();
            return ;
        }
        temp.push_back(candidates[i]);
      //  f(candidates,i+1,sum+candidates[i],target,temp);
        f(candidates,i,sum+candidates[i],target,temp);
        if(temp.size())
        temp.pop_back();
        f(candidates,i+1,sum,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        f(candidates,0,0,target,temp);
        return ans;
 
    }
};