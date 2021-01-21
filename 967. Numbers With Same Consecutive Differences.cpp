class Solution {
public:
    void helper(int &n,int &k,vector<int> &ans,string curr,int start){
        if(start==n){
            ans.push_back(stol(curr));
            return ;
        }
        for(char ch='0';ch<='9';ch++){
            if(curr.size()==0 && ch=='0'){
                continue;
            }
            if(abs(curr.back()-ch)==k || curr.size()==0){
                helper(n,k,ans,curr+ch,start+1);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        helper(n,k,ans,"",0);
        return ans;
    }
};
