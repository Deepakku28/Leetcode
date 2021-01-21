class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()<2){
            return 0;
        }
        
        int max_len=0;
        int len=words.size();
        for(int i=0;i<len-1;i++){
            set<char> s;
            for(int j=0;j<words[i].length();j++){
                s.insert(words[i][j]);
            }
            for(int j=i+1;j<len;j++){
                int flag=1;
                for(int k=0;k<words[j].length();k++){
                    if(s.find(words[j][k])!=s.end()){
                        flag=0;
                        break;
                    }
                }
                if(flag==1 && (words[i].length()*words[j].length())>max_len){
                    max_len = (words[i].length()*words[j].length());
                }
            }
        }
        return max_len;
    }
};
