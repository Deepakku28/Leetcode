class Solution {
public:
    int minFrequency(string &str){
        sort(str.begin(),str.end());
        int i=0;
        int count=1;
        while(str[i]==str[i+1] && i+1<str.size()){
            count++;
            i++;
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> query;
        for(int i=0;i<queries.size();i++){
            query.push_back(minFrequency(queries[i]));
        }
        vector<int> word;
        for(int i=0;i<words.size();i++){
            word.push_back(minFrequency(words[i]));
        }
        vector<int> ans;
        for(int i=0;i<query.size();i++){
            int count=0;
            for(int j=0;j<word.size();j++){
                if(query[i]<word[j]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
