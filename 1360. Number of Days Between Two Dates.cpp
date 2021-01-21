class Solution {
public:
    bool isLeapYear(int y){
        return (y%4==0 && (y%400==0 || y%100!=0));
    }
    
    int helper(string date,vector<int> &days){
        int y=stoi(date.substr(0,4));
        int m=stoi(date.substr(5,2));
        int d=stoi(date.substr(8));
        for(int i=1971;i<y;i++){
            d+=isLeapYear(i)==true?366:365;
        }
        return d+(m>2 && isLeapYear(y))+accumulate(begin(days),begin(days)+m-1,0);
    }
    
    int daysBetweenDates(string date1, string date2) {
        vector<int> days{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return abs(helper(date1,days)-helper(date2,days));
    }
};
