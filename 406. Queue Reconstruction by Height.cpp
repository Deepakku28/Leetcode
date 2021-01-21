class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end());
        vector<vector<int>> ans(n,vector<int>(2,INT_MAX));
        for(int i=0;i<n;i++){
            int count=0;
            int j=0;
            for(j=0;j<n;j++){
                if(ans[j][0]==INT_MAX || people[i][0]==ans[j][0])
                    count++;
                if(count==people[i][1]+1)
                    break;
            }
            ans[j][0]=people[i][0];
            ans[j][1]=people[i][1];
        }
        return ans;
    }
};
