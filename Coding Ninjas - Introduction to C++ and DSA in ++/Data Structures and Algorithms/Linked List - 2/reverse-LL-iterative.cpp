
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(!head || !head->next) return head;

    Node*fwd = head, *temp = head, *prev = NULL;
    
    while(fwd){
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }

    head = prev;
    return head;
}