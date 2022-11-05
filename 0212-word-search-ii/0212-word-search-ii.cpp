class trieNode{
public:
    trieNode* nodes[26] = {};
    bool isEnd = false;
};

class Solution {
    int m, n, dir[5] = {1,0,-1,0,1};
    trieNode* root = new trieNode();
    
    void insert(string &s){
        auto ptr = root;
        for(char &c: s){
            int ind = c-'a';
            if(ptr->nodes[ind] == nullptr)
                ptr->nodes[ind] = new trieNode();
            ptr = ptr->nodes[ind];
        }
        ptr->isEnd = true;
    }

    bool isvalid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void dfs(int i, int j, string& word, trieNode* &root, vector<string>& ans, vector<vector<char>>& board){
        if(root->isEnd){
            ans.push_back(word);
            root->isEnd = false;
        }
        char orig = board[i][j];
        board[i][j] = '*';
        
        for(int k=0; k<4; k++){
            int newx = i+dir[k], newy = j+dir[k+1];
            if(isvalid(newx, newy, m, n) && board[newx][newy] != '*'){
                int ind = board[newx][newy]-'a';
                if(root->nodes[ind]){
                    word += board[newx][newy];
                    dfs(newx, newy, word, root->nodes[ind], ans, board);
                    word.pop_back();
                }
            }
        }
        board[i][j] = orig;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        
        for(auto &word: words)
            insert(word);
        
        vector<string> ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ind = board[i][j]-'a';
                string word = string(1, board[i][j]);
                if(root->nodes[ind]){
                    dfs(i, j, word, root->nodes[ind], ans, board);
                }
            }
        }
        
        return ans;
    }
};