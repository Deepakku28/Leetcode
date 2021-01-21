class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str=a;
        int minRepeat=1;
        while(str.size()<b.size()){
            str+=a;
            minRepeat++;
        }
        int pos=str.find(b);
        if(pos>=0){
            return minRepeat;
        }
        str+=a;
        minRepeat++;
        pos=str.find(b);
        if(pos>=0){
            return minRepeat;
        }
        return -1;
    }
};
