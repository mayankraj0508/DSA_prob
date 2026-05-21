class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>v;
        int mxfreq = 1;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
            mxfreq = max(mxfreq,m[nums[i]]);
        }
        for(auto x:m){
            if(x.second==mxfreq){
                v.push_back(x.first);
            }
        }
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        int size = INT_MAX;;
        for(int i=0; i<v.size(); i++){
            bool flag = true;
            int first = 0;
            int last = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]==v[i] && flag){
                    first = j;
                    flag = false;
                }
                else if(nums[j]==v[i] && flag==false){
                    last = j;
                }
            }
            if(last==0){
                last=first;
            }
            size = min(size,last-first+1);
        }
        return size;
    }
};