class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start=0;
        int end=A.size()-1;
        while(start<end){ 
            int mid=(end + start)/2;
            if(A[mid-1]<A[mid] && A[mid]>A[mid+1]){
                return mid;
            }
            else if(A[mid-1]>A[mid]){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
};
