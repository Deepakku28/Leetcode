struct myComp {
    bool operator() (const pair<int,string> &a, const pair<int,string> &b){
        if(a.first!=b.first) {
            return (a.first>b.first);
        }
        else{
            return (a.second<b.second);
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words){
            mp[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComp> pq;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            pair<int,string> it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
