class Solution {
public:

    pair<int,int> parse(string s){
        int coeff = 0;
        int constant = 0;

        int sign = 1;
        int i = 0;

        while(i < s.size()){

            if(s[i] == '+'){
                sign = 1;
                i++;
            }
            else if(s[i] == '-'){
                sign = -1;
                i++;
            }

            int num = 0;
            bool hasNum = false;

            while(i < s.size() && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                hasNum = true;
                i++;
            }

            if(i < s.size() && s[i] == 'x'){
                if(!hasNum) num = 1;
                coeff += sign * num;
                i++;
            }
            else{
                constant += sign * num;
            }
        }

        return {coeff, constant};
    }

    string solveEquation(string equation) {

        string lhs = "";
        string rhs = "";

        int i = 0;

        while(equation[i] != '='){
            lhs += equation[i];
            i++;
        }

        i++;

        while(i < equation.size()){
            rhs += equation[i];
            i++;
        }

        auto left = parse(lhs);
        auto right = parse(rhs);

        int coeff = left.first - right.first;
        int constant = right.second - left.second;

        if(coeff == 0 && constant == 0)
            return "Infinite solutions";

        if(coeff == 0)
            return "No solution";

        return "x=" + to_string(constant / coeff);
    }
};