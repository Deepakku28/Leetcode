class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                int temp=nums1[k];
                nums1[k]=nums1[i];
                nums1[i]=temp;
                i--;
                k--;
            }
            else{
                int temp=nums1[k];
                nums1[k]=nums2[j];
                nums2[j]=temp;
                j--;
                k--;
            }
        }
        while(j>=0){
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
};
