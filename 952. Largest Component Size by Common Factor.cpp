class Solution {
public:
    int find(int val,vector<int> &parent){
        if(parent[val]==val){
            return parent[val];
        }
        return parent[val]=find(parent[val],parent);
    }
    
    void Union(int val1,int val2,vector<int> &parent){
        int root1=find(val1,parent);
        int root2=find(val2,parent);
        if(root1==root2){
            return;
        }
        parent[root2]=root1;
    }
    
    int largestComponentSize(vector<int>& A) {
        vector<int> parent(100001,-1);
        for(int i=0;i<=100000;i++){
            parent[i]=i;
        }
        for(int i=0;i<A.size();i++){
            for(int j=2;j<=sqrt(A[i]);j++){
                if(A[i]%j==0){
                    Union(A[i],j,parent);
                    Union(A[i],A[i]/j,parent);
                }
            }
        }
        int ans=1;
        unordered_map<int,int> mp;
        for(int i=0;i<A.size();i++){
            int root=find(parent[A[i]],parent);
            mp[root]++;
            ans=max(ans,mp[root]);
        }
        return ans;
    }
};
