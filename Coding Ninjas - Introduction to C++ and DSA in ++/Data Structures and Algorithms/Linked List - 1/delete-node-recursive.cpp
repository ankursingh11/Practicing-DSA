
/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* deleteNodeRec(Node *head, int pos) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
     if(!head) return head;
    if(pos == 0) return head->next;
    head->next = deleteNodeRec(head->next, pos-1);
    return head;
}


