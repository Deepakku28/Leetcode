class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n=ages.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[ages[i]]++;
        }
        int ans=0;
        for(auto a:mp){
            for(auto b:mp){
                if(!(b.first<=0.5*a.first+7 || b.first>a.first || (b.first>100 && a.first<100))){
                    if(a.first==b.first){
                        ans+=(a.second*(b.second-1));
                    }
                    else{
                        ans+=a.second*b.second;
                    }
                }
            }
        }
        return ans;
    }
};
