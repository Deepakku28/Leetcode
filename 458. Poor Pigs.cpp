class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n=(minutesToTest/minutesToDie)+1;
        int ans=0;
        int m=1;
        while(m<buckets){
            m*=n;
            ans++;
        }
        return ans;
    }
};
