
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

Node*merge(Node*head1, Node*head2){
   
    
    Node*temp = NULL;
    Node*newHead = NULL;
    
    if(head1->data <= head2->data){
        newHead = head1;
        head1 = head1->next;
    }else{
        newHead = head2;
        head2 = head2->next;
    }
    temp = newHead;
    
    while(head1 && head2){
        if(head1->data <= head2->data){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    
    if(head1) temp->next = head1;
    if(head2) temp->next = head2;
    
    return newHead;
}

Node*midpointLL(Node*head){
    if(!head) return head;
    Node*fast = head;
    Node*slow = head;
    
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

Node *mergeSort(Node *head)
{
	if(!head || !head->next) return head;
    Node*mid = midpointLL(head);
    Node*head2 = mid->next;
    Node*head1 = head;
    mid->next = NULL;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}