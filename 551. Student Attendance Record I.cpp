class Solution {
public:
    bool checkRecord(string s) {
        if((s.find("LLL")!=string::npos) || (count(s.begin(),s.end(),'A')>1)){
            return false;
        }
        return true;
    }
};
