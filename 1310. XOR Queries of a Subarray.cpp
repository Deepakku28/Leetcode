class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v(arr.size(),0);
        v[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            v[i]=(arr[i]^v[i-1]);
        }
        vector<int> result;
        for(auto it:queries){
            if(it[0]==0){
                result.push_back(v[it[1]]);
            }
            else{
                result.push_back(v[it[0]-1]^v[it[1]]);
            }
        }
        return result;
    }
};
