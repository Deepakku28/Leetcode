class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans=INT_MAX;
        unordered_set<int> st;
        unordered_set<int> cur;
        unordered_set<int> res;
        for(int a:arr){
            cur={a};
        
            for(auto r:st){
                cur.insert(a&r);
            }
            st=cur;
            for(auto r:st){
                res.insert(r);
            }
        }
        for(auto i:res){
            ans=min(ans,abs(i-target));
        }
        return ans;
    }
};
