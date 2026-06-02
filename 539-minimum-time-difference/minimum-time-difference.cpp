class Solution {
public:
    int findMinDifference(vector<string>& timepoints) {
        for(int i =0; i<timepoints.size(); i++){
            if(timepoints[i]=="00:00")
            timepoints[i] = "24:00";
        }
       sort(timepoints.begin(),timepoints.end());
       int mn = INT_MAX;
       for(int i=0; i<timepoints.size()-1; i++){
           string a = timepoints[i];
           string b = timepoints[i+1];
           string c ="";
           string d = "";
           int j =0; 
           while(j<a.size()){
              if(a[j]!=':')
               c = c+a[j];
               j++;
           }
            j=0; 
           while(j<b.size()){
              if(b[j]!=':')
               d = d+b[j];
               j++;
           }
           int  ch = stoi(c.substr(0,2));
           int dh = stoi(d.substr(0,2));
           int cm = stoi(c.substr(2,2));
           int dm = stoi(d.substr(2,2));
           int ans = 60-cm + (dh-ch-1)*60 + dm;
        
           mn = min(mn,ans);

       }
       string a = timepoints[0];
       string b = timepoints[timepoints.size()-1];
    
           string c ="";
           string d = "";
           int j =0; 
           while(j<a.size()){
              if(a[j]!=':')
               c = c+a[j];
               j++;
           }
            j=0; 
           while(j<b.size()){
              if(b[j]!=':')
               d = d+b[j];
               j++;
           }
           int  ch = stoi(c.substr(0,2));
           int dh = stoi(d.substr(0,2));
           int cm = stoi(c.substr(2,2));
           int dm = stoi(d.substr(2,2));
            int ans = 60-cm + (dh-ch-1)*60 + dm;
            mn = min(mn,1440-ans);

       return mn;
    }
};