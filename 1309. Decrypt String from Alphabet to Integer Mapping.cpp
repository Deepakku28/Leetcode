class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;){
            if(i+2<n && s[i+2]=='#'){
                string index=s.substr(i,2);
                int val=stoi(index);
                char ch=('a'+(val-1));
                str=str+ch;
                i=i+3;
            }
            else{
                string index=s.substr(i,1);;
                int val=stoi(index);
                char ch=('a'+(val-1));
                str=str+ch;
                i++;
            }
        }
        return str;
    }
};
