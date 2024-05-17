
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

node* arrange_LinkedList(node* head)
{
    //write your code here
    if(!head) return head;
    
    node*headEven = NULL;
    node*tailEven = NULL;
    node*headOdd = NULL;
    node*tailOdd = NULL;
    
    while(head){
        int data = head->data;
        if(data%2 == 0){
            if(headEven == NULL){
                headEven = head;
                tailEven = head;
            }else{
                tailEven->next = head;
                tailEven = head;
            }  
        }else{
            if(headOdd == NULL){
                headOdd = head;
                tailOdd = head;
            }else{
                tailOdd->next = head;
                tailOdd = head;
            }
        }
        head = head->next;
    }
    
    if(!headOdd) return headEven;
    else tailOdd->next = headEven;
    
    if(!headEven) return headOdd;
    else tailEven->next = NULL;
    
    return headOdd;
}
