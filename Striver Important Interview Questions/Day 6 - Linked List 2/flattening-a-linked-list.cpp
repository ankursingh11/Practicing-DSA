
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node*merge(Node*head1, Node*head2){
    
    if(!head1 && !head2) return NULL;
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node*head = NULL, *tail = NULL;
    
    if(head1->data <= head2->data){
        head = tail = head1;
        head1 = head1->bottom;
    }else{
        head = tail = head2;
        head2 = head2->bottom;
    }
    
    while(head1 && head2){
        if(head1->data <= head2->data){
            tail->bottom = head1;
            head1 = head1->bottom;
        }else{
            tail->bottom = head2;
            head2 = head2->bottom;
        }
        tail = tail->bottom;
    }
    
    if(!head1) tail->bottom = head2;
    if(!head2) tail->bottom = head1;
    
    return head;
}
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(!root || !root->next) return root;
   root->next = flatten(root->next);
   return merge(root, root->next);
}