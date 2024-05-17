
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(!head1 && !head2) return NULL;
    if(head1 && !head2) return head1;
    if(!head1 && head2) return head2;

    Node*newHead, *newTail;
    newHead = newTail = NULL;

    if(head1->data <= head2->data){
        newHead = newTail = head1;
        head1 = head1->next;
    }else{
        newHead = newTail = head2;
        head2 = head2->next;
    }

    while(head1 && head2){
        if(head1->data <= head2->data){
            newTail->next = head1;
            head1 = head1->next;
        }else{
            newTail->next = head2;
            head2 = head2->next;
        }
        newTail = newTail->next;
    }


    if(!head1){
        // cout<<"-1"<<endl;
        newTail->next = head2;
    }
    if(!head2){
        // cout<<"-2"<<endl;
        newTail->next = head1;
    }

    // newTail->next = NULL;
    return newHead;

}
