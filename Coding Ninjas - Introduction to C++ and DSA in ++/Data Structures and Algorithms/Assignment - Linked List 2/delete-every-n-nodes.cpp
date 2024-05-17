
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    if(!head) return head;
    
    node*temp = head;
    node*prev = NULL;
    
    while(temp){
        int x = 0;
        while(x < M){
            if(!temp) break;
            prev = temp;
            temp = temp->next;
            x++;
        }
        
        int y = 0;
        while(y<N){
            if(!temp) break;
            temp = temp->next;
            y++;
        }
        
        prev->next = temp;
    }
    
    prev->next = temp;
    return head;
}
