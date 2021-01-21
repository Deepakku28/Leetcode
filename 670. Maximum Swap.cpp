class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.size();
        string ans=str;
        for(int i=0;i<n-1;i++){ 
            for(int j=i+1;j<n;j++){
                string temp=str;
                char ch=temp[i];
                temp[i]=temp[j];
                temp[j]=ch;
                ans=max(ans,temp);
            }
        }
        return stoi(ans);
    }
};
