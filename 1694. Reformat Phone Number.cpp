class Solution {
public:
    string reformatNumber(string number) {
        string str="";
        for(int i=0;i<number.size();i++){
            if(isdigit(number[i])){
                str+=number[i];
            }
        }
        if(str.size()<=3){
            return str;
        }
        string ans="";
        int n=str.size();
        for(int i=0;i<n;){
            if(i+4==n){
                ans+=str.substr(i,2);
                i+=2;
                ans+='-';
                ans+=str.substr(i,2);
                i+=2;
            }
            else if(i+3<n && i+3!=n-1){
                ans+=str.substr(i,3);
                i+=3;
                ans+='-';
            }
            else{
                ans+=str.substr(i);
                i=n;
            }
        }
        return ans;
    }
};
