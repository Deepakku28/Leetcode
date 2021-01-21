class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n=A.size();
        vector<int> maxFromLeft(n,0);
        maxFromLeft[0]=A[0];
        for(int i=1;i<n;i++){
            maxFromLeft[i]=max(maxFromLeft[i-1],A[i]);
        }
        
        vector<int> minFromRight(n,0);
        minFromRight[n-1]=A[n-1];
        for(int i=n-2;i>=0;i--){
            minFromRight[i]=min(minFromRight[i+1],A[i]);
        }
        
        for(int i=0;i<n;i++){
            if(maxFromLeft[i]<=minFromRight[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
