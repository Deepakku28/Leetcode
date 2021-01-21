class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1=magazine.size();
        int len2=ransomNote.size();
        vector<int> mp(26,0);
        for(int i=0;i<len1;i++){
            mp[magazine[i]-'a']++;
        }
        for(int i=0;i<len2;i++){
            mp[ransomNote[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp[i]<0){
                return false;
            }
        }
        return true;
    }
};
