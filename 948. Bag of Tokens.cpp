class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()<=0){
            return 0;
        }
        sort(tokens.begin(),tokens.end());
        if(tokens[0]>power){
            return 0;
        }
        int start=0;
        int end=tokens.size()-1;
        int currScore=0;
        int maxScore=0;
        while(start<=end){
            if(tokens[start]<=power){
                power-=tokens[start];
                currScore++;
                start++;
            }
            else if(power>=0){
                power+=tokens[end];
                currScore--;
                end--;
            }
            maxScore=max(maxScore,currScore);
        }
        return maxScore;
    }
};
