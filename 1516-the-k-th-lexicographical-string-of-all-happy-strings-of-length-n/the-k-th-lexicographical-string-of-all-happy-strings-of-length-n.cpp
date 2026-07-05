class Solution {
public:
    string ans  = "";
    void f(string temp, int size, char last, int k, int &x, int n){
        if(size>n){
            return ;
        }
        if(size==n){
            x++;
            if(x==k){
                ans = temp;
              
            }
            
        }
        if(last=='z'){
            temp = temp+'a';
            f(temp,size+1,'a',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
            temp = temp + 'b';
            f(temp,size+1,'b',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
            temp = temp+'c';
            f(temp,size+1,'c',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
            
        }
        else if(last=='a'){
            temp = temp+'b';
            f(temp,size+1,'b',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
             temp = temp+'c';
            f(temp,size+1,'c',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
        }
          else if(last=='b'){
            temp = temp+'a';
            f(temp,size+1,'a',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
              temp = temp+'c';
            f(temp,size+1,'c',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
        }
        else{
             temp = temp+'a';
            f(temp,size+1,'a',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }
              temp = temp+'b';
            f(temp,size+1,'b',k,x,n);
            if(temp.size()){
                temp.pop_back();
            }

        }



    }
    string getHappyString(int n, int k) {
        string temp = "";
        int x = 0;
        f(temp,0,'z',k,x,n);
        return ans;
        
        
    }
};