class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(int i=0;i<words.size();i++){
            string str="";
            for(int j=0;j<words[i].size();j++){
                str=str+morse[words[i][j]-'a'];
            }
            s.insert(str);
        }
        return (int)s.size();
    }
};
