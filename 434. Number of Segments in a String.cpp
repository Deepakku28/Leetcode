class Solution {
public:
    int countSegments(string s) {
        stringstream str(s);
        string word;
        int count=0;
        while(str>>word){
            count++;
        }
        return count;
    }
};
