class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int len=flowerbed.size();
        for(int i=0;i<len;i++){
            if(flowerbed[i]==0){
                int next=(i==len-1)?0:flowerbed[i+1]; 
                int prev=(i==0)?0:flowerbed[i-1];
                if(next==0 && prev==0) {
                   flowerbed[i]=1;
                   count++;
               }
            }
        }
        return count>=n;
    }
};
