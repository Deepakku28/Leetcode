class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            nums2.push_back(nums1[i]);
        }
        sort(nums2.begin(),nums2.end());
        double ans=0;
        int s=nums2.size();
        int j=s/2;
        if(s%2==1){
            ans=nums2[j];
        }
        else{
            ans=(nums2[j] +nums2[j-1])/2.0;
        }
        return ans;
    }
};
