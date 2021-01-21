class Solution {
public:
    
    bool check(string curr,int maxLetters){
        set<char> s;
        for(char it:curr){
            s.insert(it);
        }
        if(s.size()>maxLetters){
            return false;
        }
        return true;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> mp;
        for(int i=0;i<s.length()-minSize+1;i++){
            string curr=s.substr(i,minSize);
            if(check(curr,maxLetters)){
                mp[curr]++;
            }
        }
        int max_count=0;
        for(auto it:mp){
            if(it.second>max_count){
                max_count=it.second;
            }
        }
        return max_count;
    }
};
