struct trie{
    bool isEnd;
    trie* children[26];
    trie(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    trie *root;
    WordDictionary() {
        root=new trie();
    }
    
    void addWord(string word) {
        trie* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a']==NULL){
                temp->children[word[i]-'a']=new trie();
            }
            temp=temp->children[word[i]-'a'];
        }
        temp->isEnd=true;
    }
    
    bool helper(string word,trie* root){
        for(int i=0;i<word.size();i++){
            if(word[i]!='.'){
                if(root->children[word[i]-'a']==NULL){
                    return false;
                }
                root=root->children[word[i]-'a'];
            }
            else{
                bool found=false;
                int j=0;
                for(;j<26;j++){
                    if(root->children[j]){
                        found |= helper(word.substr(i+1),root->children[j]);
                    }
                    if(found){
                        return true;
                    }
                }
                if(j>=26){
                    return false;
                }
            }
        }
        return (root && root->isEnd);
    }
    
    bool search(string word) {
        return helper(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
