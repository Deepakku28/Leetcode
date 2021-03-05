class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int hr=0;hr<12;hr++){
            for(int min=0;min<60;min++){
                if(__builtin_popcount(hr)+__builtin_popcount(min)==num){
                    string str=to_string(hr)+(min<10?":0":":")+to_string(min);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};
