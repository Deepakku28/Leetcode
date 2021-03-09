class Solution {
public:
    int find(int &val,vector<int> &parent){
        if(parent[val]==val){
            return parent[val];
        }
        return parent[val]=find(parent[val],parent);
    }
    
    void Union(int &val1,int &val2,vector<int> &parent){
        int root1=find(val1,parent);
        int root2=find(val2,parent);
        if(root1!=root2){
            parent[root2]=root1;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<string> equal;
        vector<string> notEqual;
        for(auto it:equations){
            if(it[1]=='='){
                equal.push_back(it);
            }
            else{
                notEqual.push_back(it);
            }
        }
        vector<int> parent(26,-1);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<equal.size();i++){
            int val1=equal[i][0]-'a';
            int val2=equal[i][3]-'a';
            Union(val1,val2,parent);
        }
        for(int i=0;i<notEqual.size();i++){
            int val1=notEqual[i][0]-'a';
            int val2=notEqual[i][3]-'a';
            int root1=find(val1,parent);
            int root2=find(val2,parent);
            if(root1==root2){
                return false;
            }
        }
        return true;
    }
};
