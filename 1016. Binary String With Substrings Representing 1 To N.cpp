class Solution {
public:
    bool queryString(string str, int n) {
        reverse(str.begin(),str.end());
        for(int i=1;i<=n;i++){
            bool flag=false;
            string temp="";
            int val=i;
            while(val){
                if(val&1){
                    temp+='1';
                }
                else{
                    temp+='0';
                }
                val=val/2;
            }
            int len=temp.size();
            for(int j=0;j<str.size();j++){
                if(str.substr(j,len)==temp){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                return false;
            }
        }
        return true;
    }
};
