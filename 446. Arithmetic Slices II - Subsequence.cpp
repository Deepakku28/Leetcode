class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        long n=A.size();
        if(n<3){
            return 0;
        }
        long result=0;
        unordered_map<long,long> mp[n];
        for(long i=1;i<n;i++){
            for(long j=0;j<i;j++){
                long diff=(long)A[i]-A[j];
                if(diff<INT_MIN || diff>INT_MAX){
                    continue;
                }
                auto it=mp[j].find(diff);
                long count=(it==mp[j].end()?0:it->second);
                mp[i][diff]+=count+1;
                result+=count;
            }
        }
        return result;
    }
};
