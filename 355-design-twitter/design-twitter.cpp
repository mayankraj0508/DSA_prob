#define pp pair<int,int>
class Node{
    public:
    Node*next;
    Node*prev;
    pp val;
    Node(pp val){
        this->val = val;
        this->next= NULL;
        this->prev= NULL;
    }
};

class Twitter {
public:
    unordered_map<int,set<int>>m;//user id and following id 
    vector<vector<pp>>t;
    //unordered_map<int,pp>t; /// user id and its tweet with timestamp 
    int time = 0;
    Node*head;
    Node*tail;
    Twitter() {
      head = NULL;
      tail = NULL;
      t.resize(501);
        
    }
    void postTweet(int userId, int tweetId) {
       t[userId].push_back({time,tweetId});
       time++;

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pp>pq;
        for(auto x:m[userId]){
            for(auto p:t[x]){
                pq.push(p);
            }
            
        }
        
         for(auto p:t[userId]){
            pq.push(p);
         }
        vector<int>ans;
        int count = 0;
        while(count<10 && pq.size()){

            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
            count++;
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        m[followerId].insert(followeeId);
        return ;
        
    }
    
    void unfollow(int followerId, int followeeId) {
       
            m[followerId].erase(followeeId);
        
        return ;
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */