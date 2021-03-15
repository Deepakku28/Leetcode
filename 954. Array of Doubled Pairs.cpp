class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](const int &a,const int &b){
            return abs(a)<abs(b);
        });
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==0){
                continue;
            }
            if(mp[2*arr[i]]==0){
                return false;
            }
            mp[arr[i]]--;
            mp[2*arr[i]]--;
        }
        return true;
    }
};
