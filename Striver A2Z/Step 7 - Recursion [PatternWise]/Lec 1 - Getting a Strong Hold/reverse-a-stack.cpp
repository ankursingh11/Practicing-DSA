
// https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

class Solution{
public:
    void Reverse(stack<int> &st){
        if(st.size() == 1) return;
        int ele = st.top();
        st.pop();
        Reverse(st);
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(ele);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return;
    }
};