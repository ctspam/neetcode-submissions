class BrowserHistory {
public:
    struct Node
    {
        string url;
        Node* next;
        Node* prev;
        Node (string u) : url(u), prev(nullptr), next(nullptr){}
    };
    Node* cur; 
    BrowserHistory(string homepage) {
        cur = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        cur->next = newNode;
        newNode->prev = cur;
        cur = newNode;
    }
    
    string back(int steps) {
        for(int i = 0; i < steps && cur->prev != nullptr; ++i)
        {
            cur = cur->prev;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        for(int i = 0; i < steps && cur->next != nullptr; ++i)
        {
            cur = cur->next;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */