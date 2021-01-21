class Solution {
public:
    int romanToInt(string s) {
        if(s=="" || s.length()==0){
            return 0;
        }
        
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        int len=s.length();
        int result=mp[s[len-1]];
        
        for(int i=len-2;i>=0;i--){
            if(mp[s[i]]>=mp[s[i+1]]){
                result=result+mp[s[i]];
            }
            else{
                result=result-mp[s[i]];
            }
        }
        return result;
    }
};
