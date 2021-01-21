class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        for(int i=0;i<n;i=i+2*k){
            if(i+k<n){
                reverse(s.begin()+i,s.begin()+k+i);
            }
            else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};
