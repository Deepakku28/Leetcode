class Solution {
public:
    bool dfs(vector<int> &nums,vector<bool> &visited,int index,int &n,long long int &sum,int count,long long int currSum){
        if(count==0){
            return true;
        }
        if(currSum==sum){
            return dfs(nums,visited,0,n,sum,count-1,0);
        }
        for(int i=index;i<n;i++){
            if(currSum+nums[i]>sum){
                continue;
            }
            if(visited[i]==false){
                visited[i]=true;
                if(dfs(nums,visited,i+1,n,sum,count,currSum+nums[i])==true){
                    return true;
                }
                visited[i]=false;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        int n=nums.size();
        if(n<4){
            return false;
        }
        long long int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0){
            return false;
        }
        sum/=4;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<bool> visited(n,false);
        return dfs(nums,visited,0,n,sum,4,0);
    }
};
