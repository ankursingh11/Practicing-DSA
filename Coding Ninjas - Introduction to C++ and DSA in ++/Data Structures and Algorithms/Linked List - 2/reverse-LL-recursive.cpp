
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

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(!head || !head->next) return head;
    Node*newHead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}