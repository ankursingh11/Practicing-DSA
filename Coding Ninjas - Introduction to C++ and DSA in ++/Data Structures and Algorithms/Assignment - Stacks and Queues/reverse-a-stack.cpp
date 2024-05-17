
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.empty()) return;

    int ele = input.top();
    input.pop();

    reverseStack(input, extra);

    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }

    input.push(ele);

    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }

    return;
}