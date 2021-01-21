class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> mp(n,false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            mp[curr]=true;
            if(arr[curr]==0){
                return true;
            }
            if(curr-arr[curr]<n && curr-arr[curr]>=0 && mp[curr-arr[curr]]==false){
                q.push(curr-arr[curr]);
            }
            if(curr+arr[curr]<n && curr+arr[curr]>=0 && mp[curr+arr[curr]]==false){
                q.push(curr+arr[curr]);
            }
        }
        return false;
    }
};
