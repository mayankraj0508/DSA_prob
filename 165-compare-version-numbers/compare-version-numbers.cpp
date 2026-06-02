class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i =0;
        int j = 0;
        bool flag = true;
        while(i<version1.size() || j<version2.size()){
            string rev1 = "";
            string rev2 = "";
            while(i<version1.size() && version1[i]!='.'){
                rev1= rev1 + version1[i];
                i++;
            }
            i++;
            while(j<version2.size() && version2[j]!='.'){
                rev2 = rev2 + version2[j];
                j++;
            }
            j++;
            int k = 0;
            int p = 0;
            while(k<rev1.size() && rev1[k]=='0'){
                k++;
            }
            rev1 = rev1.substr(k,rev1.size());
              while(p<rev2.size() && rev2[p]=='0'){
                p++;
            }
            rev2 = rev2.substr(p,rev2.size());
            int a = 0;
            int b = 0;
            if(rev1=="" && rev2!=""){
                int k = rev2.size();
                while(k--){
                    rev1 = rev1+'0';
                }
            }
                if(rev2=="" && rev1!=""){
                int k = rev1.size();
                while(k--){
                    rev2 = rev2+'0';
                }
            }
            if(rev1!="")
            a = stoi(rev1);
            if(rev2!="")
            b = stoi(rev2);
            if(a>b){
                return 1;
            }
            else if(a<b){
                return -1;
            }
        }
        return 0;
        
    }
};