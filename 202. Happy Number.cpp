class Solution {
public:
    bool helper(int n,unordered_map<int,bool> &mp){
        if(n==1){
            return true;
        }
        if(mp[n]==true){
            return false;
        }
        mp[n]=true;
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return helper(sum,mp);
    }
    
    bool isHappy(int n) {
        unordered_map<int,bool> mp;
        return helper(n,mp);
    }
};
