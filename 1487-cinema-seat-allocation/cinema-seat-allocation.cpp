class Solution {
public:
    #define pp pair<int,int>
    set<pp>s;
    set<int>res;
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //vector<vector<bool>>booked(n,vector<bool>(10,false));
        for(int i = 0; i<reservedSeats.size();  i++){
            int row  = reservedSeats[i][0]-1;
            int col = reservedSeats[i][1]-1;
            s.insert({row,col});
            res.insert(row);
        }
        int ans =0;
        for(auto i:res){
          
           // for(int j = 0; j<10; j++){
              bool flag  = true;
                if(s.find({i,1})==s.end() && s.find({i,2})==s.end()  && s.find({i,3})==s.end()&& s.find({i,4})==s.end() ){
                    ans ++;
                    flag = false;
                }
                if(s.find({i,5})==s.end() && s.find({i,6})==s.end() && s.find({i,7})==s.end() && s.find({i,8})==s.end()){
                    ans++;
                    flag  = false;
                }
                else if(flag && s.find({i,3})==s.end() && s.find({i,4})==s.end() && s.find({i,5})==s.end() && s.find({i,6})==s.end()){
                    ans++;
                }
           // }
        }
        int unreserved = n-res.size();
        ans= ans+unreserved*2;
        return ans;
        
    }
};