class Solution {
public:
    int addDigits(int num) {
        string str=to_string(num);
        while(str.size()>1){
            int sum=0;
            for(int i=0;i<str.size();i++){
                sum=sum+(str[i]-'0');
            }
            str=to_string(sum);
        }
        return stoi(str);
    }
};
