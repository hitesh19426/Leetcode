class trienode{
public:
    trienode* nodes[26] = {};
    bool isEnd = false;
};

class WordDictionary {
    trienode* root = new trienode();
public:
    WordDictionary() {}
    
    void addWord(string word) {
        auto ptr = root;
        for(char c: word){
            int ind = c-'a';
            if(ptr->nodes[ind] == NULL)
                ptr->nodes[ind] = new trienode();
            ptr = ptr->nodes[ind];
        }
        ptr->isEnd = true;
    }
    
    bool searchHelper(string &word, trienode* root, int start = 0){
        for(int i=start; i<word.size(); i++){
            if(word[i] == '.'){
                for(int j=0; j<26; j++){
                    if(root->nodes[j] && searchHelper(word, root->nodes[j], i+1))
                        return true;
                }
                return false;
            }
            else{
                int ind = word[i]-'a';
                if(root->nodes[ind] == NULL)
                    return false;
                root = root->nodes[ind];
            }
        }
        return root->isEnd;
    }
    
    bool search(string s){
        return searchHelper(s, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */