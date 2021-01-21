class Solution {
public:
    string sortString(string s) {
        int n=s.size();
        vector<int> mp(26,0);
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        string str="";
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(mp[j]>0){
                    str+=(j+'a');
                    mp[j]--;
                }
            }
            for(int j=25;j>=0;j--){
                if(mp[j]>0){
                    str+=(j+'a');
                    mp[j]--;
                }
            }
        }
        return str;
    }
};
