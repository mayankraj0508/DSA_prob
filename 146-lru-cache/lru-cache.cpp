class Node{
    public :
    Node*next;
    Node*prev;
    int val;
    int key;
    Node(int key, int val){
        this->val  = val;
        this->key  = key;
        next = NULL;
        prev  = NULL;

    }
};




class LRUCache {
public:
    Node*head;
    Node*tail;
    int c;
    int capacity  ;
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        head  = NULL;
        tail  = NULL;
        c  = 0;
        this->capacity  = capacity;
        
    }
    // tail ke next pe most recentlyvused 
    int get(int key) {
        if(m.find(key)!=m.end()){
            int x = m[key]->val;
           Node*temp = m[key];
          if(temp==tail){
               return x;
           }
           if(temp==head){
               if(head){
               head  = head->next;
               if(head)
               head->prev  = NULL;
           }
               if(tail)
               tail->next  = temp;
               temp->prev  = tail;
               tail  = temp;
               tail->next  = NULL;
              
               
           }
           
           else{
           Node*c = temp->prev;
           Node*d = temp->next;
           if(c)
           c->next= d;
           if(d)
           d->prev  = c;
           if(tail)
           tail->next  = temp;
           temp->prev  = tail;
           tail  = temp;
           tail->next  = NULL;
        }
           return x;




        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            
            m[key]->val = value;
            Node*temp = m[key];
            if(head==tail) return ;

             if(temp==head){
                if(head){
               head  = head->next;
               head->prev  = NULL;
             }
               
               if(tail)
               tail->next  = temp;
               temp->prev  = tail;
               tail  = temp;
               tail->next  = NULL;
               m[key] = tail;
               
           }
           else if(temp==tail){
               return ;
           }
           else{
           Node*c = temp->prev;
           Node*d = temp->next;
           if(c)
           c->next= d;
           if(d)
           d->prev  = c;
           if(tail)
           tail->next  = temp;
           temp->prev  = tail;
           tail  = temp;
           tail->next  = NULL;
           m[key] = tail;
        }

        }
        else {
            if(c<capacity){
               
                Node*temp = new Node(key,value);
                if(head==NULL){
                    head = temp;
                    tail  = temp;
                    m[key] = head;
                    c++;
                    return ;
                }
                if(head==tail){
                    tail->next  = temp;
                    temp->prev = tail;
                    tail  = temp;
                    tail->next  = NULL;
                    c++;
                    m[key] = tail;
                    return ;

                }
                if(tail)
                tail->next  = temp;
                temp->prev  = tail;
                tail  = temp;
                tail->next  = NULL;
                m[key] = tail;
                c++;


            }
            else{
                int x  = -1;
                if(head==tail){
                    int y = head->key;
                    Node*temp = new Node(key,value);
                    head  = temp;
                    tail  = temp;
                    m[key] = head;
                    m.erase(y);
                    return  ;
                }
                if(head)
                 x = head->key;
                if(head)
                head = head->next;

                Node*temp = new Node(key,value);
                if(tail)
                tail->next  = temp;
                temp->prev  = tail;
                tail  = temp;
                tail->next  = NULL;
                m[key] = temp;
                if(x!=-1)
                m.erase(x);

            }


        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */