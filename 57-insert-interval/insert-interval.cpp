class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>ans;
        bool flag  = true;
        for(int i =0; i<intervals.size(); i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            int a = newInterval[0];
            int b = newInterval[1];
            vector<int>temp = {a,b};
            vector<int>tec = {x,y};
            if(x>=a && flag){
               ans.push_back(temp);
               flag  = false;
            }
            ans.push_back(tec);
        }
        if(flag==true){
            ans.push_back({newInterval[0],newInterval[1]});
        }
        vector<vector<int>>an;
        int start  = ans[0][0];
        int end   =  ans[0][1];
        for(int i =1; i<ans.size(); i++){
            int s = ans[i][0];
            int e = ans[i][1];
            // case 1 when new interval lies completely in my interval
            if(s>=start && e<=end){
                continue;
            }
            // case 2 when start ofn nwe interval lies in my interval 
            else if(s>=start && s<=end && e>=end){
                end  = max(end,e);
            }
            // case 3 
            else{
                an.push_back({start,end});
                start  = s;
                end  = e;
            }
        }
        an.push_back({start,end});
            for(int i=0; i<ans.size(); i++){
            cout<<ans[i][0]<<" "<<ans[i][1];
        }
        // for(int i=0; i<an.size(); i++){
        //     cout<<an[i][0]<<" "<<an[i][1];
        // }
        return an;




        
    }
};