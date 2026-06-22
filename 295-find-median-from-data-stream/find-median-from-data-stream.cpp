class MedianFinder {
public:
   vector<int>nums;
   priority_queue<double>firsthalf;
   priority_queue<double,vector<double>,greater<double>>secondhalf;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
        if(firsthalf.size()==0){
            firsthalf.push(num);
        }
        else{
            if(firsthalf.top()<num){
                secondhalf.push(num);
            }
            else{
                firsthalf.push(num);
                
            }
            while(firsthalf.size()>secondhalf.size()+1){
                secondhalf.push(firsthalf.top());
                firsthalf.pop();
            }
            while(secondhalf.size()>firsthalf.size()+1){
              firsthalf.push(secondhalf.top());
              secondhalf.pop();
        }

        }
        return ;
      
        
    }
    
    double findMedian() {
        if(firsthalf.size()==secondhalf.size()){
            return (firsthalf.top()+secondhalf.top())/2.0;
        }
        else{
            if(secondhalf.size()>firsthalf.size()){
                return secondhalf.top();
            }
            return firsthalf.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */