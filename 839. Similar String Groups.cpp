class Solution {
public:
    int find(int val,vector<int> &parent){
        if(parent[val]==val){
            return parent[val]=val;
        }
        return parent[val]=find(parent[val],parent);
    }
    
    void Union(int val1,int val2,int &size,vector<int> &parent){
        int root1=find(val1,parent);
        int root2=find(val2,parent);
        if(root1!=root2){
            parent[root2]=root1;
            size--;
        }
    }
    
    bool similar(string val1,string val2){
        int count=0;
        for(int i=0;i<val1.size();i++){
            if(val1[i]!=val2[i]){
                count++;
            }
            if(count>2){
                return false;
            }
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int size=n;
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    Union(i,j,size,parent);
                }
            }
        }
        return size;
    }
};
