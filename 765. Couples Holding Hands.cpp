class Solution {
public:
    int find(int val,vector<int> &parent){
        if(parent[val]==val){
            return parent[val];
        }
        return parent[val]=find(parent[val],parent);
    }
    
    void Union(int x,int y,vector<int> &parent,vector<int> &size,int &count){
        int parentX=find(x,parent);
        int parentY=find(y,parent);
        if(parentX==parentY){
            return;
        }
        if(size[parentX]<=size[parentY]){
            parent[parentX]=parentY;
            size[parentY]++;
        }
        else{
            parent[parentY]=parentX;
            size[parentX]++;
        }
        count--;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        vector<int> parent(n,0);
        vector<int> size(n,0);
        int count=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int x=row[2*i];
            int y=row[2*i+1];
            Union(x/2,y/2,parent,size,count);
        }
        return (n-count);
    }
};
