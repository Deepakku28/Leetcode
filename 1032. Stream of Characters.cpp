struct trie{
    bool isEnd=false;
    trie* child[26]={NULL};
};

class StreamChecker {
public:
    trie* root=new trie();
    int len=0;
    string str="";
    
    void insert(string word){
        trie* temp=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->child[index]==NULL){
                temp->child[index]=new trie();
            }
            temp=temp->child[index];
        }
        temp->isEnd=true;
    }
    
    StreamChecker(vector<string>& words) {
        for(auto it:words){
            reverse(it.begin(),it.end());
            insert(it);
            len=max(len,(int)it.size());
        }
    }
    
    bool search(string str){
        trie* temp=root;
        for(int i=0;i<str.size();i++){
            int index=str[i]-'a';
            if(temp->child[index]==NULL){
                return false;
            }
            temp=temp->child[index];
            if(temp->isEnd){
                return true;
            }
        }
        return (temp->isEnd);
    }
    
    bool query(char letter) {
        str=letter+str;
        if(str.length()>len){
            str.pop_back();
        }
        return search(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
