class Solution {
public:
    int numSplits(string s) {
        int len=s.length();
        vector<int> prefix(len),suffix(len);
        set<char> prefix_s,suffix_s;
        for(int i=0;i<len;i++){
            prefix_s.insert(s[i]);
            suffix_s.insert(s[len-i-1]);
            prefix[i]=prefix_s.size();
            suffix[len-i-1]=suffix_s.size();
        }
        int count=0;
        for(int i=1;i<len;i++){
            if(prefix[i-1]==suffix[i]){
                count++;
            }
        }
        return count;
    }
};
