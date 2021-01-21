class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int ans=0;
        int n=A.size();
        for(int i=0;i<n;i++){
            if(s.empty() || A[s.top()]>A[i]){
                s.push(i);
            }
        }
        
        for(int i=n-1;i>0;i--){
            while(!s.empty() && A[s.top()]<=A[i]){
                ans=max(ans,i-s.top());
                s.pop();
            }
        }
        return ans;
    }
};
