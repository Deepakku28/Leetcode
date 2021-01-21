class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n=A.size();
        if(n<2){
            return A;
        }
        sort(A.begin(),A.end());
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(B[i],i));
        }
        sort(temp.begin(),temp.end());
        vector<int> ans(n);
        int start=0;
        int end=n-1;
        for(int i=n-1;i>=0;i--){
            if(A[end]<=temp[i].first){
                ans[temp[i].second]=A[start];
                start++;
            }
            else{
                ans[temp[i].second]=A[end];
                end--;
            }
            
        }
        return ans;
    }
};
