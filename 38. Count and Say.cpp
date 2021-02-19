class Solution {
public:
    string countAndSay(int n) {
        string str=to_string(1);
        n--;
        while(n--){
            string curr="";
            for(int i=0;i<str.size();i++){
                int count=1;
                while(i+1<str.size() && str[i]==str[i+1]){
                    count++;
                    i++;
                }
                curr+=to_string(count)+str[i];
            }
            str=curr;
        }
        return str;
    }
};
