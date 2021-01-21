class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        vector<char> val(n);
        string str="";
        for(int i=0;i<n;i++){
            int index=indices[i];
            val[index]=s[i];
        }
        for(int i=0;i<n;i++){
            str+=val[i];
        }
        return str;
    }
};
