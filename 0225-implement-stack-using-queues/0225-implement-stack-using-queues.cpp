class MyStack{
    public:
    queue<int>q;
    void push(int x) {
        q.push(x);
        for(auto i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();//STL f(x)
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
/*class MyStack //Using 2 queues. 
{
public:
    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        while(!q1.empty())
        {
            q1.pop();
            q2.push(q1.front());
        }

        q1.push(x);

        while(!q2.empty()){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }

    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */