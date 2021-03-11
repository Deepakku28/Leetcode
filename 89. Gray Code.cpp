class Solution {
public:
    int convert(string str){
        int ans=0;
        int n=str.size()-1;
        for(int i=n;i>=0;i--){
            if(str[i]=='1'){
                ans+=(1<<(n-i));
            }
        }
        return ans;
    }
    
    vector<int> grayCode(int n) {
        vector<string> val;
        val.push_back("0");
        val.push_back("1");
        for(int i=2;i<(1<<n);i=i<<1){
            for(int j=i-1;j>=0;j--){
                val.push_back(val[j]);
            }
            for(int j=0;j<i;j++){
                val[j]="0"+val[j];
            }
            for(int j=i;j<2*i;j++){
                val[j]="1"+val[j];
            }
        }
        vector<int> ans;
        for(auto it:val){
            cout<<it<<" ";
        }
        for(int i=0;i<val.size();i++){
            ans.push_back(convert(val[i]));
        }
        return ans;
    }
};
