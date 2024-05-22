
// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int ans = -1;
        if(input.empty()) return ans;

        while(input.size() != 1){
            output.push(input.top());
            input.pop();
        }

        ans = input.top();
        input.pop();

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }

        return ans;
    }
    
    int peek() {
        int ans = -1;
        if(input.empty()) return ans;

        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        ans = output.top();

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }

        return ans; 
    }
    
    bool empty() {
        return input.empty();
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