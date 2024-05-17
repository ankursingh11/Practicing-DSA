
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

int findNodeRec(Node *head, int n)
{
	//Write your code here
    if(!head) return -1;
    if(head->data == n) return 0;
    int pos = findNodeRec(head->next, n);
    if(pos != -1) return 1 + pos;
    return pos;

}