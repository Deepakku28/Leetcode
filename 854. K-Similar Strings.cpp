class Solution {
public:
    void dfs(string &str1,string &str2,int index,int swaps,int &ans){
        if(index>str1.size()){
            return;
        }
        int currIndex=index;
        while(currIndex<str1.size()){
            if(str1[currIndex]!=str2[currIndex]){
                break;
            }
            currIndex++;
        }
        if(currIndex==str1.size()){
            ans=min(ans,swaps);
        }
        else{
            for(int i=currIndex+1;i<str1.size();i++){
                if(str1[currIndex]==str2[i]){
                    swap(str2[currIndex],str2[i]);
                    dfs(str1,str2,currIndex+1,swaps+1,ans);
                    swap(str2[currIndex],str2[i]);
                }
            }
        }
    }
    
    int kSimilarity(string str1, string str2) {
        int ans=INT_MAX;
        dfs(str1,str2,0,0,ans);
        return ans;
    }
};
