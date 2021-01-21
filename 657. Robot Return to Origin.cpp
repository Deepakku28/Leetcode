class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int up=0;
        int down=0;
        int right=0;
        int left=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                up++;
            }
            else if(moves[i]=='D'){
                down++;
            }
            else if(moves[i]=='R'){
                right++;
            }
            else{
                left++;
            }
        }
        return (up==down && right==left);
    }
};
