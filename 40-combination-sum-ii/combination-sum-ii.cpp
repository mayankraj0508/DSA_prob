class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&candidates , int i, vector<int>temp, int sum ,int target){
        if(sum==target){
            ans.push_back(temp);
            return ;
        }
        if(i>=candidates.size() || sum>target){
            return ;
        }
        temp.push_back(candidates[i]);
        f(candidates,i+1,temp,sum+candidates[i],target);
        if(temp.size())
        temp.pop_back();
        int idx  = i+1;
        while( idx<candidates.size() && idx>=1 && candidates[idx]==candidates[idx-1]){
            idx ++;
        }
        f(candidates,idx,temp,sum,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        f(candidates,0,temp,0,target);
        return ans;

    
    }
};
