class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start=0;
        int end=people.size()-1;
        int ans=0;
        sort(people.begin(),people.end());
        while(start<=end){
            if(start==end){
                ans++;
                break;
            }
            if(people[start]+people[end]>limit){
                ans++;
                end--;
            }
            else{
                ans++;
                end--;
                start++;
            }
        }
        return ans;
    }
};
