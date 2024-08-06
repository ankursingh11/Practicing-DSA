
// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

void addNode(Node *head, int pos, int data)
{
   // Your code here
   if(!head) return;
   Node*newNode = new Node(data);
   int i = 1;
   Node*curr = head;
   while(i <= pos){
       curr = curr->next;
       i++;
   }
   if(!curr->next){
       curr->next = newNode;
       newNode->prev = curr;
       return;
   }
   Node*nextNode = curr->next;
   curr->next = newNode;
   newNode->next = nextNode;
   nextNode->prev = newNode;
   newNode->prev = curr;
   return;
}