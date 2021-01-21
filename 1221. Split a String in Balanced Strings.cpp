class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        int ans=0;
        int left=0;
        int right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                left++;
            }
            else if(s[i]=='R'){
                right++;
            }
            if(left==right){
                ans++;
                left=0;
                right=0;
            }
        }
        return ans;
    }
};
