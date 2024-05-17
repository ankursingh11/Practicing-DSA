
#include <string>
#include <vector>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    string reverseWord(string word){
        string reverse = "";
        for(int i = word.length()-1; i>=0; i--) reverse+=word[i];
        return reverse;
    }
    

    bool isPalindromePair(vector<string> words)
    {
		//Write your code here
        for(int i = 0; i < words.size(); i++) this->add(reverseWord(words[i]));
        return isPalindromePair(this->root, words);
    }
    
    bool isPalindromePair(TrieNode*root, vector<string> words){
        if(words.size() == 0) return false;
        for(int i = 0; i < words.size(); i++){
            if(doesPairExistFor(root, words[i], 0)) return true;
        }
        return false;
    }
    
    bool doesPairExistFor(TrieNode*root, string word, int si){
        if(word.length() == 0) return true;
        if(si == word.length()){
            if(root->isTerminal) return true;
            return checkRemainingBranchesInTrie(root, "");
        }
        int charIndex = word[si]-'a';
    TrieNode*correspondingChild = root->children[charIndex];
    
    if(correspondingChild == NULL){
        if(root->isTerminal) return checkWordForPalindrome(word.substr(si));
        return false;
    }
    return doesPairExistFor(correspondingChild, word, si+1);
    }
    
    bool checkRemainingBranchesInTrie(TrieNode*root, string word){
        if(root->isTerminal){
            if(checkWordForPalindrome(word)) return true;
        }
        for(int i = 0; i < 26; i++){
            TrieNode *childNode = root->children[i];
            if(childNode == NULL) continue;
            
            string fwd = word + childNode->data;
            if(checkRemainingBranchesInTrie(childNode, fwd)) return true;
        }
        return false;
    }
    
    bool checkWordForPalindrome(string word){
        int si = 0;
        int ei = word.length()-1;
        while(si < ei){
            if(word[si]!=word[ei]) return false;
            si+=1;
            ei-=1;
        }
        return true;
    }
};