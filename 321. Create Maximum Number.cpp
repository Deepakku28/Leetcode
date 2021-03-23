class Solution {
public:
    vector<int> maxArray(vector<int> &nums,int k){
        int n=nums.size();
        int remove=n-k;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            while(temp.size()>0 && temp.back()<nums[i] && remove){
                temp.pop_back();
                remove--;
            }
            temp.push_back(nums[i]);
        }
        while(remove){
            remove--;
            temp.pop_back();
        }
        return temp;
    }
    
    vector<int> merge(vector<int> &arr1,vector<int> &arr2){
        vector<int> temp;
        int start1=0;
        int start2=0;
        while(start1<arr1.size() && start2<arr2.size()){
            if(arr1[start1]==arr2[start2]){
                int p1=start1+1;
                int p2=start2+1;
                while(p1<arr1.size() && p2<arr2.size() && arr1[p1]==arr2[p2]){
                    p1++;
                    p2++;
                }
                if(p1==arr1.size()){
                    temp.push_back(arr2[start2++]);
                }
                else if(p2==arr2.size()){
                    temp.push_back(arr1[start1++]);
                }
                else if(arr1[p1]>arr2[p2]){
                    temp.push_back(arr1[start1++]);
                }
                else{
                    temp.push_back(arr2[start2++]);
                }
            }
            else if(arr1[start1]>arr2[start2]){
                temp.push_back(arr1[start1++]);
            }
            else{
                temp.push_back(arr2[start2++]);
            }
        }
        while(start1<arr1.size()){
            temp.push_back(arr1[start1++]);
        }
        while(start2<arr2.size()){
            temp.push_back(arr2[start2++]);
        }
        assert(temp.size()==arr1.size()+arr2.size());
        return temp;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(k,0);
        for(int i=max(0,k-m);i<=min(n,k);i++){
            vector<int> arr1=maxArray(nums1,i);
            vector<int> arr2=maxArray(nums2,k-i);
            vector<int> temp=merge(arr1,arr2);
            if(temp>ans){
                ans=temp;
            }
        }
        return ans;
    }
};
