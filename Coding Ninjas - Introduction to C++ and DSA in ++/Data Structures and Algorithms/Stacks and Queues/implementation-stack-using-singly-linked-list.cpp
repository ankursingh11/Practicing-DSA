
/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack {
	// Define the data members
    Node*head = NULL;
    Node*tail = NULL;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head = tail = NULL;
        size = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return this->size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return this->size == 0;
    }

    void push(int element) {
        // Implement the push() function
        Node*newNode = new Node(element);
        if(!head) head = newNode;
        else{
            newNode->next = head;
            head = newNode;
        }
        this->size++;
    }

    int pop() {
        // Implement the pop() function
        if(!head) return -1;
        int ans = head->data;
        Node*temp = head;
        head = head->next;
        delete temp;
        this->size--;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(!head) return -1;
        return head->data;
    }
};