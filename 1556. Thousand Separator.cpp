class Solution {
public:
    string thousandSeparator(int n) {
        string str=to_string(n);
        int len=str.length();
        if(len<=3){
            return str;
        }
        string s="";
        int k=0;
        for(int i=len-1;i>=0;i--){
            s=s+str[i];
            k++;
            if(k==3 && i!=0){
                s=s+".";
                k=0;
            }
        }
        int start=0;
        int end=s.length()-1;
        reverse(s.begin(),s.end());
        //cout<<s<<endl;
        return s;
    }
};
