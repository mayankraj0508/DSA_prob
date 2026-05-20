class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>a;
        unordered_map<int,int>b;
        vector<int>c(A.size(),0);
        a[A[0]]++;
        b[B[0]]++;
        if(A[0]==B[0]){
            c[0] = 1;
        }

        for(int i =1; i<c.size();i++){
            a[A[i]]++;
            b[B[i]]++;
            if(A[i]==B[i]){
                c[i] = c[i-1]+1;
            }
            else if(a.find(B[i])!=a.end() && b.find(A[i])!=b.end()){
               c[i] =  c[i-1]+2;
            }
            else if(a.find(B[i])!=a.end()){
                c[i] = c[i-1]+1;
            }
            else if(b.find(A[i])!=b.end()){
                c[i] = c[i-1]+1;
            }
            else{
                c[i] = c[i-1];
            }
        }
        return c;

    }
};