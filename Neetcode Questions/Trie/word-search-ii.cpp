
// https://leetcode.com/problems/word-search-ii/

class TrieNode{
    public :
    bool isTerminal;
    TrieNode**children;

    TrieNode(){
        isTerminal = false;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) children[i] = NULL;

    }
};

class Solution {
    TrieNode*root;
public:
    Solution(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode*curr = root;

        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(curr->children[index] == NULL) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    bool validPoints(int x, int y, int rowSize, int colSize){
        return (x >= 0 && x < rowSize && y >= 0 && y < colSize);
    }

    void search(vector<vector<char>>&board, int rowSize, int colSize, int x, int y, vector<string>&ans, string word, TrieNode*root){
        if(!validPoints(x, y, rowSize, colSize) || board[x][y] == '#') return;

        char ch = board[x][y];
        root = root->children[ch-'a'];
        if(!root) return;
        word += ch;
        if(root->isTerminal){
            ans.push_back(word);
            root->isTerminal = false;
        }

        board[x][y] = '#';

        search(board, rowSize, colSize, x+1, y, ans, word, root);
        search(board, rowSize, colSize, x-1, y, ans, word, root);
        search(board, rowSize, colSize, x, y+1, ans, word, root);
        search(board, rowSize, colSize, x, y-1, ans, word, root);
        
        board[x][y] = ch;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> ans;
        int rowSize = board.size();
        if(rowSize == 0) return ans;
        int colSize = board[0].size();

        for(auto word : words) insert(word);

        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                string word = "";
                search(board, rowSize, colSize, i, j, ans, word, root);
            }
        }

        return ans;
    }
};