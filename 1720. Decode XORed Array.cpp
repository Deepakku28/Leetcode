class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int> ans;
        ans.push_back(first);
        for(int i=0;i<n;i++){
            ans.push_back(first^encoded[i]);
            first=ans.back();
        }
        return ans;
    }
};
