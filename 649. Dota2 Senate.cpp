class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=0;
        int count=0;
        while(senate.size()!=n){
            n=senate.size();
            string temp="";
            for(int i=0;i<n;i++){
                if(senate[i]=='R'){
                    if(count>=0){
                        temp+='R';
                    }
                    count++;
                }
                else{
                    if(count<=0){
                        temp+='D';
                    }
                    count--;
                }
            }
            senate=temp;
        }
        if(senate[0]=='R'){
            return "Radiant";
        }
        return "Dire";
    }
};
