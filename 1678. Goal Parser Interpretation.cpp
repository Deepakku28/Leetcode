class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string ans="";
        for(int i=0;i<n;){
            if(i+1<n && command[i]=='(' && command[i+1]==')'){
                ans=ans+"o";
                i+=2;
            }
            else if(command.substr(i,4)=="(al)"){
                ans=ans+"al";
                i+=4;
            }
            else{
                ans=ans+command[i];
                i++;
            }
        }
        return ans;
    }
};
