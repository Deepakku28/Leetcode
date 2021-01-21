class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        reverse(digits.begin(),digits.end());
        int carry=1;
        int i=0;
        for(i=0;i<n;i++){
            digits[i]+=carry;
            carry=0;
            if(digits[i]>9){
                digits[i]=digits[i]%10;
                carry=1;
            }
        }
        if(i==n && carry==1){
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
