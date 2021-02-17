class Solution {
public:
    int arrangeCoins(int n) {
        int start=1;
        int end=n;
        while(start<=end){
            long long int mid=start+(end-start)/2;
            long long int sum=(mid*(mid+1))/2;
            if(sum==n){
                return mid;
            }
            else if(sum>n){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return end;
    }
};
