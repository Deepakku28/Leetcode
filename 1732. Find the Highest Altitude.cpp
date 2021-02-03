class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0;
        int maxVal=0;
        int n=gain.size();
        for(int i=0;i<n;i++){
            curr+=gain[i];
            maxVal=max(maxVal,curr);
        }
        return maxVal;
    }
};
