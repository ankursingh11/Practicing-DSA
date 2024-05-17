
// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i = 0; i < input.size(); i++) insertWord(input[i]);
        string output = "";
        helper(root, pattern, output);
    }
    
    void helper(TrieNode*root, string pattern, string output){
        if(!root) return;
        if(pattern.size() == 0){
            if(root->isTerminal) cout<<output<<endl;
            
            for(int i = 0; i < 26; i++){
                if(root->children[i]){
                    string s = output + root->children[i]->data;
                    print(root->children[i], s);
                }
            }
            return;
        }
        
        int index = pattern[0] - 'a';
        output = output + pattern[0];
        helper(root->children[index], pattern.substr(1), output);
    }
    
    void print(TrieNode*root, string output){
        if(!root) return;
        if(root->isTerminal) cout<<output<<endl;
        for(int i = 0; i < 26; i++){
            if(root->children[i]){
                string s = output + root->children[i]->data;
                print(root->children[i], s);
            }
        }
    }

};
