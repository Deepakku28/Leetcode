class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        for(int i=1;i<n;i++){
            A[i]+=A[i-1];
        }
        unordered_map<int,int> mp;
        mp[0]++;
        int count=0;
        for(int i=0;i<n;i++){
            int temp=A[i]%K;
            if(temp<0){
                temp+=K;
            }
            count+=mp[temp];
            mp[temp]++;
        }
        return count;
    }
};
