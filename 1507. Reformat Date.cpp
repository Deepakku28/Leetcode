class Solution {
public:
    string reformatDate(string date) {
        vector<string> month = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        string d,m,y;
        if(date.size()==13){
            d=date.substr(0,2);
            m=date.substr(5,3);
            y=date.substr(9);
        }
        else{
            d="0"+date.substr(0,1);
            m=date.substr(4,3);
            y=date.substr(8);
        }
        int mon=0;
        for(int i=0;i<12;i++){
            if(month[i]==m){
                mon=i+1;
                break;
            }
        }
        m=(mon<10)?"0"+to_string(mon):to_string(mon);
        return y+"-"+m+"-"+d;
    }
};
