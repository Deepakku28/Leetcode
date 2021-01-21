class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n=A.size();
        int totalSum=0;
        for(auto it:A){
            totalSum+=it;
        }
        if(totalSum%3!=0){
            return false;
        }
        int target=totalSum/3;
        int multiple=1;
        int currentSum=0;
        int count = 0;
        for(auto ele:A){
            currentSum+=ele;
            if(currentSum==(multiple*target)) {
                count++;
                multiple++;
            }
        }
        return count>=3;
    }
};
