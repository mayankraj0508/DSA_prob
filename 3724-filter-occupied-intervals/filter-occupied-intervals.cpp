class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freestart, int freeend) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end(),cmp);
        int start  = occupiedIntervals[0][0];
        int end  = occupiedIntervals[0][1];
        vector<vector<int>>ans;
     
        for(int i =1; i<occupiedIntervals.size(); i++){
            int s = occupiedIntervals[i][0];
            int e  = occupiedIntervals[i][1];
            //case 1 - if new interval lies completely inside  my interval
           
            if(s>=start && e<=end){
                
                continue;
            }
            else if(s>=start && s<=end && e>=end){
                end  = max(end,e);
        
            }
            else{
                if(s-end==1){
                    end  = max(e,end);
                    //ans.push_back({start,end});
                }
                else{
                ans.push_back({start,end});
                start  = s;
                end  = e;
                }
                
            } 
        }
       
        ans.push_back({start,end});
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i][0]<<" " <<ans[i][1];
        }
    
        vector<vector<int>>finalans;
        
        for(int i =0; i<ans.size(); i++){
            int s = ans[i][0];
            int e = ans [i][1];
            // case 1 - 
            if(freeend<s){
                finalans.push_back({s,e});
            }
           else  if(freestart>e ){
                finalans.push_back({s,e});
                continue;
            }
            else if(freestart==s){
                if(freeend>=e){
                    continue;
                }
                else{
                    finalans.push_back({freeend+1,e});
                    
                }
                
            }
            else if(freestart>s){
                if(freeend>=e){
                    finalans.push_back({s,freestart-1});
                }
                else{
                    finalans.push_back({s,freestart-1});
                    finalans.push_back({freeend+1,e});
                }
            }
            else if(freestart<s){
                if(freeend>=e){
                    continue;
                }
                else{
                    finalans.push_back({freeend+1,e});
                }
            }
            
        }
        cout<<endl;
      
        return finalans;
        
    }
};