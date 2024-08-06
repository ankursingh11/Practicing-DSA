
// https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-doubly-linked-list

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        Node*head = NULL;
        Node*tail = NULL;
        if(arr.size() == 0) return head;
        
        for(auto ele : arr){
            Node*newNode = new Node(ele);
            if(!head) head = tail = newNode;
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        return head;
    }
};