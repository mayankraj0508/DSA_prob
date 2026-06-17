class Solution {
public:
    #define pp pair<int,char>

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
       for(int i =0; i<tasks.size(); i++){
        m[tasks[i]]++;
       }

        priority_queue<pp> pq;
        for(auto x : m){
            pq.push({x.second,x.first});
        }

        int time = 0;

        while(!pq.empty()){
            int prev_time = time;
            int cycle = n + 1;

            priority_queue<pp> temp;

            while(cycle-- && !pq.empty()){
                auto p = pq.top(); pq.pop();

                int freq = p.first- 1;
                time++;

                if(freq > 0){
                    temp.push({freq,p.second});
                }
            }

            while(!temp.empty()){
                pq.push(temp.top());
                temp.pop();
            }

            if(!pq.empty() && time-prev_time<n+1){
                time = prev_time + (n + 1);
            }
        }

        return time;
    }
};