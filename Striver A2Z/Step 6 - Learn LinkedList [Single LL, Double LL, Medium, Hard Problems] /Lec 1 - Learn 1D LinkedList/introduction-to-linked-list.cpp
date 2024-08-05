
// https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 0) return NULL;
        
        Node*head = NULL;
        Node*tail = NULL;
        for(int i = 0; i < n; i++){
            Node*newNode = new Node(arr[i]);
            if(!head) head = tail = newNode;
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        return head;
    }
};