class MyLinkedList {
    struct Node {              // the box: value + arrow
        int val;
        Node* next;
        Node* prev;
        Node(int v) : val(v), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = new Node(0);      // both dummies are fake, val ignored
        tail = new Node(0);
        head->next = tail;       // empty list: the two dummies point at each other
        tail->prev = head;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 or index >= size) return -1;
        Node* current = head->next;
        for(int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        Node* after = head->next;    // current first real node
        newNode->prev = head;
        newNode->next = after;
        head->next = newNode;
        after->prev = newNode;
        ++size;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* before = tail->prev;
        Node* after  = tail;

        newNode->next = after;
        newNode->prev = before;
        before->next = newNode;
        after->prev = newNode;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        Node* current = head;
        if(index > size) return;
        for(int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        Node* after = current->next;
        newNode->next = after;
        newNode->prev = current;
        current->next = newNode;
        after->prev = newNode;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        
        if (index < 0 || index >= size) return;
        Node* current = head->next;
        Node* trailCurrent = head;
        for(int i = 0; i < index; ++i)
        {
            current = current->next;
            trailCurrent = trailCurrent->next;
        }
        Node* newCurrent = current->next;
        trailCurrent->next = current->next;
        newCurrent->prev = trailCurrent;
        delete current;
        current = nullptr;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */