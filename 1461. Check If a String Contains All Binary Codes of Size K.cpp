class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()){
            return false;
        }
        unordered_set<string> st;
        for(int i=0;i<=s.length()-k;i++){
            string curr=s.substr(i,k);
            st.insert(curr);
        }
        if(st.size()==(1<<k)){
            return true;
        }
        return false;
    }
};
