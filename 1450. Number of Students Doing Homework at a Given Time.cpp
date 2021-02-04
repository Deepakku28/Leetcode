class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n=startTime.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(startTime[i]<=queryTime && endTime[i]>=queryTime)?1:0;
        }
        return ans;
    }
};
