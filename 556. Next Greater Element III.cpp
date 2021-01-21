class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10){
            return -1;
        }
        string str=to_string(n);
        int len=str.length();
        int index=-1;
        for(int i=len-1;i>=1;i--){
            if((str[i-1]-'0')<(str[i]-'0')){
                index=i-1;
                break;
            }
        }
        if(index==-1){
            return -1;
        }
        for(int i=len-1;i>index;i--){
            if(str[i]>str[index]){
                swap(str[i],str[index]);
                break;
            }
        }
        reverse(str.begin()+index+1,str.end());
        long long int ans=stol(str);
        return ans>INT_MAX?-1:ans;
    }
};
