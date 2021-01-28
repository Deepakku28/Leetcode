struct tree{
    bool isEnd=false;
    tree* child[26]={NULL};
};

class Trie {
public:
    /** Initialize your data structure here. */
    tree* root=NULL;
    
    Trie() {
        root=new tree();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        tree* temp=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->child[index]==NULL){
                temp->child[index]=new tree();
            }
            temp=temp->child[index];
        }
        temp->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        tree* temp=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->child[index]==NULL){
                return false;
            }
            temp=temp->child[index];
        }
        return (temp!=NULL && temp->isEnd);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tree* temp=root;
        for(int i=0;i<prefix.size();i++){
            int index=prefix[i]-'a';
            if(temp->child[index]==NULL){
                return false;
            }
            temp=temp->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
