class MyQueue {
public:
    stack<int> stck;
    stack<int> outstck;
    void push(int x) {
        stck.push(x);
    }
    int pop() {
        peek();
        const int val = outstck.top();
        outstck.pop();
        return val;
    }

    int peek() {
        if (outstck.empty())
        while (!stck.empty())
            outstck.push(stck.top()), stck.pop();
        return outstck.top();
    }
    bool empty() {
        return stck.empty() && outstck.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */