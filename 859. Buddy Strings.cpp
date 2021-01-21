class Solution {
public:
    bool buddyStrings(string A, string B) {
        int m=A.size();
        int n=B.size();
        if(m!=n){
            return false;
        }
        if(A==B){
            unordered_set<char> s(A.begin(),A.end());
            if(s.size()<m){
                return true;
            }
        }
        vector<int> diff;
        for(int i=0;i<m;i++){
            if(A[i]!=B[i]){
                diff.push_back(i);
            }
        }
        return (diff.size()==2 && A[diff[0]]==B[diff[1]] && A[diff[1]]==B[diff[0]]);
    }
};
