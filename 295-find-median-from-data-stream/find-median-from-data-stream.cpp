class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>sq;


    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.size()==0){
            pq.push(num);
        }
        else{
            if(num>pq.top()){
                sq.push(num);
            }
            else{
                pq.push(num);
            }
            while(pq.size()>sq.size()+1){
                int x = pq.top();
                pq.pop();
                sq.push(x);
            }
            while(sq.size()>pq.size()+1){
                int x = sq.top();
                sq.pop();
                pq.push(x);
            }
        }
        
    }
    
    double findMedian() {
        int total = pq.size()+sq.size();
        if(total%2==0){
            double ans  = (pq.top()+sq.top())/2.0;
            return ans;
        }
        else{
            if(pq.size()>sq.size()) return (double) pq.top();
            else return sq.top();
            
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */