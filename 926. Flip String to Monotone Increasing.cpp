class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n=S.size();
        vector<int> dpLeftToRight(n+1,0);
        vector<int> dpRightToLeft(n+1,0);
        for(int i=1;i<=n;i++){
            dpLeftToRight[i]+=dpLeftToRight[i-1]+(S[i-1]=='0'?0:1);
        }
        for(int i=n-1;i>=0;i--){
            dpRightToLeft[i]+=dpRightToLeft[i+1]+(S[i]=='1'?0:1);
        }
        int ans=n;
        for(int i=0;i<=n;i++){
            ans=min(ans,dpLeftToRight[i]+dpRightToLeft[i]);
        }
        return ans;
    }
};
