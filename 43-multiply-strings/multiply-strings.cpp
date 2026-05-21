class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0")
            return "0";

        if(num2.size() < 2){
            int vb = num2[num2.size()-1]-'0';

            string ans = "";
            int i = num1.size()-1;
            int carry = 0;

            while(i >= 0){

                int val = vb * (num1[i]-'0') + carry;

                if(val < 10){
                    char ch = val + '0';
                    ans = ch + ans;
                    carry = 0;
                }
                else{
                    int newval = val % 10;
                    carry = val / 10;

                    char ch = newval + '0';
                    ans = ch + ans;
                }

                i--;
            }

            if(carry){
                char ch = carry + '0';
                ans = ch + ans;
            }

            return ans;
        }

        string ans = "";
        int shift = 0;

        for(int j = num2.size()-1; j >= 0; j--){

            int carry = 0;
            string bns = "";

            for(int i = num1.size()-1; i >= 0; i--){

                int b = num2[j]-'0';

                int val = b * (num1[i]-'0') + carry;

                int newval = val % 10;
                carry = val / 10;

                char ch = newval + '0';

                bns = ch + bns;
            }

            // added carry handling
            if(carry){
                char ch = carry + '0';
                bns = ch + bns;
            }

            if(ans == ""){
                ans = bns;
                shift++;
                continue;
            }

            int idx = ans.size()-1-shift;
            int idx2 = bns.size()-1;

            carry = 0;

            while(idx2 >= 0 && idx>=0){

                  int   va = ans[idx]-'0';

                int vb = bns[idx2]-'0';

                int val = va + vb + carry;

                if(val < 10){

                    char ch = val + '0';

                  
                        ans[idx] = ch;

                    carry = 0;
                }
                else{

                    int newval = val % 10;

                    char ch = newval + '0';

                   
                        ans[idx] = ch;

                    carry = val / 10;
                }

                idx2--;
                idx--;
            }
       while(idx2 >= 0){

    int val = (bns[idx2]-'0') + carry;

    if(val < 10){

        char ch = val + '0';
        ans = ch + ans;

        carry = 0;
    }
    else{

        int newval = val % 10;

        char ch = newval + '0';

        ans = ch + ans;

        carry = val / 10;
    }

    idx2--;
}

            if(carry != 0){
                char ch = carry + '0';
                ans = ch + ans;
            }

            shift++;
        }

        return ans;
    }
};