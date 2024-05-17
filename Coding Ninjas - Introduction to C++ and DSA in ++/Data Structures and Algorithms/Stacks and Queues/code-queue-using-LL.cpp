
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

class Queue {
	// Define the data members
    Node*head, *tail;
    int size;
   public:
    Queue() {
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

    void enqueue(int data) {
		// Implement the enqueue() function
        Node*newNode = new Node(data);
        if(!head) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
        this->size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(!head) return -1;
        int ans = head->data;
        Node*temp = head;
        head = head->next;
        delete temp;
        this->size--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(!head) return -1;
        return head->data;
    }
};