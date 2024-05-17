
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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(!head) return head;

    Node*c1 = head, *p1 = NULL;
    while(i--){
        p1 = c1;
        c1 = c1->next;
    }

    Node*c2 = head, *p2 = NULL;
    while(j--){
        p2 = c2;
        c2 = c2->next;
    }

    if(p1) p1->next = c2;
    else head = c2;

    if(p2) p2->next = c1;
    else head = c1;

    Node*temp = c1->next;
    c1->next = c2->next;
    c2->next = temp;

    return head;
}