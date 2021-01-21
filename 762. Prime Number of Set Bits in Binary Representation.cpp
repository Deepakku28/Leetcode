class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        set<int> s={2,3,5,7,11,13,17,19};
        int ans=0;
        for(int i=L;i<=R;i++){
            if(s.find(__builtin_popcount(i))!=s.end()){
                ans++;
            }
        }
        return ans;
    }
};
