class Solution {
public:
    #define pp pair<int,char>
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pp>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans = "";
        while(pq.size()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            int n = ans.size();
            if(n>=2 && ans[n-1]==ch && ans[n-2]==ch ){
                if(pq.empty()){
                    break;
                }
                if(ch==ans[n-1]){
                    int freq2 = pq.top().first;
                    char ch2 = pq.top().second;
                    pq.pop();
                    ans  = ans + ch2;
                    freq2--;
                       if(freq2)
                pq.push({freq2,ch2});
                }
                if(freq)
                pq.push({freq,ch});
             
            }
            else{
                ans  =  ans + ch;
                freq--;
                if(freq)
                pq.push({freq,ch});
            }

        }
        return ans;
     
    }
};