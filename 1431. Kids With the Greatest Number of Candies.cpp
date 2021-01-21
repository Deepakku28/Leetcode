class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_val=INT_MIN;
        for(int i=0;i<candies.size();i++){
            max_val=max(max_val,candies[i]);
        }
        vector<bool> result(candies.size());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=max_val){
                result[i]=true;
            }
            else{
                result[i]=false;
            }
        }
        return result;
    }
};
