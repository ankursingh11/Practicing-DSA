
/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> ans;
    if(!root) return ans;

    Node<int>* head = NULL, *tail = NULL;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>*currNode = q.front();
        q.pop();

        if(!currNode){
            if(q.empty()) break;
            tail->next = NULL;
            ans.push_back(head);
            head = tail = NULL;
            q.push(NULL);
            continue;
        }
        Node<int>*newNode = new Node<int>(currNode->data);
        if(!head) head = tail =newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }

        if(currNode->left) q.push(currNode->left);
        if(currNode->right) q.push(currNode->right);
    }

    tail->next = NULL;
    ans.push_back(head);
    return ans;
}