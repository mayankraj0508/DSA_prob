class Solution {
public:
    long long f(int a, int y) {
    queue<pair<int,int>> q;
    unordered_set<int> visited;

    q.push({a,0});
    visited.insert(a);

    while(q.size()){
        int x = q.front().first;
        int b = q.front().second;
        q.pop();

        if(x<=0 || x>=10001){
            continue;
        }

        if(x==y){
            return b;
        }

        if(x%11==0 && x%5==0){

            if(!visited.count(x/11)){
                visited.insert(x/11);
                q.push({x/11,b+1});
            }

            if(!visited.count(x/5)){
                visited.insert(x/5);
                q.push({x/5,b+1});
            }

            if(!visited.count(x+1)){
                visited.insert(x+1);
                q.push({x+1,b+1});
            }

            if(!visited.count(x-1)){
                visited.insert(x-1);
                q.push({x-1,b+1});
            }
        }
        else if(x%11==0){

            if(!visited.count(x/11)){
                visited.insert(x/11);
                q.push({x/11,b+1});
            }

            if(!visited.count(x+1)){
                visited.insert(x+1);
                q.push({x+1,b+1});
            }

            if(!visited.count(x-1)){
                visited.insert(x-1);
                q.push({x-1,b+1});
            }
        }
        else if(x%5==0){

            if(!visited.count(x/5)){
                visited.insert(x/5);
                q.push({x/5,b+1});
            }

            if(!visited.count(x+1)){
                visited.insert(x+1);
                q.push({x+1,b+1});
            }

            if(!visited.count(x-1)){
                visited.insert(x-1);
                q.push({x-1,b+1});
            }
        }
        else{

            if(!visited.count(x+1)){
                visited.insert(x+1);
                q.push({x+1,b+1});
            }

            if(!visited.count(x-1)){
                visited.insert(x-1);
                q.push({x-1,b+1});
            }
        }
    }

    return -1;
}

    int minimumOperationsToMakeEqual(int x, int y) {
        
        return f(x, y);
    }
};