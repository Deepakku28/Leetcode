class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int n=seq.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                count++;
            }
            ans.push_back(count%2);
            if(seq[i]==')'){
                count--;
            }
        }
        return ans;
    }
};
