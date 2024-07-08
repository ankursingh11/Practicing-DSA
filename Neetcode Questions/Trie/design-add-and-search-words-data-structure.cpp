
// https://leetcode.com/problems/design-add-and-search-words-data-structure/


class TrieNode{
    public :
    TrieNode **children;
    bool isTerminal;

    TrieNode(){
        isTerminal = false;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) children[i] = NULL;
    }
};


class WordDictionary {
    TrieNode*root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;

        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }

        curr->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode*curr = root;
        return search(word, 0, curr);
    }

    private :
    bool search(string word, int index, TrieNode*node){

        if(!node) return false;
        if(index == word.size()) return node->isTerminal;
        if(word[index] != '.') return search(word, index+1, node->children[word[index]-'a']);
        for(int j = 0; j < 26; j++){
            if(search(word, index+1, node->children[j])) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */