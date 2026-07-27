struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}  // new node starts pointing nowhere
};

class LinkedList {
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index >= size) return -1;
        Node* current = head;
        for(int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (size == 0) tail = newNode;
        ++size;

    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if(size == 0 )
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode; 
            tail = newNode;
        }
        ++size;
    }

    bool remove(int index) {

        if(index >= size) return false;
        
        // edge case if node to delete was the first node
        if(index == 0)
        {
            Node* toDelete = head;
            head = head->next;
            if(size ==1)
            {
                tail == nullptr;
            }
            delete toDelete;
            toDelete = nullptr;
            --size;
            return true;
        }
        Node* current = head->next;
        Node* trailCurrent = head;
        for(int i = 0; i < index-1; ++i)
        {
            current = current->next;
            trailCurrent = trailCurrent->next;
        }
        trailCurrent->next = current->next;
        if(current == tail) tail = trailCurrent;
        delete current;
        current = nullptr;
        --size;
        return true;
    }

    vector<int> getValues() {
        Node* current = head;
        vector<int> results;
        while(current != nullptr)
        {
            results.push_back(current->val);
            current = current->next;
        }
        return results;
    }
};
