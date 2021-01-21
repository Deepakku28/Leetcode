class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> time;
        for(int i=0;i<n;i++){
            int hr=stoi(timePoints[i].substr(0,2));
            int min=stoi(timePoints[i].substr(3,2));
            time.push_back(hr*60+min);
        }
        sort(time.begin(),time.end());
        time.push_back(time[0]+1440);
        int minDiff=1440;
        for(int i=0;i<n;i++){
            int diff=time[i+1]-time[i];
            minDiff=min(minDiff,diff);
        }
        return minDiff;
    }
};
