class LFUCache {
public:

    class Node {
    public:
        int key, val, cnt;
        Node *next, *prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            cnt = 1;
            next = NULL;
            prev = NULL;
        }
    };

    class List {
    public:
        int size;
        Node *head, *tail;

        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void addFront(Node* node) {
            Node* temp = head->next;

            node->next = temp;
            node->prev = head;

            head->next = node;
            temp->prev = node;

            size++;
        }

        void removeNode(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }
    };

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    int capacity;
    int currSize;
    int minFreq;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqList(Node* node) {
        int frequency = node->cnt;

        freqList[frequency]->removeNode(node);

        if (frequency == minFreq &&
            freqList[frequency]->size == 0) {
            minFreq++;
        }

        node->cnt++;

        if (freqList.find(node->cnt) == freqList.end()) {
            freqList[node->cnt] = new List();
        }

        freqList[node->cnt]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        updateFreqList(node);

        return node->val;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        
        if (keyNode.find(key) != keyNode.end()) {

            Node* node = keyNode[key];

            node->val = value;

            updateFreqList(node);

            return;
        }

      
        if (currSize == capacity) {

            List* list = freqList[minFreq];

            Node* nodeToDelete = list->tail->prev;

            keyNode.erase(nodeToDelete->key);

            list->removeNode(nodeToDelete);

            delete nodeToDelete;

            currSize--;
        }

        
        Node* newNode = new Node(key, value);

        minFreq = 1;

        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }

        freqList[1]->addFront(newNode);

        keyNode[key] = newNode;

        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */