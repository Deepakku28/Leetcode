class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        if(D==weights.size()){
            return left;
        }
        
        while(left<right){
            int mid=left+(right-left)/2;
            int currDays=1;
            int shipCapacity=0;
            for(auto it:weights){
                if(shipCapacity+it>mid){
                    currDays++;
                    shipCapacity=0;
                }
                shipCapacity+=it;
            }
            if(currDays>D){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
};
