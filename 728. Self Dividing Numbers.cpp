class Solution {
public:
    bool helper(int num){
        int original=num;
        while(num){
            int rem=num%10;
            if(rem==0 || original%rem!=0){
                return false;
            }
            num/=10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(i<10 || helper(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
