class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size();
        int n=B.size();
        vector<vector<int>> ans;
        int start1=0;
        int start2=0;
        while(start1<m && start2<n){
            if(A[start1][1]>B[start2][1]){
                if(A[start1][0]<=B[start2][1]){
                    ans.push_back({max(A[start1][0],B[start2][0]),B[start2][1]});
                }
                start2++;
            }
            else if(A[start1][1]<B[start2][1]){
                if(A[start1][1]>=B[start2][0]){
                    ans.push_back({max(A[start1][0],B[start2][0]),A[start1][1]});
                }
                start1++;
            }
            else{
                ans.push_back({max(A[start1][0],B[start2][0]),A[start1][1]});
                start1++;
                start2++;
            }
        }
        return ans;
    }
};
