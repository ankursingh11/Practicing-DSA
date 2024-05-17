
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

int length(Node*head){
    if(!head) return 0;
    return 1 + length(head->next);
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(!head) return head;
    
    int len = length(head);
    
    int x = len - n;
    int y = 0;
    Node*temp = head;
    Node*prev = NULL;
    
    while(y < x){
        prev = temp;
        temp = temp->next; 
        y++;
    }
    
    Node*newHead = temp;
    Node*newTail = prev;
    
    while(temp->next!=NULL) temp = temp->next;
    
    temp->next = head;
    newTail->next = NULL;
    return newHead;
}