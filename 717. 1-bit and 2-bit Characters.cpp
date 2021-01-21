class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0,n=bits.size();
        for(i=0;i<n-1;){
            if(bits[i]==0){
                i++;
            }
            else{
                i+=2;
            }
        }
        return (i==n-1);
    }
};
