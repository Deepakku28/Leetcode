class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[A[i]+B[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=0-C[i]-D[j];
                if(mp.find(sum)!=mp.end()){
                    ans+=mp[sum];
                }
            }
        }
        return ans;
    }
};
