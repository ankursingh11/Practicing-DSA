
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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(!head) return head;
    Node*temp = head->next;
    while(temp && head->data == temp->data) temp = temp->next;
    head->next = removeDuplicates(temp);
    return head;
}