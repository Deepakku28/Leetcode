class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            int currMax=0;
            while(visited[i]!=true){
                visited[i]=true;
                currMax++;
                i=nums[i];
            }
            ans=max(ans,currMax);
        }
        return ans;
    }
};
