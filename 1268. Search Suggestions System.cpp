struct trie{
    trie* child[26]={NULL};
    int isEnd=0;
};

class Solution {
public:
    void insert(string &str,trie* root){
        trie* temp=root;
        for(int i=0;i<str.size();i++){
            int index=str[i]-'a';
            if(temp->child[index]==NULL){
                temp->child[index]=new trie();
            }
            temp=temp->child[index];
        }
        temp->isEnd=1;
    }
    
    void helperUtility(trie* temp,vector<string> &arr,string &str){
        if(arr.size()>=3){
            return ;
        }
        if(temp->isEnd){
            arr.push_back(str);
        }
        for(int i=0;i<26;i++){
            if(temp->child[i]!=NULL){
                str.push_back(char('a'+i));
                helperUtility(temp->child[i],arr,str);
                str.pop_back();
            }
        }
    }
    
    vector<string> helper(string &str,trie* root){
        vector<string> arr;
        trie* temp=root;
        for(int i=0;i<str.size();i++){
            if(temp->child[str[i]-'a']==NULL){
                return arr;
            }
            temp=temp->child[str[i]-'a'];
        }
        helperUtility(temp,arr,str);
        return arr;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& val, string searchWord) {
        int n=val.size();
        trie* root=new trie();
        for(int i=0;i<n;i++){
            insert(val[i],root);
        }
        string prefix="";
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            prefix+=searchWord[i];
            //cout<<prefix<<endl;
            ans.push_back(helper(prefix,root));
        }
        return ans;
    }
};
