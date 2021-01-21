class Solution {
public:
    string generateTheString(int n) {
        string str="";
        for(int i=0;i<n-1;i++){
            str+='a';
        }
        if(n%2==1){
            str+='a';
        }
        else{
            str+='b';
        }
        return str;
    }
};
