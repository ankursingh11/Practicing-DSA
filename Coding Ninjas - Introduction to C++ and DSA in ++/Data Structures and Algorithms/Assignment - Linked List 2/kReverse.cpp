
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
    int len = 0;
    while(++len && head) head = head->next;
    return len-1;
}


Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(!head || k == 0) return head;

    int i = 0;
    Node*curr = head, *fwd = NULL, *prev = NULL;
    while(curr && i++ < k){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    if(fwd) head->next = kReverse(fwd, k);
    return prev;
}