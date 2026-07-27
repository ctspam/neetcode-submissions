class MinStack {
private:
    stack<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        minStack.push(val);
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top(); 
    }
    
    int getMin() {
        stack<int> temp;
        int mini = minStack.top();
        while(minStack.size())
        {
            mini = min(mini, minStack.top());
            temp.push(minStack.top());
            minStack.pop();
        }
        while(temp.size())
        {
            minStack.push(temp.top());
            temp.pop();
        }
        return mini;
    }
};
