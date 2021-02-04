class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal=-1;
        int n=arr.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(i!=n-1){
                maxVal=max(maxVal,arr[i+1]);
            }
            ans[i]=maxVal;
        }
        return ans;
    }
};
