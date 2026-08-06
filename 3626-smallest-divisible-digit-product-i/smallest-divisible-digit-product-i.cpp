class Solution {
public:
    int smallestNumber(int n, int t) {
        int x = n;
        string s = to_string(x);
        int pro = 1;
        for(int i = 0; i<s.size(); i++ ){
            pro  = pro*(s[i]-'0');
        }

        while(pro%t!=0){
            int num = stoi(s);
            num++;
            s = to_string(num);
         pro = 1;
        for(int i = 0; i<s.size(); i++ ){
            pro  = pro*(s[i]-'0');
        }
            
        }
        int c = stoi(s);
        return c ;
        
    }
};