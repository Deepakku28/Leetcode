class Solution {
public:
    bool check(vector<int> &mp){
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();
        if(len1>len2){
            return false;
        }
        vector<int> mp(26,0);
        for(int i=0;i<len1;i++){
            mp[s1[i]-'a']++;
            mp[s2[i]-'a']--;
        }
        if(check(mp)==true){
            return true;
        }
        for(int i=len1;i<len2;i++){
            mp[s2[i]-'a']--;
            mp[s2[i-len1]-'a']++;
            if(check(mp)==true){
                return true;
            }
        }
        return false;
    }
};
