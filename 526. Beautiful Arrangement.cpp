class Solution {
public:
    void helper(int start,int end,int &ans,vector<int> &val){
        if(start==end){
            if((start+1)%val[start]==0 || (val[start]%(start+1))==0){
                ans++;
            }
            return;
        }
        for(int i=start;i<=end;i++){
            swap(val[i],val[start]);
            if((start+1)%val[start]==0 || (val[start]%(start+1))==0){
                helper(start+1,end,ans,val);
            }
            swap(val[i],val[start]);
        }
    }
    
    int countArrangement(int n) {
        int ans=0;
        vector<int> val(n,0);
        for(int i=0;i<n;i++){
            val[i]=i+1;
        }
        helper(0,n-1,ans,val);
        return ans;
    }
};
