class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;){
            int count=0;
            int j=i;
            while(s[j]==s[i] && j<n){
                count++;
                j++;
            }
            i=j;
            ans=max(ans,count);
        }
        return ans;
    }
};
