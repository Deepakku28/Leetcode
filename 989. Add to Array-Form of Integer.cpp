class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int len1=A.size()-1;
        int carry=0;
        while(carry>0 || len1>=0 || K>0){
            if(len1>=0){
                carry+=A[len1];
                len1--;
            }
            if(K>0){
                carry+=(K%10);
                K=K/10;
            }
            ans.push_back(carry%10);
            carry=carry/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
