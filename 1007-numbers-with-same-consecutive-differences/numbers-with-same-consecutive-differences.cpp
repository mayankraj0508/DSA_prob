class Solution {
public:

    void f(vector<int>&ans, vector<char>&nums,
           int n, int k, string temp){

        if(temp.size()==n){
            ans.push_back(stoi(temp));
            return;
        }

        for(int i=0;i<10;i++){

            if(temp.size()==0){

                // leading zero avoid
                if(i==0 && n>1) continue;

                temp.push_back(nums[i]);
                f(ans,nums,n,k,temp);
                temp.pop_back();
            }
            else{

                int last = temp.back()-'0';

                if(abs(i-last)==k){

                    temp.push_back(nums[i]);
                    f(ans,nums,n,k,temp);
                    temp.pop_back();
                }
            }
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {

        vector<char> nums =
        {'0','1','2','3','4',
         '5','6','7','8','9'};

        vector<int> ans;

        string temp="";

        f(ans,nums,n,k,temp);

        return ans;
    }
};