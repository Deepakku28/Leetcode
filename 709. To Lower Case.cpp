class Solution {
public:
    string toLowerCase(string str) {
        for(auto& it:str){
            if(it>='A' && it<='Z'){
                it=(it+32);
            }
        }
        return str;
    }
};
