class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n=A.size();
        int maxStart=A[0];
        int ans=A[0];
        for(int i=1;i<n;i++){
            maxStart=max(maxStart,A[i-1]+(i-1));
            ans=max(ans,maxStart+A[i]-i);
        }
        return ans;
    }
};
