class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string  x = to_string(low);
        string  y = to_string(high);
        int xx = x.size();
        int yy = y.size();
        char ch  = x[0];
        string temp = "";
        while(true){
            int prev  = 0;
            int size = 0;
            bool flag  = false;

            while(size<xx){
                int value = ch-'0' + prev;
                if(value==10){
                    flag  = true;
                    break;
                }
                temp = temp + char(ch+prev);
                prev++;
                size++;
            }
            int num = stoi(temp);
            if(num>=low && num<=high && flag==false){
                ans.push_back(num);
            }
        
            
            temp = "";
             ch++;
             if(flag ==true){
                ch = '1';
                xx++;
             }
             if(xx>yy){
                break;
             }
             
          
           
        }
        return ans ;

        
    }
};