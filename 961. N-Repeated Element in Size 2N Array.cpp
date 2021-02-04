class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        vector<int> mp(10001,0);
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
        }
        int maxVal=0;
        int ans=0;
        for(int i=0;i<mp.size();i++){
            if(mp[i]>maxVal){
                maxVal=mp[i];
                ans=i;
            }
        }
        return ans;
    }
};
