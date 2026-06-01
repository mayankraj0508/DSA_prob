#define pp pair<int, int>
class Node {
public:
    Node* prev;
    Node* next;
    pp val;
    Node(pp val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    Node* prev;
    int size;
    int k;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        head = NULL;
        prev = NULL;
        tail = NULL;
        size = 0;
        k = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        if (size == 0) {
            return -1;
        }
        if (head == tail) {
            return head->val.second;
        }
        Node* c = m[key];
        if (c == head) {
            return head->val.second;
        }
        Node* t = c->next;
        Node* p = c->prev;
        bool flag = false;
        if (p)
            p->next = t;
        if (t == NULL) {
            Node* l = tail->prev;
            Node* k = tail;
            l->next = NULL;
            tail = l;
            k->next = head;
            head->prev = k;
            head = k;
            k->prev = NULL;
            flag = true;
        }
        if (t)
            t->prev = p;
        if (flag == false) {
            c->next = head;
            head->prev = c;
            head = c;
            c->prev = NULL;
        }

        int ans = head->val.second;
        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* p = m[key];
            if (p == head) {
                head->val.second = value;
                m[key]->val.second = value;
                return;
            }
            if (head == tail) {
                head->val.second = value;
                m[key]->val.second = value;
                return;
            }

            if (p == tail) {
                Node* k = tail->prev;
                Node* j = tail;
                k->next = NULL;
                tail = k;
                j->next = head;
                head->prev = j;
                j->prev = NULL;
                head = j;
                m[key]->val.second = value;
                return;

            } else {
                Node* a = p->prev;
                Node* b = p->next;
                if (a)
                    a->next = b;
                if (b)
                    b->prev = a;
                p->next = head;
                head->prev = p;
                p->prev = NULL;
                head = p;
                m[key]->val.second = value;
                return;
            }
        } else {
            Node* p = new Node({key, value});
            m[key] = p;
            if (head == NULL) {
                head = p;
                tail = p;
                size++;

            } else {
                p->next = head;
                head->prev = p;
                p->prev = NULL;
                head = p;
                size++;
            }
            if (size > k) {
                // deletion
                int valu = tail->val.first;
                tail = tail->prev;
                tail->next = NULL;
                size--;
                m.erase(valu);
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