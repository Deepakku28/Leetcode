class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({position[i],speed[i]});
        }
        sort(sorted.begin(),sorted.end());
        stack<double> s;
        for(int i=0;i<n;i++){
            double arrivalTime=(((double)target-(double)sorted[i].first)/(double)sorted[i].second);
            while(!s.empty() && arrivalTime>=s.top()){
                s.pop();
            }
            s.push(arrivalTime);
        }
        return s.size();
    }
};
