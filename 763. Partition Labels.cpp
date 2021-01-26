class Solution {
public:
    vector<int> partitionLabels(string str) {
        vector<int> ans;
        vector<int> mp(26,-1);
        int n=str.size();
        for(int i=0;i<n;i++){
            mp[str[i]-'a']=i;
        }
        int index=-1;
        int last=0;
        for(int i=0;i<n;i++){
            index=max(index,mp[str[i]-'a']);
            if(index==i){
                ans.push_back(i-last+1);
                last=i+1;
            }
        }
        return ans;
    }
};
