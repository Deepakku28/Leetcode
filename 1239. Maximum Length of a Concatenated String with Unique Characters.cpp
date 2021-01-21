class Solution {
public:
    
    bool is_unique(string str){
        vector<int> v(26,0);
        for(char it:str){
            v[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]>1){
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<string>& arr,int index,string curr,int &max_len){
        if(is_unique(curr)==false){
            return ;
        }
        if(curr.length()>max_len){
            max_len=curr.length();
        }
        for(int i=index;i<arr.size();i++){
            dfs(arr,i+1,curr+arr[i],max_len);
        }
    }
    
    int maxLength(vector<string>& arr) {
        int max_len=0;
        dfs(arr,0,"",max_len);
        return max_len;
    }
};
