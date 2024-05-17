
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
Node* InsertNode(Node *head, int pos, Node* newNode){
    if(!head && pos != 0) return head;
    if(pos == 0){
        newNode->next = head;
        return newNode;
    }
    head->next = InsertNode(head->next, pos-1, newNode);
    return head;
}
