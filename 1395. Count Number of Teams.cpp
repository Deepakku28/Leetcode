class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++){
            int leftSmaller=0;
            int leftBigger=0;
            int rightSmaller=0;
            int rightBigger=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    leftSmaller++;
                }
                if(rating[j]>rating[i]){
                    leftBigger++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    rightBigger++;
                }
                if(rating[j]>rating[i]){
                    rightSmaller++;
                }
            }
            ans+=(leftBigger*rightBigger)+(leftSmaller*rightSmaller);
        }
        return ans;
    }
};
