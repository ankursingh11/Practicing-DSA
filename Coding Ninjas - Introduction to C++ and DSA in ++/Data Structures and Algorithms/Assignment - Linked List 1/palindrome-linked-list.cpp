
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
#include<vector>

bool isPalindrome(Node *head)
{
    //Write your code here
    if(!head) return true;
    vector <int> v;
    while(head){
        v.push_back(head->data);
        head = head->next;
    }
    
    int i = 0, j = v.size()-1;
    
    for( ; i<=j; i++, j--){
        if(v[i]!=v[j]) return false;
    }
    return true;
    
}
