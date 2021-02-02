class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n=A.size();
        vector<int> mp(26,INT_MAX);
        for(int i=0;i<n;i++){
            vector<int> curr(26,0);
            for(int j=0;j<A[i].size();j++){
                curr[A[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                mp[j]=min(mp[j],curr[j]);
            }
        }
        vector<string> ans;
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                for(int j=0;j<mp[i];j++){
                    ans.push_back(string(1,'a'+i));
                }
            }
        }
        return ans;
    }
};
