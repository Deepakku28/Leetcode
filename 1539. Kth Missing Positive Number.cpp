class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int val=1;
        int count=0;
        int i=0;
        while(i<n){
            if(arr[i]!=val){
                count++;
                if(count==k){
                    return val;
                }
                val++;
            }
            else{
                i++;
                val++;
            }
        }
        return n+k;
    }
};
