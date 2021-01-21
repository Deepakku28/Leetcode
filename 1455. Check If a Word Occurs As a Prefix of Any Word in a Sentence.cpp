class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<pair<string,int>> mp;
        int i=0;
        int n=sentence.size();
        int j=1;
        int k=0;
        while(k<n){
            if(k==n-1){
                mp.push_back(make_pair(sentence.substr(i+1),j));
                break;
            }
            else if(sentence[k]==' ' && i==0){
                mp.push_back(make_pair(sentence.substr(i,k-i),j));
                j++;
                i=k;
            }
            else if(sentence[k]==' '){
                mp.push_back(make_pair(sentence.substr(i+1,k-i),j));
                j++;
                i=k;
            }
            k++;
        }
        for(auto it:mp){
            if(searchWord==it.first.substr(0,searchWord.size())){
                return it.second;
            }
        }
        return -1;
    }
};
